#include "ticTacToe.h"
#include <iostream>
#include <string>

TicTacToe::TicTacToe() {
    m_board = "123456789";
    m_xChar = 'x';
    m_oChar = 'o';
}

void TicTacToe::startGame() {
    printBoard();

    while (true) {
        xMoveLabel:
        int xMove = -1;
        while ((xMove < 1) || (xMove > 9)) {
            std::cout << m_xChar << ": ";
            std::cin >> xMove;
        }
        if ((m_board[xMove - 1] == m_xChar) || (m_board[xMove - 1] == m_oChar)) {
            goto xMoveLabel;
        }
        m_board[xMove - 1] = m_xChar;

        printBoard();
        if (isWinner(m_xChar)) {
            std::cout << m_xChar << " wins." << std::endl;
            break;
        }
        if (isTie()) {
            std::cout << "Tie." << std::endl;
            break;
        }

        oMoveLabel:
        int oMove = -1;
        while ((oMove < 1) || (oMove > 9)) {
            std::cout << m_oChar << ": ";
            std::cin >> oMove;
        }
        if ((m_board[oMove - 1] == m_xChar) || (m_board[oMove - 1] == m_oChar)) {
            goto oMoveLabel;
        }
        m_board[oMove - 1] = m_oChar;

        printBoard();
        if (isWinner(m_oChar)) {
            std::cout << m_oChar << " wins." << std::endl;
            break;
        }
        if (isTie()) {
            std::cout << "Tie." << std::endl;
            break;
        }
    }
    return;
}

void TicTacToe::printBoard() {
    for (int i = 0; i < m_board.length(); i++) {
        std::cout << m_board[i] << ' ';
        if ((i + 1) % 3 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    return;
}

bool TicTacToe::isTie() {
    int usedTiles = 0;
    for (int i = 0; i < m_board.length(); i++) {
        if (m_board[i] > 57) {
            usedTiles++;
        }
    }
    if (usedTiles >= 9) {
        return true;
    }
    return false;
}

bool TicTacToe::isWinner(char p) {
    if (((m_board[0] == p) && (m_board[1] == p)) && (m_board[2] == p)) {
        return true;
    }
    else if (((m_board[3] == p) && (m_board[4] == p)) && (m_board[5] == p)) {
        return true;
    }
    else if (((m_board[6] == p) && (m_board[7] == p)) && (m_board[8] == p)) {
        return true;
    }
    else if (((m_board[0] == p) && (m_board[3] == p)) && (m_board[6] == p)) {
        return true;
    }
    else if (((m_board[1] == p) && (m_board[4] == p)) && (m_board[7] == p)) {
        return true;
    }
    else if (((m_board[2] == p) && (m_board[5] == p)) && (m_board[8] == p)) {
        return true;
    }
    else if (((m_board[0] == p) && (m_board[4] == p)) && (m_board[8] == p)) {
        return true;
    }
    else if (((m_board[2] == p) && (m_board[4] == p)) && (m_board[6] == p)) {
        return true;
    }
    return false;
}