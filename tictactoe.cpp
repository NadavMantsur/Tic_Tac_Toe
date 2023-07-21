#include <iostream>
#include <vector>

#include "tictactoe.hpp"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
Player::Player(Symbol symbol_): m_symbol(symbol_)
{}

Symbol Player::GetSymbol() const
{
    return m_symbol;
}

void Player::MakeMove(Board& board_)
{
    int row, col;
    cout << "Player ";
    if (Symbol::X == m_symbol)
    {
        cout << "X";
    }
    else
    {
        cout << "O";
    }
    cout << ", enter your move (row column): ";
    cin >> row >> col;

    if (false == board_.MakeMove(row, col, m_symbol == Symbol::X ? 'X' : 'O'))
    {
        cout << "Invalid move! Try again." << endl;

        MakeMove(board_);
    }
}

////////////////////////////////////////////////////////////////////////////////
Board::Board(): m_board(3, vector<char>(3, ' '))
{}

void Board::PrintBoard() const
{
    for (const auto& row : m_board)
    {
        for (char cell : row)
        {
            cout << cell << " ";
        }

        cout << endl;
    }
}

bool Board::MakeMove(int row_, int col_, char symbol_)
{
    if (0 > row_ || 3 <= row_ || 0 > col_ || 3 <= col_ || ' ' != m_board[row_][col_])
    {
        return false;
    }

    m_board[row_][col_] = symbol_;

    return true;
}

bool Board::CheckWin(char const symbol_) const
{
    // rows
    for (const auto& row : m_board)
    {
        if (symbol_ == row[0] && symbol_ == row[1] && symbol_ == row[2] )
        {
            return true;
        }
    }

    // cols
    for (int col = 0; col < 3; ++col)
    {
        if (symbol_ == m_board[0][col] && 
            symbol_ == m_board[1][col] && 
            symbol_ == m_board[2][col])
        {
            return true;
        }
    }

    // diags
    if (symbol_ == m_board[0][0] && 
        symbol_ == m_board[1][1] && 
        symbol_ == m_board[2][2])
    {
        return true;
    }

    if (symbol_ == m_board[0][2] && 
        symbol_ == m_board[1][1] && 
        symbol_ == m_board[2][0])
    {
        return true;
    }

    return false;
}

////////////////////////////////////////////////////////////////////////////////
TicTacToe::TicTacToe(): m_board(), m_currPlayer(Symbol::X), m_movesCnt(0)
{
    m_players.emplace_back(Symbol::X);
    m_players.emplace_back(Symbol::O);
}

void TicTacToe::StartGame()
{
    cout << "Welcome to the Champions Tic-Tac-Toe league" <<endl;

    while (9 > m_movesCnt)
    {
        m_board.PrintBoard();

        m_players[static_cast<int>(m_currPlayer)].MakeMove(m_board);
        
        ++m_movesCnt;

        if (m_board.CheckWin(m_players[static_cast<int>(m_currPlayer)].GetSymbol() == Symbol::X ? 'X' : 'O'))
        {
            // cout << "The winner is: Player "<< static_cast<char>(m_currPlayer)<< endl;
            cout << "The winner is Player: ";
            if (Symbol::X == m_currPlayer) 
            {
                cout << "X";
            } 
            else 
            {
                cout << "O";
            }

            cout << endl;
        
            m_board.PrintBoard();

            return;
        }

        m_currPlayer = (Symbol::X == m_currPlayer) ? Symbol::O : Symbol::X;
    }

    cout << "It is a tie" << endl;

    m_board.PrintBoard();
}