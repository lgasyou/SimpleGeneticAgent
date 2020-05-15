//
// Created by xenon on 2020/5/1.
//

#pragma once

#include <vector>

namespace Agent {
    using ChromosomeCode = unsigned int;
    using ChromosomeType = std::vector<ChromosomeCode>;

    // 遗传算法中的个体
    struct Individual {
    public:
        // 染色体
        ChromosomeType Chromosome;

        // 个体得分
        float Score = -1;

    public:
        explicit Individual(int length);

        Individual(const Individual& rhs) = default;

        ~Individual() = default;
    };
}
