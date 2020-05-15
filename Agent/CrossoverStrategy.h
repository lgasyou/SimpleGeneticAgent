//
// Created by xenon on 2020/5/15.
//

#pragma once

#include "Individual.h"

#include <random>

namespace Agent {
    // 交叉算法接口
    class ICrossoverStrategy {
    public:
        virtual void Crossover(std::vector<Individual>& population) = 0;

        virtual ~ICrossoverStrategy() = default;
    };

    // 单点交叉算法
    class OnePointCrossover final : public ICrossoverStrategy {
    private:
        const float kCrossoverRate;
        const int kChromosomeLength;
        const int kPopulation;
        std::uniform_real_distribution<float> crossoverDist;

    public:
        explicit OnePointCrossover(float crossoverRate, int chromosomeLength, int population);

        void Crossover(std::vector<Individual>& population) override;
    };
}
