#include <iostream>

using namespace std;

void printBoard(char (*board)[3]);
void resetBoard(char (*board)[3], char & turn);
bool checkWin(char (*board)[3], char player);
bool checkTie(char (*board)[3]);

int main(){
  char turn = 'O'; //initial set up
  char board[3][3];
  char input[6];
  bool playing = true;
  while (playing = true){ //playing game loop
    resetBoard(board, turn);
    while(!(checkWin(board,turn) && checkTie(board))){ //the game hasnt reached an end state loop
      if (turn == 'X') //swap the turns first so variables line up
	turn = 'O';
      else
	turn = 'X';
 //take in input
  //set the array
  //print the array
      }
    if (checkTie(board)) //say who won
	cout << "The game ended in a tie. You both loose!" << endl;
    else
      cout << turn << "Wins!" << endl;
  }
}
void printBoard(char (*board)[3]){

}
void resetBoard(char (*board)[3], char & turn){

}
bool checkWin(char (*board)[3], char player){

}
bool checkTie(char (*board)[3]){

}
