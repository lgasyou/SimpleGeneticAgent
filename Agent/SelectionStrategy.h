//
// Created by xenon on 2020/5/15.
//

#pragma once

#include "Individual.h"

#include <random>

namespace Agent {
    // 选择算法接口
    class ISelectionStrategy {
    public:
        virtual void Select(std::vector<Individual>& population) = 0;

        virtual ~ISelectionStrategy() = default;
    };

    // 轮盘式选择
    class RouletteWheelSelection final : public ISelectionStrategy {
    private:
        std::uniform_real_distribution<float> selectDist;

    public:
        RouletteWheelSelection();

        void Select(std::vector<Individual>& population) override;

    };
}
