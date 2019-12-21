cmake_minimum_required(VERSION 3.15)
project(simulatorProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS-pthread)

add_executable(simulatorProject server.cpp commands/Command.h commands/OpenServerCommand.cpp commands/ConnectCommand.cpp commands/DefineVarCommand.cpp commands/ConditionParser.h commands/IfCommand.cpp commands/LoopCommand.cpp commands/FuncCommand.cpp commands/ForLoop.cpp SymbolTable.cpp SymbolTable.h LRU.h)