#include "State.h"

#include <iostream>
#include <random>

State::State()
{
    //TODO Exercise 1
}

void State::execute(Move move)
{
    //TODO Exercise 2
}

void State::update_winner(Move move)
{
    int changed_column = move.get_column();
    int changed_row = move.get_row();

    //TODO
}

int State::minimax()
{
    //TODO
    return 0;
}

bool State::has_ended()
{
    //TODO Exercise 2
    return true;
}

Player State::get_winner()
{
    return winner;
}

void State::read_move()
{
    //TODO Exercise 2
}

void State::generate_move()
{
    //TODO
}

void State::print()
{
    std::cout << "   ";
    for (int column = 0; column < 3; column++)
    {
        std::cout << " " << static_cast<char>('a' + column) << "  ";
    }
    std::cout << std::endl;
    print_empty_line();
    for (int row = 0; row < 3; row++)
    {
        std::cout << row + 1 << " ";
        print_line(row);
        print_empty_line();
    }
}

void State::print_empty_line()
{
    std::cout << "  +";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "---+";
    }
    std::cout << std::endl;
}

void State::print_line(int row)
{
    const static char player_chars[] = {' ', 'X', 'O'};
    std::cout << "|";
    for (int column = 0; column < 3; column++)
    {
        Player occupation = field[column][row];
        std::cout << " " << player_chars[static_cast<int>(occupation)] << " |";
    }
    std::cout << std::endl;
}