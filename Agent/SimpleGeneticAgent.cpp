//
// Created by xenon on 2020/4/25.
//

#include "SimpleGeneticAgent.h"
#include "IAgentVisitor.h"
#include "../Environment/GameEnvironment.h"
#include "../Random.h"

using namespace Agent;

SimpleGeneticAgent::SimpleGeneticAgent(Environment::GameEnvironment& environment, int maxGeneration,
                                       int population, float crossoverRate, float mutationRate, int chromosomeLength
) noexcept :
    kMaxGeneration(maxGeneration),
    kPopulation(population),
    kMutationRate(mutationRate),
    kChromosomeLength(chromosomeLength),
    environment(environment),
    randomEngine(RandomEngine()),
    mutateDist(0, 1),
    crossoverStrategy(std::make_unique<OnePointCrossover>(crossoverRate, chromosomeLength, population)),
    selectionStrategy(std::make_unique<RouletteWheelSelection>()) {
    InitPopulation();
}

void SimpleGeneticAgent::Evolute() {
    Select();
    Crossover();
    Mutate();
    EvaluatePopulation();
    ++generation;
}

bool SimpleGeneticAgent::Done() const noexcept {
    const auto& best = GetBestIndividual();
    const bool gotBestScore = best.Score == environment.BestScore();
    return generation >= kMaxGeneration || gotBestScore;
}

void SimpleGeneticAgent::Select() {
    selectionStrategy->Select(population);
}

void SimpleGeneticAgent::Crossover() {
    crossoverStrategy->Crossover(population);
}

void SimpleGeneticAgent::Mutate() {
    for (auto& entity : population) {
        for (auto& c : entity.Chromosome) {
            if (mutateDist(randomEngine) <= kMutationRate) {
                c = !c;
            }
        }
    }
}

void SimpleGeneticAgent::InitPopulation() {
    generation = 0;
    for (int i = 0; i < kPopulation; ++i) {
        auto individual = Individual(kChromosomeLength);
        individual.Score = environment.Evaluate(individual.Chromosome);
        population.push_back(std::move(individual));
    }
}

void SimpleGeneticAgent::EvaluatePopulation() {
    for (auto& individual : population) {
        float score = environment.Evaluate(individual.Chromosome);
        individual.Score = score;
    }
}

const Individual& SimpleGeneticAgent::GetBestIndividual() const {
    float bestScore = -1;
    std::size_t index = -1;
    for (std::size_t i = 0; i < population.size(); ++i) {
        const auto& individual = population[i];
        if (individual.Score > bestScore) {
            bestScore = individual.Score;
            index = i;
        }
    }
    return population.at(index);
}

void SimpleGeneticAgent::Accept(const IAgentVisitor& visitor) const {
    visitor.Visit(*this);
}

unsigned int SimpleGeneticAgent::Generation() const noexcept {
    return generation;
}

const Environment::GameEnvironment& SimpleGeneticAgent::Environment() const {
    return environment;
}
