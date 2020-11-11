//
// Created by xenon on 2020/5/15.
//

#include "SelectionStrategy.h"
#include "../Random.h"

#include <numeric>
#include <stdexcept>

using namespace Agent;

namespace {
    std::size_t RandomChooseWithPossibly(const std::vector<float>& collection, float possibly) {
        for (int i = 0; i < collection.size(); ++i) {
            if (possibly > collection[i]) {
                continue;
            }
            return i;
        }
        throw std::runtime_error("Possibly must in [0, 1].");
    }
}

RouletteWheelSelection::RouletteWheelSelection() : selectDist(0, 1) {

}

void RouletteWheelSelection::Select(std::vector<Individual>& population) {
    std::vector<float> scores;
    scores.reserve(population.size());
    for (const auto& individual : population) {
        scores.push_back(individual.Score);
    }

    float sum = std::accumulate(scores.cbegin(), scores.cend(), 0.f, [](float lhs, float rhs) {
        return lhs + rhs;
    });
    std::vector<float> possiblyList;
    possiblyList.reserve(scores.size());
    float pSum = 0;
    for (const auto& item : scores) {
        pSum += item / sum;
        possiblyList.push_back(pSum);
    }

    std::vector<Individual> newPopulation;
    newPopulation.reserve(population.size());
    for (int i = 0; i < population.size(); ++i) {
        float number = selectDist(RandomEngine());
        std::size_t index = ::RandomChooseWithPossibly(possiblyList, number);
        newPopulation.emplace_back(population[index]);
    }
    population = newPopulation;
}
