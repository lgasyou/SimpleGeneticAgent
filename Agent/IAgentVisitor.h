//
// Created by xenon on 2020/4/25.
//

#pragma once

class IGeneticAgent;

class IAgentVisitor {
public:
    virtual void Visit(const IGeneticAgent& agent) const = 0;
};
