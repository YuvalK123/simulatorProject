# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yuvalkasner/Documents/c++_projects/simulatorProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/simulatorProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simulatorProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simulatorProject.dir/flags.make

CMakeFiles/simulatorProject.dir/server.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/server.cpp.o: ../server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simulatorProject.dir/server.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/server.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/server.cpp

CMakeFiles/simulatorProject.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/server.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/server.cpp > CMakeFiles/simulatorProject.dir/server.cpp.i

CMakeFiles/simulatorProject.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/server.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/server.cpp -o CMakeFiles/simulatorProject.dir/server.cpp.s

CMakeFiles/simulatorProject.dir/commands/OpenServerCommand.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/commands/OpenServerCommand.cpp.o: ../commands/OpenServerCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/simulatorProject.dir/commands/OpenServerCommand.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/commands/OpenServerCommand.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/OpenServerCommand.cpp

CMakeFiles/simulatorProject.dir/commands/OpenServerCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/commands/OpenServerCommand.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/OpenServerCommand.cpp > CMakeFiles/simulatorProject.dir/commands/OpenServerCommand.cpp.i

CMakeFiles/simulatorProject.dir/commands/OpenServerCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/commands/OpenServerCommand.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/OpenServerCommand.cpp -o CMakeFiles/simulatorProject.dir/commands/OpenServerCommand.cpp.s

CMakeFiles/simulatorProject.dir/commands/ConnectCommand.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/commands/ConnectCommand.cpp.o: ../commands/ConnectCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/simulatorProject.dir/commands/ConnectCommand.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/commands/ConnectCommand.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/ConnectCommand.cpp

CMakeFiles/simulatorProject.dir/commands/ConnectCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/commands/ConnectCommand.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/ConnectCommand.cpp > CMakeFiles/simulatorProject.dir/commands/ConnectCommand.cpp.i

CMakeFiles/simulatorProject.dir/commands/ConnectCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/commands/ConnectCommand.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/ConnectCommand.cpp -o CMakeFiles/simulatorProject.dir/commands/ConnectCommand.cpp.s

CMakeFiles/simulatorProject.dir/commands/DefineVarCommand.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/commands/DefineVarCommand.cpp.o: ../commands/DefineVarCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/simulatorProject.dir/commands/DefineVarCommand.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/commands/DefineVarCommand.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/DefineVarCommand.cpp

CMakeFiles/simulatorProject.dir/commands/DefineVarCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/commands/DefineVarCommand.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/DefineVarCommand.cpp > CMakeFiles/simulatorProject.dir/commands/DefineVarCommand.cpp.i

CMakeFiles/simulatorProject.dir/commands/DefineVarCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/commands/DefineVarCommand.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/DefineVarCommand.cpp -o CMakeFiles/simulatorProject.dir/commands/DefineVarCommand.cpp.s

CMakeFiles/simulatorProject.dir/commands/IfCommand.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/commands/IfCommand.cpp.o: ../commands/IfCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/simulatorProject.dir/commands/IfCommand.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/commands/IfCommand.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/IfCommand.cpp

CMakeFiles/simulatorProject.dir/commands/IfCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/commands/IfCommand.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/IfCommand.cpp > CMakeFiles/simulatorProject.dir/commands/IfCommand.cpp.i

CMakeFiles/simulatorProject.dir/commands/IfCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/commands/IfCommand.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/IfCommand.cpp -o CMakeFiles/simulatorProject.dir/commands/IfCommand.cpp.s

CMakeFiles/simulatorProject.dir/commands/LoopCommand.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/commands/LoopCommand.cpp.o: ../commands/LoopCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/simulatorProject.dir/commands/LoopCommand.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/commands/LoopCommand.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/LoopCommand.cpp

CMakeFiles/simulatorProject.dir/commands/LoopCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/commands/LoopCommand.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/LoopCommand.cpp > CMakeFiles/simulatorProject.dir/commands/LoopCommand.cpp.i

CMakeFiles/simulatorProject.dir/commands/LoopCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/commands/LoopCommand.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/LoopCommand.cpp -o CMakeFiles/simulatorProject.dir/commands/LoopCommand.cpp.s

CMakeFiles/simulatorProject.dir/commands/FuncCommand.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/commands/FuncCommand.cpp.o: ../commands/FuncCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/simulatorProject.dir/commands/FuncCommand.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/commands/FuncCommand.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/FuncCommand.cpp

CMakeFiles/simulatorProject.dir/commands/FuncCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/commands/FuncCommand.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/FuncCommand.cpp > CMakeFiles/simulatorProject.dir/commands/FuncCommand.cpp.i

CMakeFiles/simulatorProject.dir/commands/FuncCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/commands/FuncCommand.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/FuncCommand.cpp -o CMakeFiles/simulatorProject.dir/commands/FuncCommand.cpp.s

CMakeFiles/simulatorProject.dir/commands/ForLoop.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/commands/ForLoop.cpp.o: ../commands/ForLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/simulatorProject.dir/commands/ForLoop.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/commands/ForLoop.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/ForLoop.cpp

CMakeFiles/simulatorProject.dir/commands/ForLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/commands/ForLoop.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/ForLoop.cpp > CMakeFiles/simulatorProject.dir/commands/ForLoop.cpp.i

CMakeFiles/simulatorProject.dir/commands/ForLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/commands/ForLoop.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/ForLoop.cpp -o CMakeFiles/simulatorProject.dir/commands/ForLoop.cpp.s

CMakeFiles/simulatorProject.dir/SymbolTable.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/SymbolTable.cpp.o: ../SymbolTable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/simulatorProject.dir/SymbolTable.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/SymbolTable.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/SymbolTable.cpp

CMakeFiles/simulatorProject.dir/SymbolTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/SymbolTable.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/SymbolTable.cpp > CMakeFiles/simulatorProject.dir/SymbolTable.cpp.i

CMakeFiles/simulatorProject.dir/SymbolTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/SymbolTable.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/SymbolTable.cpp -o CMakeFiles/simulatorProject.dir/SymbolTable.cpp.s

CMakeFiles/simulatorProject.dir/commands/ConditionalParser.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/commands/ConditionalParser.cpp.o: ../commands/ConditionalParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/simulatorProject.dir/commands/ConditionalParser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/commands/ConditionalParser.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/ConditionalParser.cpp

CMakeFiles/simulatorProject.dir/commands/ConditionalParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/commands/ConditionalParser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/ConditionalParser.cpp > CMakeFiles/simulatorProject.dir/commands/ConditionalParser.cpp.i

CMakeFiles/simulatorProject.dir/commands/ConditionalParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/commands/ConditionalParser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/ConditionalParser.cpp -o CMakeFiles/simulatorProject.dir/commands/ConditionalParser.cpp.s

CMakeFiles/simulatorProject.dir/commands/Print.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/commands/Print.cpp.o: ../commands/Print.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/simulatorProject.dir/commands/Print.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/commands/Print.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/Print.cpp

CMakeFiles/simulatorProject.dir/commands/Print.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/commands/Print.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/Print.cpp > CMakeFiles/simulatorProject.dir/commands/Print.cpp.i

CMakeFiles/simulatorProject.dir/commands/Print.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/commands/Print.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/Print.cpp -o CMakeFiles/simulatorProject.dir/commands/Print.cpp.s

CMakeFiles/simulatorProject.dir/commands/Sleep.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/commands/Sleep.cpp.o: ../commands/Sleep.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/simulatorProject.dir/commands/Sleep.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/commands/Sleep.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/Sleep.cpp

CMakeFiles/simulatorProject.dir/commands/Sleep.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/commands/Sleep.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/Sleep.cpp > CMakeFiles/simulatorProject.dir/commands/Sleep.cpp.i

CMakeFiles/simulatorProject.dir/commands/Sleep.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/commands/Sleep.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/commands/Sleep.cpp -o CMakeFiles/simulatorProject.dir/commands/Sleep.cpp.s

CMakeFiles/simulatorProject.dir/client.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/client.cpp.o: ../client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/simulatorProject.dir/client.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/client.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/client.cpp

CMakeFiles/simulatorProject.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/client.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/client.cpp > CMakeFiles/simulatorProject.dir/client.cpp.i

CMakeFiles/simulatorProject.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/client.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/client.cpp -o CMakeFiles/simulatorProject.dir/client.cpp.s

CMakeFiles/simulatorProject.dir/Observer.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/Observer.cpp.o: ../Observer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/simulatorProject.dir/Observer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/Observer.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/Observer.cpp

CMakeFiles/simulatorProject.dir/Observer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/Observer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/Observer.cpp > CMakeFiles/simulatorProject.dir/Observer.cpp.i

CMakeFiles/simulatorProject.dir/Observer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/Observer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/Observer.cpp -o CMakeFiles/simulatorProject.dir/Observer.cpp.s

CMakeFiles/simulatorProject.dir/SimManager.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/SimManager.cpp.o: ../SimManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/simulatorProject.dir/SimManager.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/SimManager.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/SimManager.cpp

CMakeFiles/simulatorProject.dir/SimManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/SimManager.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/SimManager.cpp > CMakeFiles/simulatorProject.dir/SimManager.cpp.i

CMakeFiles/simulatorProject.dir/SimManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/SimManager.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/SimManager.cpp -o CMakeFiles/simulatorProject.dir/SimManager.cpp.s

CMakeFiles/simulatorProject.dir/main.cpp.o: CMakeFiles/simulatorProject.dir/flags.make
CMakeFiles/simulatorProject.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/simulatorProject.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulatorProject.dir/main.cpp.o -c /Users/yuvalkasner/Documents/c++_projects/simulatorProject/main.cpp

CMakeFiles/simulatorProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulatorProject.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuvalkasner/Documents/c++_projects/simulatorProject/main.cpp > CMakeFiles/simulatorProject.dir/main.cpp.i

CMakeFiles/simulatorProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulatorProject.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuvalkasner/Documents/c++_projects/simulatorProject/main.cpp -o CMakeFiles/simulatorProject.dir/main.cpp.s

# Object files for target simulatorProject
simulatorProject_OBJECTS = \
"CMakeFiles/simulatorProject.dir/server.cpp.o" \
"CMakeFiles/simulatorProject.dir/commands/OpenServerCommand.cpp.o" \
"CMakeFiles/simulatorProject.dir/commands/ConnectCommand.cpp.o" \
"CMakeFiles/simulatorProject.dir/commands/DefineVarCommand.cpp.o" \
"CMakeFiles/simulatorProject.dir/commands/IfCommand.cpp.o" \
"CMakeFiles/simulatorProject.dir/commands/LoopCommand.cpp.o" \
"CMakeFiles/simulatorProject.dir/commands/FuncCommand.cpp.o" \
"CMakeFiles/simulatorProject.dir/commands/ForLoop.cpp.o" \
"CMakeFiles/simulatorProject.dir/SymbolTable.cpp.o" \
"CMakeFiles/simulatorProject.dir/commands/ConditionalParser.cpp.o" \
"CMakeFiles/simulatorProject.dir/commands/Print.cpp.o" \
"CMakeFiles/simulatorProject.dir/commands/Sleep.cpp.o" \
"CMakeFiles/simulatorProject.dir/client.cpp.o" \
"CMakeFiles/simulatorProject.dir/Observer.cpp.o" \
"CMakeFiles/simulatorProject.dir/SimManager.cpp.o" \
"CMakeFiles/simulatorProject.dir/main.cpp.o"

# External object files for target simulatorProject
simulatorProject_EXTERNAL_OBJECTS =

simulatorProject: CMakeFiles/simulatorProject.dir/server.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/commands/OpenServerCommand.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/commands/ConnectCommand.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/commands/DefineVarCommand.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/commands/IfCommand.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/commands/LoopCommand.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/commands/FuncCommand.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/commands/ForLoop.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/SymbolTable.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/commands/ConditionalParser.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/commands/Print.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/commands/Sleep.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/client.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/Observer.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/SimManager.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/main.cpp.o
simulatorProject: CMakeFiles/simulatorProject.dir/build.make
simulatorProject: CMakeFiles/simulatorProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable simulatorProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simulatorProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simulatorProject.dir/build: simulatorProject

.PHONY : CMakeFiles/simulatorProject.dir/build

CMakeFiles/simulatorProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simulatorProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simulatorProject.dir/clean

CMakeFiles/simulatorProject.dir/depend:
	cd /Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yuvalkasner/Documents/c++_projects/simulatorProject /Users/yuvalkasner/Documents/c++_projects/simulatorProject /Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug /Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug /Users/yuvalkasner/Documents/c++_projects/simulatorProject/cmake-build-debug/CMakeFiles/simulatorProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simulatorProject.dir/depend

