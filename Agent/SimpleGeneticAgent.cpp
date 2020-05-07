//
// Created by xenon on 2020/4/25.
//

#include "SimpleGeneticAgent.h"
#include "IAgentVisitor.h"
#include "../Environment/GameEnvironment.h"
#include "../Random.h"

#include <numeric>
#include <iostream>

SimpleGeneticAgent::SimpleGeneticAgent(GameEnvironment& environment, int maxGeneration, int population,
                                       float crossoverRate, float mutationRate, int chromosomeLength
) noexcept : kMaxGeneration(maxGeneration), kPopulation(population), kCrossoverRate(crossoverRate),
    kMutationRate(mutationRate), kChromosomeLength(chromosomeLength), environment(environment),
    randomEngine(RandomEngine()), selectDist(0, 1), crossoverDist(0, 1), mutateDist(0, 1) {
    InitColony();
}

void SimpleGeneticAgent::Evolute() {
    EvaluateColony();
    Select();
    Crossover();
    Mutate();
    ++generation;
}

bool SimpleGeneticAgent::Done() const noexcept {
    return generation >= kMaxGeneration;
}

void SimpleGeneticAgent::Select() {
    float sum = std::accumulate(colony.cbegin(), colony.cend(), 0.f, [](float sum, const Entity& rhs) {
        return sum + rhs.Score;
    });
    for (auto& e : colony) {
        std::cout << e.Score << " ";
    }
    std::cout << sum << std::endl;
}

void SimpleGeneticAgent::Crossover() {

}

void SimpleGeneticAgent::Mutate() {
    for (auto& entity : colony) {
        for (auto& c : entity.Chromosome) {
            if (mutateDist(randomEngine) <= kMutationRate) {
                c = !c;
            }
        }
    }
}

void SimpleGeneticAgent::InitColony() {
    generation = 0;
    for (int i = 0; i < kPopulation; ++i) {
        colony.emplace_back(kChromosomeLength);
    }
}

void SimpleGeneticAgent::EvaluateColony() {
    for (auto& entity : colony) {
        float score = environment.Evaluate(entity.Chromosome);
        entity.Score = score;
    }
}

const Entity& SimpleGeneticAgent::GetBestEntity() const {
    float bestScore = -1;
    std::size_t index = -1;
    for (std::size_t i = 0; i < colony.size(); ++i) {
        const auto& entity = colony[i];
        if (entity.Score > bestScore) {
            bestScore = entity.Score;
            index = i;
        }
    }
    return colony.at(index);
}

void SimpleGeneticAgent::Accept(const IAgentVisitor& visitor) const {
    visitor.Visit(*this);
}

unsigned int SimpleGeneticAgent::Generation() const noexcept {
    return generation;
}

const GameEnvironment& SimpleGeneticAgent::Environment() const {
    return environment;
}
