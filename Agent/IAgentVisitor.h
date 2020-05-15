//
// Created by xenon on 2020/4/25.
//

#pragma once

namespace Agent {
    class IGeneticAgent;

    // 访问遗传算法智能体的接口
    class IAgentVisitor {
    public:
        virtual void Visit(const IGeneticAgent& agent) const = 0;
    };
}