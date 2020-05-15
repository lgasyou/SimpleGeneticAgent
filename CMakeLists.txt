cmake_minimum_required(VERSION 3.16)
project(EightPuzzle)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        EightPuzzle
        Main.cpp
        Environment/GameEnvironment.h
        Agent/SimpleGeneticBestIndividualVisitor.h
        Agent/SimpleGeneticAgent.h
        Environment/GameEnvironment.cpp
        Agent/SimpleGeneticAgent.cpp
        Agent/SimpleGeneticBestIndividualVisitor.cpp
        Agent/IAgentVisitor.h Agent/Individual.h
        Agent/Individual.cpp
        Agent/IGeneticAgent.h
        Agent/SimpleGeneticEveryGenerationVisitor.cpp
        Agent/SimpleGeneticEveryGenerationVisitor.h
        Environment/EightPuzzleGame.cpp
        Environment/EightPuzzleGame.h
        Environment/IGame.h
        Random.h
        Agent/SelectionStrategy.cpp
        Agent/SelectionStrategy.h
        Agent/CrossoverStrategy.cpp
        Agent/CrossoverStrategy.h)
