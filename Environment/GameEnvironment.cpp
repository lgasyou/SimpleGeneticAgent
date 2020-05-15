//
// Created by xenon on 2020/4/25.
//

#include "GameEnvironment.h"
#include "IGame.h"

using namespace Environment;

GameEnvironment::GameEnvironment(IGame& game) : game(game) {

}

float GameEnvironment::Evaluate(const Agent::ChromosomeType& chromosome) {
    game.Reset();
    const auto& actions = DecodeChromosome(chromosome);
    for (const auto action : actions) {
        game.Act(action);
        if (game.Done()) {
            break;
        }
    }
    return game.Score();
}

std::vector<unsigned int> GameEnvironment::DecodeChromosome(const Agent::ChromosomeType& chromosome) const {
    std::vector<unsigned int> ret;
    auto iter = chromosome.cbegin();
    while (iter != chromosome.cend() && iter + 1 != chromosome.cend()) {
        auto first = *iter;
        ++iter;
        auto second = *iter;
        ++iter;
        auto action = first * 2 + second;
        ret.push_back(action);
    }
    return ret;
}

const IGame& GameEnvironment::Game() const {
    return game;
}

float GameEnvironment::BestScore() const {
    return game.BestScore();
}
