#pragma once
#include <string>

class TicTacToe {
    private:
        std::string m_board;
        char m_xChar, m_oChar;
    public:
        TicTacToe();
        void startGame();
        bool isWinner(char p);
        void printBoard();
        bool isTie();
};