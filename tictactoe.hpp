#include <iostream>
#include <vector>

using namespace std;

enum class Symbol { X, O };

class Board
{
public:
    Board();
    ~Board() noexcept =default;

    Board(const Board& o_) =default;
    Board& operator= (const Board& o_) =default;

    void PrintBoard() const;
    bool MakeMove(int row_, int col_, char symbol_);
    bool CheckWin(char const symbol_) const;

private:
    vector<vector<char>> m_board;
};


class Player
{
public:
    Player(Symbol symbol_); 
    ~Player() noexcept =default;

    Player(const Player& o_) =default;
    Player& operator=(const Player& o_) =default;

    Symbol GetSymbol() const;
    void MakeMove(Board& board_);

private:
    Symbol m_symbol;
};


class TicTacToe
{
public:
    TicTacToe();
    ~TicTacToe() noexcept =default;

    TicTacToe(const TicTacToe& o_) =default;
    TicTacToe& operator= (const TicTacToe& o_) =default;

    void StartGame();

private:
    Board m_board;
    vector<Player> m_players;
    Symbol m_currPlayer;
    int m_movesCnt;

};