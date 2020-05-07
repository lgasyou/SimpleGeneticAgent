//
// Created by xenon on 2020/5/2.
//

#pragma once

#include "IAgentVisitor.h"

class IGeneticAgent;

class SimpleGeneticEveryGenerationVisitor final : public IAgentVisitor {
public:
    void Visit(const IGeneticAgent& agent) const override;
};
