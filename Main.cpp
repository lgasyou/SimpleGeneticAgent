#include "Environment/GameEnvironment.h"
#include "Environment/EightPuzzleGame.h"
#include "Agent/SimpleGeneticAgent.h"
#include "Agent/SimpleGeneticBestIndividualVisitor.h"
#include "Agent/SimpleGeneticEveryGenerationVisitor.h"

#include <iostream>

using namespace Agent;
using namespace Environment;

// 使用特定参数的一次迭代过程
void Round(int population, int maxGeneration, float crossoverRate, float mutationRate,
           int chromosomeLength, const std::initializer_list<int>& board) {
    std::cout << "群体大小：" << population << "，最大迭代数：" << maxGeneration
              << "，交叉几率：" << crossoverRate << "，变异几率：" << mutationRate
              << "，染色体长度：" << chromosomeLength << std::endl;

    EightPuzzleGame game{board};
    GameEnvironment environment{game};
    SimpleGeneticBestIndividualVisitor bestIndividualVisitor{};
    SimpleGeneticEveryGenerationVisitor generationVisitor{};
    SimpleGeneticAgent agent{environment, maxGeneration, population, crossoverRate, mutationRate, chromosomeLength};

    // 持续进化，直至进化到最高的适应度，或是到达最大迭代数
    while (!agent.Done()) {
        // 进化
        agent.Evolute();

        // 打印每次迭代过程中的智能体信息
        agent.Accept(generationVisitor);
    }
    // 打印迭代结束后的智能体信息，以及解
    agent.Accept(bestIndividualVisitor);
}

// 可行解：空格上移 空格左移 空格下移 空格右移
int main() {
    // 种群大小
    constexpr int population = 20;

    // 最大迭代数
    constexpr int maxGeneration = 1000;

    // 交叉概率
    constexpr float crossoverRate = 0.7f;

    // 变异概率
    constexpr float mutationRate = 0.001f;

    // 染色体长度
    constexpr int chromosomeLength = 20;

    // 八数字的初始棋盘
    const auto& board = {2, 8, 3, 1, EightPuzzleGame::EMPTY, 4, 7, 6, 5};

    // 检查数据合理性
    static_assert(population > 0);
    static_assert(maxGeneration > 0);
    static_assert(crossoverRate >= 0 && crossoverRate <= 1);
    static_assert(mutationRate >= 0 && mutationRate <= 1);
    static_assert(chromosomeLength > 0);
    assert(board.size() == 9);

    Round(population, maxGeneration, crossoverRate, mutationRate, chromosomeLength, board);

    return 0;
}
