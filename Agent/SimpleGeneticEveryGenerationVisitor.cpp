//
// Created by xenon on 2020/5/2.
//

#include "SimpleGeneticEveryGenerationVisitor.h"
#include "IGeneticAgent.h"
#include "Individual.h"

#include <iostream>

using std::cout, std::endl;
using namespace Agent;

void SimpleGeneticEveryGenerationVisitor::Visit(const IGeneticAgent& agent) const {
    const auto& entity = agent.GetBestIndividual();
    const float score = entity.Score;
    cout << "进化至第" << agent.Generation() << "代，最优个体得分为：" << score << endl;
}
