//
// Created by xenon on 2020/5/1.
//

#pragma once

#include <vector>

class Entity {
public:
    std::vector<unsigned int> Chromosome;
    float Score = -1;

public:
    explicit Entity(int length);

    Entity(const Entity& rhs) = default;

    ~Entity() = default;
};
