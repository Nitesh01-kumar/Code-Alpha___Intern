#include <iostream>

using namespace std;

const int SIZE = 9;

// ---------- Function Declarations ----------
void printBoard(int board[SIZE][SIZE]);

bool isRowSafe(int board[SIZE][SIZE], int row, int number);
bool isColumnSafe(int board[SIZE][SIZE], int col, int number);
bool isBoxSafe(int board[SIZE][SIZE], int startRow, int startCol, int number);

bool isSafe(int board[SIZE][SIZE], int row, int col, int number);

bool findEmptyCell(int board[SIZE][SIZE], int &row, int &col);

bool solveSudoku(int board[SIZE][SIZE]);

void inputBoard(int board[SIZE][SIZE]);

void resetBoard(int board[SIZE][SIZE]);


// ---------- Print Sudoku Board ----------
void printBoard(int board[SIZE][SIZE])
{
    cout << "\n================ SUDOKU BOARD ================\n";

    for(int row = 0; row < SIZE; row++)
    {
        if(row % 3 == 0)
        {
            cout << "---------------------------------------------\n";
        }

        for(int col = 0; col < SIZE; col++)
        {
            if(col % 3 == 0)
            {
                cout << "| ";
            }

            if(board[row][col] == 0)
            {
                cout << ". ";
            }
            else
            {
                cout << board[row][col] << " ";
            }
        }

        cout << "|\n";
    }

    cout << "---------------------------------------------\n";
}


// ---------- Check Row ----------
bool isRowSafe(int board[SIZE][SIZE], int row, int number)
{
    for(int col = 0; col < SIZE; col++)
    {
        if(board[row][col] == number)
        {
            return false;
        }
    }

    return true;
}


// ---------- Check Column ----------
bool isColumnSafe(int board[SIZE][SIZE], int col, int number)
{
    for(int row = 0; row < SIZE; row++)
    {
        if(board[row][col] == number)
        {
            return false;
        }
    }

    return true;
}


// ---------- Check 3x3 Box ----------
bool isBoxSafe(int board[SIZE][SIZE], int startRow, int startCol, int number)
{
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            if(board[row + startRow][col + startCol] == number)
            {
                return false;
            }
        }
    }

    return true;
}


// ---------- Complete Safety Check ----------
bool isSafe(int board[SIZE][SIZE], int row, int col, int number)
{
    return isRowSafe(board, row, number) &&
           isColumnSafe(board, col, number) &&
           isBoxSafe(board, row - row % 3, col - col % 3, number);
}


// ---------- Find Empty Cell ----------
bool findEmptyCell(int board[SIZE][SIZE], int &row, int &col)
{
    for(row = 0; row < SIZE; row++)
    {
        for(col = 0; col < SIZE; col++)
        {
            if(board[row][col] == 0)
            {
                return true;
            }
        }
    }

    return false;
}


// ---------- Sudoku Solver Using Backtracking ----------
bool solveSudoku(int board[SIZE][SIZE])
{
    int row, col;

    // If no empty cell exists, puzzle solved
    if(!findEmptyCell(board, row, col))
    {
        return true;
    }

    // Try numbers 1 to 9
    for(int number = 1; number <= 9; number++)
    {
        if(isSafe(board, row, col, number))
        {
            board[row][col] = number;

            // Recursive call
            if(solveSudoku(board))
            {
                return true;
            }

            // Backtracking
            board[row][col] = 0;
        }
    }

    return false;
}


// ---------- User Input ----------
void inputBoard(int board[SIZE][SIZE])
{
    cout << "\nEnter Sudoku Puzzle\n";
    cout << "Use 0 for empty cells\n\n";

    for(int row = 0; row < SIZE; row++)
    {
        for(int col = 0; col < SIZE; col++)
        {
            cin >> board[row][col];
        }
    }
}


// ---------- Reset Board ----------
void resetBoard(int board[SIZE][SIZE])
{
    for(int row = 0; row < SIZE; row++)
    {
        for(int col = 0; col < SIZE; col++)
        {
            board[row][col] = 0;
        }
    }

    cout << "\nBoard Reset Successfully.\n";
}


// ---------- Main Function ----------
int main()
{
    int board[SIZE][SIZE] =
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},

        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},

        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "         SUDOKU SOLVER MENU\n";
        cout << "====================================\n";

        cout << "1. Show Sudoku Board\n";
        cout << "2. Solve Sudoku\n";
        cout << "3. Enter New Puzzle\n";
        cout << "4. Reset Board\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                printBoard(board);
                break;

            case 2:

                cout << "\nSolving Sudoku...\n";

                if(solveSudoku(board))
                {
                    cout << "\nSudoku Solved Successfully!\n";
                    printBoard(board);
                }
                else
                {
                    cout << "\nNo Solution Exists.\n";
                }

                break;

            case 3:
                inputBoard(board);
                break;

            case 4:
                resetBoard(board);
                break;

            case 0:
                cout << "\nProgram Closed.\n";
                break;

            default:
                cout << "\nInvalid Choice.\n";
        }

    } while(choice != 0);

    return 0;
}