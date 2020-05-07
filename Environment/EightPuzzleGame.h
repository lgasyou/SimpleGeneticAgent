//
// Created by xenon on 2020/5/3.
//

#pragma once

#include "IGame.h"

#include <vector>
#include <functional>

class EightPuzzleGame final : public IGame {
private:
    const std::vector<int> kInitBoard;
    const std::vector<int> kFinalBoard;
    std::vector<int> board;
    std::vector<std::function<void()>> acts;

public:
    static constexpr int EMPTY = -1;

public:
    explicit EightPuzzleGame(std::vector<int> board);

    EightPuzzleGame(const EightPuzzleGame& rhs);

    ~EightPuzzleGame() = default;

    void Reset() override;

    void Act(unsigned int action) override;

    [[nodiscard]]
    float Score() const override;

    [[nodiscard]]
    bool Done() const noexcept override;

    [[nodiscard]]
    std::shared_ptr<IGame> Clone() const override;

    [[nodiscard]]
    unsigned int ActionSpace() const override;

    void Print() const override;

private:
    [[nodiscard]]
    std::size_t EmptyIndex() const;

    void MoveLeft();

    void MoveRight();

    void MoveUp();

    void MoveDown();

    void InitActs();
};
