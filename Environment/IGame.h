//
// Created by xenon on 2020/5/3.
//

#pragma once

#include <memory>

namespace Environment {
    // 具体游戏的通用接口
    class IGame {
    public:
        // 重启游戏，使游戏数值回到开始状态
        virtual void Reset() = 0;

        // 使用 action 与游戏进行交互
        virtual void Act(unsigned int action) = 0;

        // 获得当前的得分
        [[nodiscard]]
        virtual float Score() const = 0;

        // 获得游戏完成时的最高得分（对应遗传算法的最高适应度）
        [[nodiscard]]
        virtual float BestScore() const = 0;

        // 游戏是否是结束状态
        [[nodiscard]]
        virtual bool Done() const noexcept = 0;

        // 获取当前对象的副本
        [[nodiscard]]
        virtual std::shared_ptr<IGame> Clone() const = 0;

        // 获得游戏的动作空间大小
        [[nodiscard]]
        virtual unsigned int ActionSpace() const = 0;

        // 打印当前游戏的状态
        virtual void Print() const = 0;
    };
}