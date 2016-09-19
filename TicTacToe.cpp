/*Tic Tac Toe, September 10 2016, Josh Howell"
  A command Line tic tac toe game */

#include <iostream>
#include <cstring>

using namespace std;
//they do exactly what their names are
void printBoard(char (*board)[3]);
void resetBoard(char (*board)[3], char & turn);
bool checkWin(char (*board)[3], char player);
bool checkTie(char (*board)[3]);

int main(){
  char turn = 'O'; //initial set up
  char board[3][3];
  char input[6];
  bool playing = true;
  while (playing == true){ //playing game loop
    resetBoard(board, turn);
    printBoard(board);
    while(!(checkWin(board,turn) || checkTie(board))){ //the game hasnt reached an end state loop
      if (turn == 'X') //swap the turns first so variables line up
	turn = 'O';
      else
	turn = 'X';
      bool moved = false;
      while (moved == false){
	cin >> input;//take in the input and make sure its good
	if (strlen(input) != 2){
	  cout << "Enter a letter then a number" << endl;
	}
	else if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c'){
	  cout << "The first symbol needs to be a letter" << endl;
	}
	else if (input[1] != '1' && input[1] != '2' && input[1] != '3'){
	  cout << "The second symbol needs to be a number" << endl;
	}
	else if (board[input[0]-'a'][input[1]-'1'] == ' '){
	  board[input[0]-'a'][input[1]-'1'] = turn;
	  moved = true;
	  printBoard(board);
	}
	else{
	  cout << "That space is taken" << endl;	  
	}
      }
    }
    if (checkTie(board)) //say who won
      cout << "The game ended in a tie. You both loose!" << endl;
    else
      cout << turn << " Wins!" << endl;
    cout << "Do you want to play again? (y/n)" << endl;
    cin >> input;
    if(strcmp(input,"y")){ //ask if they want to play agian
      playing = false;
    }
  }
}
void printBoard(char (*board)[3]){
  cout << " \tA\tB\tC" << endl;
  cout << "1\t" << board[0][0] << "\t" << board[1][0] << "\t" << board[2][0] << endl;
  cout << "2\t" << board[0][1] << "\t" << board[1][1] << "\t" << board[2][1] << endl;
  cout << "3\t" << board[0][2] << "\t" << board[1][2] << "\t" << board[2][2] << endl;
}
void resetBoard(char (*board)[3], char & turn){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      board[i][j] = ' ';
    }
  }
  turn = 'O';
}
bool checkWin(char (*board)[3], char player){
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player){
    return true;
  }
  for (int count = 0; count < 3; count++) {
    if (board[0][count] == player && board[1][count] == player && board[2][count] == player){
      return true;
    }
  }
  for (int count = 0; count < 3; count++) {
    if (board[count][0] == player && board[count][1] == player && board[count][2] == player){
      return true;
    }
  }
  return false;
}
bool checkTie(char (*board)[3]){
  bool tie = true; 
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (board[i][j] == ' ')
	tie = false;
    }
  }
  return tie;
}
