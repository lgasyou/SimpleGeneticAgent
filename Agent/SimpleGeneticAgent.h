//
// Created by xenon on 2020/4/25.
//

#pragma once

#include "IGeneticAgent.h"
#include "Entity.h"

#include <random>

class IAgentVisitor;
class GameEnvironment;

class SimpleGeneticAgent final : public IGeneticAgent {
private:
    const int kMaxGeneration;
    const int kPopulation;
    const float kCrossoverRate;
    const float kMutationRate;
    const int kChromosomeLength;

private:
    GameEnvironment& environment;
    std::vector<Entity> colony;
    unsigned int generation = 0;
    std::default_random_engine& randomEngine;
    std::uniform_real_distribution<float> selectDist;
    std::uniform_real_distribution<float> crossoverDist;
    std::uniform_real_distribution<float> mutateDist;

public:
    explicit SimpleGeneticAgent(GameEnvironment& environment, int maxGeneration, int population,
                                float crossoverRate, float mutationRate, int chromosomeLength) noexcept;

    ~SimpleGeneticAgent() = default;

    void Evolute() override;

    [[nodiscard]]
    unsigned int Generation() const noexcept override;

    [[nodiscard]]
    const Entity& GetBestEntity() const override;

    [[nodiscard]]
    bool Done() const noexcept override;

    void Accept(const IAgentVisitor& visitor) const override;

    [[nodiscard]]
    const GameEnvironment& Environment() const override;

private:
    void InitColony();

    void EvaluateColony();

    void Select();

    void Crossover();

    void Mutate();
};
