cmake_minimum_required(VERSION 3.16)
project(EightPuzzle)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        EightPuzzle
        Main.cpp
        Environment/GameEnvironment.h
        Agent/SimpleGeneticBestEntityVisitor.h
        Agent/SimpleGeneticAgent.h
        Environment/GameEnvironment.cpp
        Agent/SimpleGeneticAgent.cpp
        Agent/SimpleGeneticBestEntityVisitor.cpp
        Agent/IAgentVisitor.h Agent/Entity.h
        Agent/Entity.cpp
        Agent/IGeneticAgent.h
        Agent/SimpleGeneticEveryGenerationVisitor.cpp
        Agent/SimpleGeneticEveryGenerationVisitor.h
        Environment/EightPuzzleGame.cpp
        Environment/EightPuzzleGame.h
        Environment/IGame.h
        Random.h)
