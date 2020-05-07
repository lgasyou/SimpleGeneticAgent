//
// Created by xenon on 2020/5/3.
//

#pragma once

#include <memory>

class IGame {
public:
    virtual void Reset() = 0;

    virtual void Act(unsigned int action) = 0;

    [[nodiscard]]
    virtual float Score() const = 0;

    [[nodiscard]]
    virtual bool Done() const noexcept = 0;

    [[nodiscard]]
    virtual std::shared_ptr<IGame> Clone() const = 0;

    [[nodiscard]]
    virtual unsigned int ActionSpace() const = 0;

    virtual void Print() const = 0;
};
