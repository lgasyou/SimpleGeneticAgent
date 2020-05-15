//
// Created by xenon on 2020/5/2.
//

#pragma once

#include "IAgentVisitor.h"

namespace Agent {
    class IGeneticAgent;

    // 用于在每代访问智能体，获取当前智能体的基本迭代信息
    class SimpleGeneticEveryGenerationVisitor final : public IAgentVisitor {
    public:
        void Visit(const IGeneticAgent& agent) const override;
    };
}