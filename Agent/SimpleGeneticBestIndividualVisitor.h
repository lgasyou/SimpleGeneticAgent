//
// Created by xenon on 2020/4/25.
//

#pragma once

#include "IAgentVisitor.h"

namespace Agent {
    class IGeneticAgent;

    // 用于访问智能体，获取其最佳个体的具体执行情况
    class SimpleGeneticBestIndividualVisitor final : public IAgentVisitor {
    public:
        void Visit(const IGeneticAgent& agent) const override;
    };
}
