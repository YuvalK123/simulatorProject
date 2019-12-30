cmake_minimum_required(VERSION 3.15)
project(simulatorProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS-pthread)

add_executable(simulatorProject server.cpp commands/Command.h commands/OpenServerCommand.cpp
        commands/ConnectCommand.cpp commands/DefineVarCommand.cpp commands/ConditionParser.h commands/IfCommand.cpp
        commands/LoopCommand.cpp commands/FuncCommand.cpp commands/ForLoop.cpp commands/LoopCommand.h
        commands/ConditionalParser.cpp commands/Print.cpp commands/Sleep.cpp client.cpp
        SimManager.h SimManager.cpp main.cpp Server.h commands/OpenServerCommand.h commands/IfCommand.h
        commands/ForLoop.h commands/DefineVarCommand.h expression.h expression.cpp SimulatorHelper.h Client.h
        fly.txt generic_small_to_read.txt commands/ConnectCommand.h commands/Sleep.h commands/Print.h)