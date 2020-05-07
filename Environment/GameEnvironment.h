//
// Created by xenon on 2020/4/25.
//

#pragma once

class IGame;

#include <vector>

class GameEnvironment final {
private:
    IGame& game;

public:
    explicit GameEnvironment(IGame& game);

    ~GameEnvironment() = default;

    [[nodiscard]]
    float Evaluate(const std::vector<unsigned int>& actions);

    [[nodiscard]]
    const IGame& Game() const;

    [[nodiscard]]
    std::vector<unsigned int> DecodeChromosome(const std::vector<unsigned int>& chromosome) const;
};
