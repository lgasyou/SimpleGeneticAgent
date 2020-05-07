//
// Created by xenon on 2020/5/2.
//

#pragma once

struct Entity;
class IAgentVisitor;
class GameEnvironment;

class IGeneticAgent {
public:
    virtual void Evolute() = 0;

    [[nodiscard]]
    virtual unsigned int Generation() const noexcept = 0;

    [[nodiscard]]
    virtual const Entity& GetBestEntity() const = 0;

    [[nodiscard]]
    virtual bool Done() const noexcept = 0;

    [[nodiscard]]
    virtual const GameEnvironment& Environment() const = 0;

    virtual void Accept(const IAgentVisitor& visitor) const = 0;
};
