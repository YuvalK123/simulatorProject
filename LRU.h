//
// Created by yuval Kasner on 27/11/19.
// id - 312116569
//
//used help from code video https://www.youtube.com/watch?v=8-FZRAjR7qU
//and from page in recitation presentation.
//
#ifndef LRU_H_
#define LRU_H_

#include <iostream>
#include <list>
#include <unordered_map>
#include <fstream>
using namespace std;
template<class obj>
class CacheManager {
 private:
  int capacity;
  string className;
  unordered_map<const char *, pair<obj, list<const char *>::iterator>> cache;
  list<const char *> cacheKeys;
  void updateKey(typename unordered_map<const char *, pair<obj, list<const char *>::iterator>>::iterator &it);
  obj *GetObjectFromFile(const char *key);
  void WriteObjectToFile(const char *key, obj object);

 public:
  CacheManager(int c);
  void insert(const char *key, obj object);
  obj get(const char *key);
  void foreach(void (*p_function)(obj &));
  ~CacheManager() = default;
};

//
// Created by yuval Kasner on 27/11/19.
//


template<class obj>
void CacheManager<obj>::foreach(void (*p_function)(obj &)) {
  for (auto s :this->cacheKeys) {
    p_function(this->cache[s].first);
  }
}

template<class obj>
obj CacheManager<obj>::get(const char *key) {
  auto item = this->cache.find(key);
  if (item == this->cache.end()) {
    obj *tmp = (this->GetObjectFromFile(key));
    if (tmp != nullptr) {
      this->insert(key, *tmp);
      return *(this->GetObjectFromFile(key));
    }
    throw "an error";
  }
  updateKey(item);
  return item->second.first;
}

template<class obj>
void CacheManager<obj>::insert(const char *key, obj object) {
  auto item = this->cache.find(key);
  if (item != cache.end()) {
    this->updateKey(item);
    this->cache[key] = {object, this->cacheKeys.begin()};
    this->WriteObjectToFile(key, object);
    return;
  }
  if (this->cache.size() == (unsigned long) this->capacity) {
    this->cache.erase(this->cacheKeys.back());
    this->cacheKeys.pop_back();
  }
  this->WriteObjectToFile(key, object);
  this->cacheKeys.push_front(key);
  this->cache.insert({key, {object, this->cacheKeys.begin()}});
}
template<class obj>
void CacheManager<obj>::updateKey(typename unordered_map<const char *,
                                                         pair<obj, list<const char *>::iterator>>::iterator &it) {
  this->cacheKeys.erase(it->second.second);
  this->cacheKeys.push_front(it->first);
  it->second.second = this->cacheKeys.begin();
}

template<class obj>
CacheManager<obj>::CacheManager(int c) {
  this->capacity = c;
  this->className = obj::class_name;
}
template<class obj>
void CacheManager<obj>::WriteObjectToFile(const char *key, obj object) {
  fstream file{this->className + " " + key, ios::out | ios::binary};
  if (!file) {
    throw "failed to open file for write!";
  }
  file.write((const char *) &object, sizeof(obj));

}
template<class obj>
obj *CacheManager<obj>::GetObjectFromFile(const char *key) {
  fstream file{this->className + " " + key, ios::in | ios::binary};
  if (!file) {
    return nullptr;
  }
  obj tmp;
  file.read(const_cast<char *>((const char *) &tmp), sizeof(obj));
  obj *s = &tmp;
  return s;
}

#endif //LRU_H_
