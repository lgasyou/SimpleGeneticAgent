//
// Created by xenon on 2020/4/25.
//

#pragma once

#include "../Agent/Individual.h"

#include <vector>

namespace Environment {
    class IGame;

    // 抽象的高层环境模块，智能体与之交互来提高、验证决策
    class GameEnvironment final {
    private:
        IGame& game;

    public:
        explicit GameEnvironment(IGame& game);

        ~GameEnvironment() = default;

        // 对接收到的 actions 给出评分
        [[nodiscard]]
        float Evaluate(const Agent::ChromosomeType& actions);

        // 获取环境使用的游戏模块
        [[nodiscard]]
        const IGame& Game() const;

        // 获取环境到达结束状态时的最佳得分
        [[nodiscard]]
        float BestScore() const;

        // 解码染色体，获得动作集合
        [[nodiscard]]
        std::vector<unsigned int> DecodeChromosome(const Agent::ChromosomeType& chromosome) const;
    };
}