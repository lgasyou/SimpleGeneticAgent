//
// Created by xenon on 2020/5/2.
//

#pragma once

namespace Environment {
    class GameEnvironment;
}

namespace Agent {
    struct Individual;
    class IAgentVisitor;

    // 遗传算法智能体接口
    class IGeneticAgent {
    public:
        virtual void Evolute() = 0;

        // 当前的代数
        [[nodiscard]]
        virtual unsigned int Generation() const noexcept = 0;

        // 获得最佳的个体
        [[nodiscard]]
        virtual const Individual& GetBestIndividual() const = 0;

        // 迭代是否完成
        [[nodiscard]]
        virtual bool Done() const noexcept = 0;

        // 获得与智能体相关连的环境
        [[nodiscard]]
        virtual const Environment::GameEnvironment& Environment() const = 0;

        // 接收访问者
        virtual void Accept(const IAgentVisitor& visitor) const = 0;
    };
}