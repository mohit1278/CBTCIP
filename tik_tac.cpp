#include <iostream>
#include <ctime>
#include <random>
using namespace std;

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
void show();
void get_x_player_choice();
void get_o_player_choice();
void get_computer_choice();
int count_board(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();

int main()
{
    int mode;
    cout << "\n\n1. COMPUTER VS PLAYER " << endl;
    cout << "2. PLAYER VS PLAYER" << endl;
    cout << "select game mode : ";
    cin >> mode;
    switch (mode)
    {
    case 1:
        computer_vs_player();
        break;
    case 2:
        player_vs_player();
        break;
    default:
        cout << "PLEASE SELECT VALID GAME MODE" << endl;
        break;
    }
    return 0;
}

void computer_vs_player()
{
    string player_name;
    cout << "enter your name : ";
    cin >> player_name;

    while (true)
    {
        system("cls");
        cout << "......." << player_name << " VS Computer........\n"
             << endl;
        show();
        if (count_board('x') == count_board('o'))
        {
            cout << "\n"
                 << player_name << "'s turn" << endl;
            get_x_player_choice();
        }
        else
        {
            get_computer_choice();
        }
        char winner = check_winner();
        if (winner == 'x')
        {
            system("cls");
            show();
            cout << "\n..............." << player_name << " won the game  :)................\n\n"
                 << endl;
            break;
        }
        else if (winner == '0')
        {
            system("cls");
            show();
            cout << "\n...........computer won the game :)...............\n\n"
                 << endl;
            break;
        }
        else if (winner == 'd')
        {
            cout << "\n...............GAME Is DRAW....................\n\n"
                 << endl;
            break;
        }
    }
}

void get_computer_choice()
{
    srand(time(0));
    int choice;
    do
    {
        choice = rand() % 10;
    } while (board[choice] != ' ');
    board[choice] = 'o';
}

void get_x_player_choice()
{
    while (true)
    {
        cout << "\n\n select your position (1-9) :";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8)
        {
            cout << "\n......... please select ypur choice from 1-9......... " << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << "\n.........pleae select an emplty position........... " << endl;
        }
        else
        {
            board[choice] = 'x';
            break;
        }
    }
}

void get_o_player_choice()
{
    while (true)
    {
        cout << "\nselect your position (1-9) :";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8)
        {
            cout << "..........please select ypur choice from 1-9 ..........." << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << ".....pleae select an emplty position ........." << endl;
        }
        else
        {
            board[choice] = 'o';
            break;
        }
    }
}

void player_vs_player()
{
    string x_player_name, o_player_name;
    cout << "Enter X player name : ";
    cin >> x_player_name;
    cout << "Enter O player name : ";
    cin >> o_player_name;
    while (true)
    {
        system("cls");
        show();
        if (count_board('x') == count_board('o'))
        {
            cout << "\n\n........" << x_player_name << " 's Turn........" << endl;
            get_x_player_choice();
        }
        else
        {
            cout << "\n\n........" << o_player_name << "'s Turn........" << endl;
            get_o_player_choice();
        }
        char winner = check_winner();
        if (winner == 'x')
        {
            system("cls");
            show();
            cout << "\n\n............" << x_player_name << " won the game.............\n\n"
                 << endl;
            break;
        }
        else if (winner == 'o')
        {
            system("cls");
            show();
            cout << "\n\n............" << o_player_name << " won the game.............\n\n"
                 << endl;
            break;
        }
        else if (winner == 'd')
        {
            cout << "GAME IS DRAW." << endl;
            break;
        }
    }
}

int count_board(char symbol)
{
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == symbol)
        {
            total += 1;
        }
    }
    return total;
}

char check_winner()
{
    // checking winner in horizontal row
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
    {
        return board[3];
    }
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
    {
        return board[6];
    }

    // checking winner in vertical column

    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
    {
        return board[1];
    }
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
    {
        return board[2];
    }

    // checking in diagonal

    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];

    if (count_board('x') + count_board('o') < 9)
    {
        return 'c';
    }
    else
    {
        return 'd';
    }
}

void show()
{
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << endl;
    cout << "   " << "    |   " << "    |   " << endl;

    cout << "------------------------" << endl;

    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << endl;
    cout << "   " << "    |   " << "    |   " << endl;

    cout << "------------------------" << endl;

    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
}