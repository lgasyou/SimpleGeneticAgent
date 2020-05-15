//
// Created by xenon on 2020/5/15.
//

#include "CrossoverStrategy.h"
#include "../Random.h"

#include <algorithm>

using namespace Agent;

OnePointCrossover::OnePointCrossover(float crossoverRate, int chromosomeLength, int population)
    : kCrossoverRate(crossoverRate), kChromosomeLength(chromosomeLength),
    kPopulation(population), crossoverDist(0, 1) {

}

void OnePointCrossover::Crossover(std::vector<Individual>& population) {
    auto& engine = RandomEngine();
    std::uniform_int_distribution<int> individualDist{0, kPopulation - 1};
    std::uniform_int_distribution<int> positionDist{0, kChromosomeLength - 1};
    for (int i = 0; i < kPopulation / 2; ++i) {
        if (crossoverDist(engine) < kCrossoverRate) {
            std::size_t first = individualDist(engine);
            std::size_t second = individualDist(engine);
            Individual& lhs = population[first];
            Individual& rhs = population[second];
            std::size_t position = positionDist(engine);
            std::vector<ChromosomeCode> lhsCopy{lhs.Chromosome.cbegin(), lhs.Chromosome.cend()};
            for (int j = position; j < kChromosomeLength; ++j) {
                lhs.Chromosome[j] = rhs.Chromosome[j];
                rhs.Chromosome[j] = lhsCopy[j];
            }
        }
    }
}
