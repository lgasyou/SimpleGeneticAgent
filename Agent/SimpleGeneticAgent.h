//
// Created by xenon on 2020/4/25.
//

#pragma once

#include "IGeneticAgent.h"
#include "Individual.h"
#include "SelectionStrategy.h"
#include "CrossoverStrategy.h"

#include <random>
#include <memory>

namespace Environment {
    class GameEnvironment;
}

namespace Agent {
    class IAgentVisitor;

    // 遗传算法智能体的简单实现类
    class SimpleGeneticAgent final : public IGeneticAgent {
    private:
        const int kMaxGeneration;
        const int kPopulation;
        const float kMutationRate;
        const int kChromosomeLength;

    private:
        Environment::GameEnvironment& environment;
        std::vector<Individual> population;
        unsigned int generation = 0;
        std::default_random_engine& randomEngine;
        std::uniform_real_distribution<float> mutateDist;
        std::unique_ptr<ICrossoverStrategy> crossoverStrategy;
        std::unique_ptr<ISelectionStrategy> selectionStrategy;

    public:
        explicit SimpleGeneticAgent(Environment::GameEnvironment& environment, int maxGeneration, int population,
                                    float crossoverRate, float mutationRate, int chromosomeLength) noexcept;

        ~SimpleGeneticAgent() = default;

        void Evolute() override;

        [[nodiscard]]
        unsigned int Generation() const noexcept override;

        [[nodiscard]]
        const Individual& GetBestIndividual() const override;

        [[nodiscard]]
        bool Done() const noexcept override;

        void Accept(const IAgentVisitor& visitor) const override;

        [[nodiscard]]
        const Environment::GameEnvironment& Environment() const override;

    private:
        // 初始化群体，并获取每个个体的评分
        void InitPopulation();

        // 对每个个体进行评价
        void EvaluatePopulation();

        // 选择
        void Select();

        // 交叉
        void Crossover();

        // 变异
        void Mutate();
    };
}