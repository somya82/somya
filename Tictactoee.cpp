#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

char space[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
int row, column;
char token = 'x';
bool tie = false;
string n1 = "", n2 = "";
bool vsAI = false;

void functionOne() {
    cout << "   |   |    \n";
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << "  \n";
    cout << "___|___|___  \n";
    cout << "   |   |      \n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << "  \n";
    cout << "___|___|___   \n";
    cout << "   |   |       \n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << "  \n";
    cout << "   |   |       \n";
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

bool isMovesLeft(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'x' && board[i][j] != '0')
                return true;
    return false;
}

int minimax(char board[3][3], int depth, bool isMax) {
    if (checkWin(board, '0')) return 10 - depth;
    if (checkWin(board, 'x')) return depth - 10;
    if (!isMovesLeft(board)) return 0;

    int best = isMax ? -1000 : 1000;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'x' && board[i][j] != '0') {
                char backup = board[i][j];
                board[i][j] = isMax ? '0' : 'x';
                int score = minimax(board, depth + 1, !isMax);
                board[i][j] = backup;

                best = isMax ? max(best, score) : min(best, score);
            }
        }
    }

    return best;
}

pair<int, int> findBestMove() {
    int bestScore = -1000;
    pair<int, int> bestMove = {-1, -1};

    char tempBoard[3][3];
    copy(&space[0][0], &space[0][0] + 9, &tempBoard[0][0]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tempBoard[i][j] != 'x' && tempBoard[i][j] != '0') {
                char backup = tempBoard[i][j];
                tempBoard[i][j] = '0';

                int score = minimax(tempBoard, 0, false);
                tempBoard[i][j] = backup;

                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {i, j};
                }
            }
        }
    }

    return bestMove;
}

bool functionThree() {
    if (checkWin(space, 'x') || checkWin(space, '0'))
        return true;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (space[i][j] != 'x' && space[i][j] != '0')
                return false;

    tie = true;
    return true;
}

void functionTwo() {
    int digit;
    if (vsAI && token == '0') {
        cout << "Computer is making a move...\n";
        pair<int, int> aiMove = findBestMove();
        row = aiMove.first;
        column = aiMove.second;
    } else {
        if (token == 'x') {
            cout << n1 << " please enter (1-9): ";
        } else {
            cout << n2 << " please enter (1-9): ";
        }
        cin >> digit;

        if (digit == 1) { row = 0; column = 0; }
        else if (digit == 2) { row = 0; column = 1; }
        else if (digit == 3) { row = 0; column = 2; }
        else if (digit == 4) { row = 1; column = 0; }
        else if (digit == 5) { row = 1; column = 1; }
        else if (digit == 6) { row = 1; column = 2; }
        else if (digit == 7) { row = 2; column = 0; }
        else if (digit == 8) { row = 2; column = 1; }
        else if (digit == 9) { row = 2; column = 2; }
        else {
            cout << "Invalid !!!" << endl;
            functionTwo();
            return;
        }
    }

    if (space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = token;
        token = (token == 'x') ? '0' : 'x';
    } else {
        cout << "That space is already taken!" << endl;
        functionTwo();
        return;
    }

    functionOne();
}

int main() {
    cout << "Enter the name of the first player: \n";
    getline(cin, n1);
    cout << "Enter the name of the second player (or press ENTER to play with AI): \n";
    getline(cin, n2);
    if (n2.empty()) {
        vsAI = true;
        n2 = "Computer";
    }
    cout << "Welcome to the Tic Tac Toe game!\n";
    cout << n1 << " is player 1 and will play as 'x'\n";
    cout << n2 << " is player 2 and will play as '0'\n";

    functionOne();

    while (true) {
        functionTwo();
        if (functionThree()) {
            if (tie)
                cout << "It's a draw!" << endl;
            else if (checkWin(space, 'x'))
                cout << n1 << " Wins!" << endl;
            else if (checkWin(space, '0'))
                cout << n2 << " Wins!" << endl;
            break;
        }
    }

    return 0;
}
