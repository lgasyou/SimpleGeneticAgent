//
// Created by xenon on 2020/5/3.
//

#include "EightPuzzleGame.h"

#include <iostream>
#include <functional>

using std::cout, std::endl;
using namespace Environment;

EightPuzzleGame::EightPuzzleGame(
        std::vector<int> board
) : kInitBoard(std::move(board)),
    kFinalBoard({1, 2, 3, 8, EMPTY, 4, 7, 6, 5}) {
    Reset();
    InitActs();
}

EightPuzzleGame::EightPuzzleGame(
        const EightPuzzleGame& rhs
) : kInitBoard(rhs.kInitBoard),
    kFinalBoard(rhs.kFinalBoard),
    board(rhs.board) {
    InitActs();
}

void EightPuzzleGame::Reset() {
    board = kInitBoard;
}

void EightPuzzleGame::Act(unsigned int action) {
    assert(action < ActionSpace());
    acts[action]();
}

float EightPuzzleGame::Score() const {
    float score = 0;
    for (int i = 0; i < 9; ++i) {
        if (board[i] == kFinalBoard[i]) {
            ++score;
        }
    }
    return score;
}

float EightPuzzleGame::BestScore() const {
    return BEST_SCORE;
}

bool EightPuzzleGame::Done() const noexcept {
    return board == kFinalBoard;
}

std::shared_ptr<IGame> EightPuzzleGame::Clone() const {
    return std::make_shared<EightPuzzleGame>(*this);
}

unsigned EightPuzzleGame::ActionSpace() const {
    return 4;
}

void EightPuzzleGame::Print() const {
    for (int i = 0; i < 9; ++i) {
        std::string v = (board[i] == EMPTY) ? " " : std::to_string(board[i]);
        cout << v << " ";
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

std::size_t EightPuzzleGame::EmptyIndex() const {
    return std::find(board.cbegin(), board.cend(), EMPTY) - board.cbegin();
}

void EightPuzzleGame::MoveLeft() {
    auto index = EmptyIndex();
    if (index % 3 != 2) {
        board[index] = board[index + 1];
        board[index + 1] = EMPTY;
    }
}

void EightPuzzleGame::MoveRight() {
    auto index = EmptyIndex();
    if (index % 3 != 0) {
        board[index] = board[index - 1];
        board[index - 1] = EMPTY;
    }
}

void EightPuzzleGame::MoveUp() {
    auto index = EmptyIndex();
    if (index < 6) {
        board[index] = board[index + 3];
        board[index + 3] = EMPTY;
    }
}

void EightPuzzleGame::MoveDown() {
    auto index = EmptyIndex();
    if (index >= 3) {
        board[index] = board[index - 3];
        board[index - 3] = EMPTY;
    }
}

void EightPuzzleGame::InitActs() {
    acts = {
            [this] { MoveLeft(); },
            [this] { MoveRight(); },
            [this] { MoveUp(); },
            [this] { MoveDown(); }
    };
}
