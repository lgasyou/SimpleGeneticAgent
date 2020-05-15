//
// Created by xenon on 2020/4/25.
//

#include "SimpleGeneticBestIndividualVisitor.h"
#include "IGeneticAgent.h"
#include "Individual.h"
#include "../Environment/GameEnvironment.h"
#include "../Environment/IGame.h"

#include <iostream>

using std::cout, std::endl;
using namespace Agent;

namespace {
    std::string ActionsToString(const std::vector<unsigned int>& actions) {
        static std::vector<std::string> strings = {"空格右移 ", "空格左移 ", "空格下移 ", "空格上移 "};
        std::string ret;
        for (const auto& action : actions) {
            ret += strings[action];
        }
        return ret;
    }
}

void SimpleGeneticBestIndividualVisitor::Visit(const IGeneticAgent& agent) const {
    const auto& individual = agent.GetBestIndividual();
    const auto& chromosome = individual.Chromosome;
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

    const bool gotSolution = individual.Score == agent.Environment().BestScore();
    if (gotSolution) {
        cout << "得到可行解，解路线为：" << ::ActionsToString(realActions) << endl;
    } else {
        cout << "迭代未能取得可行解，近似解得分为" << individual.Score
             << "（可行解得分为" << agent.Environment().BestScore() << "），"
             << "近似解路线为：" << ::ActionsToString(realActions) << endl;
    }
}
