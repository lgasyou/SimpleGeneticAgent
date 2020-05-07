#include "Environment/GameEnvironment.h"
#include "Environment/EightPuzzleGame.h"
#include "Agent/SimpleGeneticAgent.h"
#include "Agent/SimpleGeneticBestEntityVisitor.h"
#include "Agent/SimpleGeneticEveryGenerationVisitor.h"

#include <iostream>

void Round(int population, int maxGeneration, float crossoverRate, float mutationRate,
           int chromosomeLength, const std::initializer_list<int>& board) {
    std::cout << "群体大小：" << population << "，最大迭代数：" << maxGeneration
              << "，交叉几率：" << crossoverRate << "，变异几率：" << mutationRate
              << "，染色体长度：" << chromosomeLength << std::endl;

    EightPuzzleGame game{board};
    GameEnvironment environment{game};
    SimpleGeneticBestEntityVisitor bestEntityVisitor{};
    SimpleGeneticEveryGenerationVisitor generationVisitor{};
    SimpleGeneticAgent agent{environment, maxGeneration, population, crossoverRate, mutationRate, chromosomeLength};

    while (!agent.Done()) {
        agent.Evolute();
        agent.Accept(generationVisitor);
    }
    agent.Accept(bestEntityVisitor);
}

int main() {
    constexpr int population = 10;
    constexpr int maxGeneration = 10;
    constexpr float crossoverRate = 0.7f;
    constexpr float mutationRate = 0.001f;
    constexpr int chromosomeLength = 70;
    const auto& board = {2, 8, 3, 1, EightPuzzleGame::EMPTY, 4, 7, 6, 5};

    Round(population, maxGeneration, crossoverRate, mutationRate, chromosomeLength, board);

    return 0;
}
