This C++ program is a Tic Tac Toe game that allows either:
Two human players to play against each other, or A single human player to play against the computer (AI) using the Minimax algorithm.
Feature &	Prpose
2D array (space[3][3])	Represents the game board with 9 positions.
Functions	Divided into roles like drawing the board, player move, AI logic, and win checking.
Minimax Algorithm	For the AI to make the best move in Tic Tac Toe (used in findBestMove() and minimax()).
Recursion	Used in minimax() and also in functionTwo() for handling invalid input.
Control structures	if, else, for, while loops to control flow.
Standard Input/Output	cin, cout to interact with users.
String handling	For getting player names and using AI name if empty.
Game logic	Checks for win, draw, and valid moves.
🛠 Functions Used

Function Name	What It Does

functionOne()	Draws the Tic Tac Toe board.
functionTwo()	Manages player or AI turns, inputs, and updates board.
functionThree()	Checks if the game is over (win or tie).
checkWin()	Checks if a player ('x' or '0') has won.
isMovesLeft()	Checks if there are any empty spots left on the board.
minimax()	Core AI logic using recursion to find the best possible move.
findBestMove()	Calls minimax() on all valid spots to pick the optimal move for the computer.



---

👾 AI Part: Minimax Algorithm

Tries all possible future moves.

Evaluates them recursively.

Chooses the move that maximizes its chances of winning and minimizes the player's chance.

Uses depth to prefer faster wins or slower losses.


