//
// Created by xenon on 2020/4/25.
//

#pragma once

#include "IAgentVisitor.h"

class IGeneticAgent;

class SimpleGeneticBestEntityVisitor final : public IAgentVisitor {
public:
    void Visit(const IGeneticAgent& agent) const override;
};
