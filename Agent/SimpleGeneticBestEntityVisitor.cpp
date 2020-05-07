//
// Created by xenon on 2020/4/25.
//

#include "SimpleGeneticBestEntityVisitor.h"
#include "IGeneticAgent.h"
#include "Entity.h"
#include "../Environment/GameEnvironment.h"
#include "../Environment/IGame.h"

#include <iostream>

using std::cout, std::endl;

namespace {
    std::string ActionsToString(const std::vector<unsigned int>& actions) {
        static std::vector<std::string> strings = {"左", "右", "上", "下"};
        std::string ret;
        for (const auto& action : actions) {
            ret += strings[action];
        }
        return ret;
    }
}

void SimpleGeneticBestEntityVisitor::Visit(const IGeneticAgent& agent) const {
    const auto& entity = agent.GetBestEntity();
    const auto& chromosome = entity.Chromosome;
    const auto& actions = agent.Environment().DecodeChromosome(chromosome);

    const auto game = agent.Environment().Game().Clone();
    game->Reset();
    std::vector<unsigned int> realActions;
    for (auto act : actions) {
        game->Print();
        game->Act(act);
        realActions.push_back(act);
        if (game->Done()) {
            game->Print();
            break;
        }
    }
    cout << "解路线为：" << ::ActionsToString(realActions) << endl;
}
