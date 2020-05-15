//
// Created by xenon on 2020/5/1.
//

#include "Individual.h"
#include "../Random.h"

using namespace Agent;

Individual::Individual(int length) {
    auto& engine = RandomEngine();
    static std::uniform_int_distribution dist{0, 1};
    for (int i = 0; i < length; ++i) {
        Chromosome.push_back(dist(engine));
    }
}
