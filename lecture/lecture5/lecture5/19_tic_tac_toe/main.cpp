#include <iostream>
#include <cassert>
#include <fstream>
#include <stringstream>
#include <Grid.h>
using namespace std;

enum state {Empty, X, O};

const int BOARD_SIZE = 3;
const int WINNING_SIZE = 3;

// The stone used
state getStone(bool isProponent)
{
    if (isProponent)
        return X;
    else
        return O;
}

// Check if the board is valid
bool isValidBoard(const Grid<state>& board)
{
    return (board.numCols() == BOARD_SIZE && board.numRows() == BOARD_SIZE);
}

// Check if the coordinate is valid
bool isValidCoord(const Grid<state>& board, int x, int y)
{
    return board.inBounds(x, y);
}

// Check if the coordinate (x,y) has already been occupied
bool isOccupied(const Grid<state>& board, int x, int y)
{
    assert(isValidBoard(board));
    assert(isValidCoord(board, x, y));

    return board[x][y] != Empty;
}

// Place an X or O at the row and column(col) depending on
// whether the player is a proponent or not
// Returns false if
void place(Grid<state>& board, bool isProp, int x, int y)
{
    assert(isValidBoard(board));
    assert(isValidCoord(board, x, y));
    assert(!isOccupied(board, x, y));

    board[x][y] = getStone(isProp);
}

// Get the name of the player
string getName(bool isProponent)
{
    if (isProponent)
        return "Player A";
    else
        return "Player B";
}

// Read row and column from the string
bool readRowCol(const string& str, int& row, int& col)
{
    stringstream ss(str);
    ss >> row >> col;
    if (ss)
        return true;
    else
        return false;
}

// Query for inputs
bool queryInput(istream& is, bool isProponent, int& row, int& col)
{
    cout << "Turn for " << getName(isProponent) << ". Please enter the row and column:";

    string line;
    if (!getline(is, line)) {
        cout << "Read line failed!" << endl;
        return false;
    }

    if (!readRowCol(line, row, col)) {
        cout << "Please input a row and column on a single line!" << endl;
        return false;
    }

    return true;
}

// Convert the state to a character
char stateChar(state s)
{
    if (s == X) return 'X';
    if (s == O) return 'O';
    return ' ';
}

// Print the a row
void printRow(ostream& ofs, const Grid<state>& board, int x)
{
    assert (0 <= x && x < board.numRows());
    for (int y = 0; y < board.numCols(); y++) {
        ofs << "|" << stateChar(board[x][y]);
    }
    ofs << "\|" << endl;
}

// Print a separating line
void printSepLine(ostream& ofs, int n)
{
    for (int i = 0; i < n; i++)
        ofs << "+-";
    ofs << "+" << endl;
}

// Print the board
void printBoard(ostream& os, const Grid<state>& board)
{
    for (int x = 0; x < board.numRows(); x++) {
        printSepLine(os, board.numCols());
        printRow(os, board, x);
    }
    printSepLine(os, board.numCols());
}

// Generate outputs
void generateOutput(ostream& os, const Grid<state>& board,
                    bool isProponent, int row, int col)
{
    os << "--------------------------------" << endl;
    os << getName(isProponent) << " placed a stone at ("
         << row << ", " << col << ")." << endl;
    printBoard(os, board);
    os << "--------------------------------" << endl;
    os << endl;
}

// Won the diagonal line 1
bool isDiagnoalWinner1(const Grid<state>& board, state S)
{
    assert (isValidBoard(board));

    for (int x = 0; x < WINNING_SIZE; x++)
        if (board[x][x] != S)
            return false;
    return true;
}

// Won the diagonal line 2
bool isDiagnoalWinner2(const Grid<state>& board, state S)
{
    assert (isValidBoard(board));

    for (int x = 0; x < WINNING_SIZE; x++)
        if (board[x][WINNING_SIZE-x-1] != S)
            return false;
    return true;
}

// Won the horizontal lines
bool isHorizontalWinner(const Grid<state>& board, state S)
{
    assert (isValidBoard(board));

    for (int x = 0; x < WINNING_SIZE; x++) {
        bool win = true;
        for (int y = 0; y < WINNING_SIZE; y++)
            if (board[x][y] != S)
                win = false;
        if (win) return true;
    }

    return false;
}

// Won the vertical lines
bool isVerticalWinner(const Grid<state>& board, state S)
{
    assert (isValidBoard(board));

    for (int y = 0; y < WINNING_SIZE; y++) {
        bool win = true;
        for (int x = 0; x < WINNING_SIZE; x++)
            if (board[x][y] != S)
                win = false;
        if (win) return true;
    }

    return false;
}

// A player won the game
bool playerWin(const Grid<state>& board, state S)
{
    return isDiagnoalWinner1(board, S)
        || isDiagnoalWinner2(board, S)
        || isHorizontalWinner(board, S)
        || isVerticalWinner(board, S);
}

// Checking Winner
bool gameEnds(const Grid<state>& board, bool isProp)
{
    if (playerWin(board, getStone(isProp)))
        return true;
    else
        return false;
}

// Main loop for playing the game
void play(Grid<state>& board, istream& is, ostream& os)
{
    if (!isValidBoard(board)) {
        cout << "Board size is " << board.numRows() << " X "
             << board.numCols() << " instead of "
             << BOARD_SIZE << " X " << BOARD_SIZE << "." << endl;
        return;
    }

    bool isProponent = true;
    int row, col;
    while (is)
    {
        if (!queryInput(is, isProponent, row, col))
            continue;

        int x = row-1, y = col-1;
        if (!isValidCoord(board, x, y)) {
            cout << "(" << row << ", " << col << ") is not a valid coordinate!" << endl;
            continue;
        }
        if (isOccupied(board, x, y)) {
            cout << "(" << row << ", " << col << ") is already occupied!" << endl;
            continue;
        }

        place(board, isProponent, x, y);

        generateOutput(os, board, isProponent, row, col);

        if (gameEnds(board,isProponent)) {
            cout << getName(isProponent) << " has won the game! Congratulations!" << endl;
            break;
        }

        isProponent = !isProponent;
    }
}

// Initialize the board
Grid<state> initBoard()
{
    Grid<state> board(BOARD_SIZE, BOARD_SIZE);

    for (int x = 0; x < board.numRows(); x++)
    for (int y = 0; y < board.numCols(); y++)
        board[x][y] = Empty;

    return board;
}

int main()
{
    /*string filename = "board.txt";
    ofstream ofs;
    ofs.open(filename.c_str());
    if (!ofs) {
        cout << "Cannot open the file: " << filename << endl;
        return -1;
    }
    */

    Grid<state> board = initBoard();


    cout << "Game begins!" << endl;
    play(board, cin, cout);
    cout << "Game ends!" << endl;

    //ofs.close();
    return 0;
}
