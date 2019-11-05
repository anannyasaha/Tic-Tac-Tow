//TIC-TAC-TOE [game]

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;


const int SIZE = 3;

void displayBoard(string** b);//passing the array to the functions
bool userFirst();
bool currentPlayerWon(string** b, string symbol);//passing the array to the functions
//void generateComputerMove2(string board[][SIZE],int& row,int& col);
void generateComputerMove(string** board,int& row,int& col);//passing the array to the functions
int main() {
int count=0;
	//construct board

	string** board; //declaring the pointer that points to an array of pointers
	board=new string*[SIZE]; //the board points to an array of size 3
	for(int i=0;i<SIZE;i++){
		board[i]=new string[SIZE];//each element of the array points to another array
	}


	int position_id = 1;
	for (int i=0; i< SIZE; i++) {
		for (int j=0; j < SIZE; j++) {
			board[i][j] = to_string(position_id);
			/*  stringstream ss;
			   ss << position_id;
			   board[i][j] = ss.str();
			 */position_id++;
		}
	}

	//Initial game output
	cout << "Welcome to Tic-Tac-Toe" << endl;

	bool userTurn = userFirst();
	if (userTurn == true) {
		cout << "Player goes first!" << endl;
	} else {
		cout << "Computer goes first!" << endl;

	}

	//Loop for turn taking in game
	int positionsRemaining = SIZE * SIZE;
	bool userWon = false;
	bool computerWon = false;

	while ((positionsRemaining > 0)
	       && (!userWon) && (!computerWon)) {
		displayBoard(board);

		//User's turn
		if (userTurn) {
			bool validMove = false;
			while (!validMove) {
				int position_id;
				cout << "Enter a position: ";
				cin >> position_id;
				if ((position_id <= (SIZE*SIZE)) && (position_id > 0))
				{
					int row = (position_id-1)/SIZE;
					int col = (position_id-1)%SIZE;
					//cout << "row = " << row << " col = " << col << endl;
					if ((board[row][col] != "X")
					    && (board[row][col] != "O")) {
						board[row][col] = "X";
						validMove = true;
					}
					else
					{
						cout << "Position already used. Try again." << endl;
					}

				}
				else
				{
					cout << "Position invalid. Try again." << endl;
				}
			}
			positionsRemaining--;
			userWon = currentPlayerWon(board, "X");
			userTurn = false;
		}

		//Computer's turn
		else {
		int row,col;
		generateComputerMove(board, row, col);

		board[row][col]="O";
    positionsRemaining--;
		computerWon = currentPlayerWon(board, "O");
		userTurn = true;
		}

}

	//Display game result
	displayBoard(board);
	if (userWon) {
		cout << "Congratulations! You have won!" << endl;
	} else if (computerWon) {
		cout << "The computer has won. Try again." << endl;
	} else {
		cout << "Out of moves. Try again." << endl;
	}
	for(int i=0;i<SIZE;i++){
		delete[] board[i]; //deleting the every elements of the board array
	}
		delete[] board;//deleting the pointer board which points to an array
		return 0;
}


void displayBoard(string** b) {
	cout << "Tic-tac-toe board:" << endl << endl;
	for (int i=0; i< SIZE; i++) {
		for (int j=0; j < SIZE; j++) {
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

bool userFirst() {
	//set seed for random number generation
	srand(time(NULL));

	//generate a random number
	//0 for computer
	//1 for user
	int num = rand()%2;
	if (num == 0) {
		return false;
	}
	return true;
}

//Return true if player/computer with symbol (X or O) has won
bool currentPlayerWon(string** b, string symbol) {
	//Horizontal case
	//Loop through each row
	for (int i=0; i < SIZE; i++) {
		bool rowWinDetected = true;
		//Check all positions in row and see if they are the same symbol
		for (int j = 0; j < SIZE; j++) {
			if (b[i][j] != symbol) {
				rowWinDetected = false;
			}
		}
		if (rowWinDetected) {
			return true;
		}
	}

	//Vertical case
	//Loop through each column
	for (int i=0; i < SIZE; i++) {
		bool colWinDetected = true;
		//Check all positions in column and see if they are the same symbol
		for (int j = 0; j < SIZE; j++) {
			if (b[j][i] != symbol) {
				colWinDetected = false;
			}
		}
		if (colWinDetected) {
			return true;
		}
	}

	//Diagonal case #1
	bool diagonal1WinDetected = true;
	for (int i=0; i < SIZE; i++) {
		if (b[i][i] != symbol) {
			diagonal1WinDetected = false;
		}
	}
	if (diagonal1WinDetected) {
		return true;
	}

	//Diagonal case #2
	bool diagonal2WinDetected = true;
	for (int i=0; i < SIZE; i++) {
		if (b[(SIZE-1)-i][i] != symbol) {
			diagonal2WinDetected = false;
		}
	}
	if (diagonal2WinDetected) {
		return true;
	}

	//otherwise win not diagonal2WinDetected
	return false;

}

void generateComputerMove(string** board,int& row,int& col)
{	bool validMove = false;
	int ctr1=0;   //three counters for three cases
	int ctr2=0;
	int ctr3=0;
	int rowno1=0;  //three row numbers to keep track for rows in three cases
	int colno1=0;  //three col numbers to keep track for cols in three cases
	int rowno2=0;
	int colno2=0;
	int rowno3=0;
	int colno3=0;
	 for (int i=0; i < SIZE; i++) {
	   for (int j = 0; j < SIZE-1; j++) {
				if (board[i][j] == "X") {
					ctr1++;
				rowno1=i;
			colno1=j+1;}}}
			for (int j=0; j < SIZE; j++) {
			 for (int i = 0; i < SIZE-1; i++) {
					if (board[i][j] == "X") {
						ctr2++;
					rowno2=i+1;
				colno2=j;}}}
				for(int i=0;i<SIZE-1;i++){
				if(board[i][i]=="X"){
					ctr3++;
					rowno3=i+1;
					colno3=i+1;}}
					if (ctr1==2&&board[rowno1][colno1]!="X"&&board[rowno1][colno1]!="O"){
						row=rowno1;
						col=colno1;
           //if it sees there is two similar symbol horizontally then it will
					 // give its turn in the third place
 				}

				  else if(ctr2==2&&board[rowno2][colno2]!="X"&&board[rowno2][colno2]!="O"){
					row=rowno2;
					col=colno2;
					//if it sees there is two similar symbol verticallly then it will
					//give its turn in the third place
				}
			else if(ctr3==2&&board[rowno3][colno3]!="X"&&board[rowno3][colno3]!="O"){
				 row=rowno3;
				 col=colno3;
				 //if it sees there is two similar symbol diagonally then it will give its turn in the third place
			 }
					else
				{	 //if the computer plays at first or any of the above conditions doesnot work
					bool validMove = false;
          while (!validMove) {
          row = rand()%SIZE;
          col = rand()%SIZE;
          if ((board [row][col] != "X")
          && (board[row][col] != "O")) {

          validMove = true;	}
				}
			}
		}
