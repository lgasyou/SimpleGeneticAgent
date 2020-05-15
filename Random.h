//
// Created by xenon on 2020/5/5.
//

#pragma once

#include <random>

// 随机数引擎单例
inline std::default_random_engine& RandomEngine() {
    static std::random_device randomDevice;
    static std::default_random_engine eng{randomDevice()};
    return eng;
}
