#include <iostream>
#include<conio.h>
#include <windows.h>
#define N 9

using namespace std;

bool checkSafety(int puzzle[N][N], int row, int col, int num); // bool true return 1, false return 0
bool Solve(int puzzle[N][N], int row, int col);
void printSudoku(int puzzle[N][N]);

int main()
{
    system("title Sudoku Solver in C++");
    system("cls");
    printf(
        "\t\t ____            _       _            ____        _\n"
        "\t\t/ ___| _   _  __| | ___ | | ___   _  / ___|  ___ | |_   _____ _ __\n"
        "\t\t\\___ \\| | | |/ _` |/ _ \\| |/ / | | | \\___ \\ / _ \\| \\ \\ / / _ \\ '__|\n"
        "\t\t ___) | |_| | (_| | (_) |   <| |_| |  ___) | (_) | |\\ V /  __/ |\n"
        "\t\t|____/ \\__,_|\\__,_|\\___/|_|\\_\\\\__,_| |____/ \\___/|_| \\_/ \\___|_|\n");
    // int puzzle[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
    //                     {5, 2, 0, 0, 0, 0, 0, 0, 0},
    //                     {0, 8, 7, 0, 0, 0, 0, 3, 1},
    //                     {0, 0, 3, 0, 1, 0, 0, 8, 0},
    //                     {9, 0, 0, 8, 6, 3, 0, 0, 5},
    //                     {0, 5, 0, 0, 9, 0, 6, 0, 0},
    //                     {1, 3, 0, 0, 0, 0, 2, 5, 0},
    //                     {0, 0, 0, 0, 0, 0, 0, 7, 4},
    //                     {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    int puzzle[N][N];
    cout << "\n\nEnter the Sudoku Puzzle (Enter '0' in empty places): \n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> puzzle[i][j];

    if(Solve(puzzle, 0, 0))
    {
        printSudoku(puzzle);
    }
    else
    {
        cout << "No Solution Exists!" << endl;
    }


    return 0;
}

bool Solve(int puzzle[N][N], int row, int col)
{
    if (row == N - 1 && col == N)
        return true;

    if(col == N)
    {
        col = 0;
        row++;
    }

    if(puzzle[row][col] > 0)
        return Solve(puzzle, row, col + 1);
    
    for (int num = 1; num < 10; num++)
    {
        if(checkSafety(puzzle, row, col, num))
        {
            puzzle[row][col] = num;
            if(Solve(puzzle, row, col + 1))
                return true;
        }
        puzzle[row][col] = 0;
    }
    return false;    
}

bool checkSafety(int puzzle[N][N], int row, int col, int num)
{
    for(int x = 0; x < N; x++)
    {
        if(puzzle[row][x] == num)
            return false;
    }

    for(int x = 0; x < N; x++)
    {
        if(puzzle[x][col] == num)
            return false;
    }

    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(puzzle[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

void printSudoku(int puzzle[N][N])
{
    system("cls");

    printf(
        "\t\t ____            _       _            ____        _\n"
        "\t\t/ ___| _   _  __| | ___ | | ___   _  / ___|  ___ | |_   _____ _ __\n"
        "\t\t\\___ \\| | | |/ _` |/ _ \\| |/ / | | | \\___ \\ / _ \\| \\ \\ / / _ \\ '__|\n"
        "\t\t ___) | |_| | (_| | (_) |   <| |_| |  ___) | (_) | |\\ V /  __/ |\n"
        "\t\t|____/ \\__,_|\\__,_|\\___/|_|\\_\\\\__,_| |____/ \\___/|_| \\_/ \\___|_|\n");

        cout << "\n\n\tThe Solution of the Entered Sudoku is: \n\n";

    for (int row = 0; row < N; row++)
    {
        cout << "\t";
        for (int col = 0; col < N; col++)
        {
            cout << puzzle[row][col] << " ";
            if (col == 2 || col == 5)
                cout << "| ";
        }
        cout << endl;
        if (row == 2 || row == 5)
            cout << "\t------+-------+------\n";
    }
    
    cout << "\n\n\tPress any key to exit." << endl;
    getch();
}