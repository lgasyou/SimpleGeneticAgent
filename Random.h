//
// Created by xenon on 2020/5/5.
//

#pragma once

#include <random>

inline std::default_random_engine& RandomEngine() {
    static std::default_random_engine eng;
    return eng;
}
