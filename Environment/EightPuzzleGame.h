//
// Created by xenon on 2020/5/3.
//

#pragma once

#include "IGame.h"

#include <vector>
#include <functional>

namespace Environment {
    // 八数字谜题的实现类
    class EightPuzzleGame final : public IGame {
    private:
        // 每局游戏的初始棋盘
        const std::vector<int> kInitBoard;

        // 完成状态的棋盘
        const std::vector<int> kFinalBoard;

        // 当前状态的棋盘
        std::vector<int> board;

        // 动作谓词
        std::vector<std::function<void()>> acts;

    public:
        // 空白部分在棋盘中的值
        static constexpr int EMPTY = -1;

        // 八数字游戏能够取得的最好得分
        static constexpr int BEST_SCORE = 9;

    public:
        explicit EightPuzzleGame(std::vector<int> board);

        EightPuzzleGame(const EightPuzzleGame& rhs);

        ~EightPuzzleGame() = default;

        void Reset() override;

        void Act(unsigned int action) override;

        [[nodiscard]]
        float Score() const override;

        [[nodiscard]]
        float BestScore() const override;

        [[nodiscard]]
        bool Done() const noexcept override;

        [[nodiscard]]
        std::shared_ptr<IGame> Clone() const override;

        [[nodiscard]]
        unsigned int ActionSpace() const override;

        void Print() const override;

    private:
        // 获得空白位置的索引
        [[nodiscard]]
        std::size_t EmptyIndex() const;

        // 数字左移，空白右移
        void MoveLeft();

        // 数字右移，空白左移
        void MoveRight();

        // 数字上移，空白下移
        void MoveUp();

        // 数字下移，空白上移
        void MoveDown();

        // 初始化动作谓词
        void InitActs();
    };
}