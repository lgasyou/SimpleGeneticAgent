//
// Created by xenon on 2020/5/2.
//

#include "SimpleGeneticEveryGenerationVisitor.h"
#include "IGeneticAgent.h"
#include "Entity.h"

#include <iostream>

using std::cout, std::endl;

void SimpleGeneticEveryGenerationVisitor::Visit(const IGeneticAgent& agent) const {
    const auto& entity = agent.GetBestEntity();
    const float score = entity.Score;
    cout << "进化至第" << agent.Generation() << "代，最优个体得分为：" << score << endl;
}
