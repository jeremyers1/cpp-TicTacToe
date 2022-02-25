#include <iostream>
#include <string>
#include <vector>
#include <ctime>

// Welcome to my Tic Tac Toe program
// Global Variable Declarations
std::vector<char> boardrow1 = {' ','a',' ','|',' ','b',' ','|',' ','c',' ','\n'};
std::vector<char> boardrow2 = {' ','d',' ','|',' ','e',' ','|',' ','f',' ','\n'};
std::vector<char> boardrow3 = {' ','g',' ','|',' ','h',' ','|',' ','i',' ','\n'};
std::string boardrowX = "---+---+---\n";
std::string player1 = "Play1", player2 = "Play2";
std::string first = "Elon", second = "Musk";
char move;
int moves = 0;
bool choice = false, gameover = false;
std::string winner;

// function declarations 
void intro();
void gameboard (std::vector<char> boardrow1, std::vector<char> boardrow2, std::vector<char> boardrow3, std::string boardrowX);
void checkwinner();
void announcewinner(char XO);


int main () {
 intro();
 /* Removed for texting purposes
  std::cout << "Greetings! First, let's get your names!\nPlayer 1, what is your name?\n";
  std::cin >> player1;
  std::cout << "Thanks, " << player1 << "!\nNow Player 2, what is your name?\n";
  std::cin >> player2;
  std::cout << "Awesome, " << player2 << "!\nNow let's play a game of Tic-Tac-Toe!\n\nNow let's find out who goes first!\n\n";
*/
  // get order of players
  srand(time(0));
  if (rand() % 2 == 0) {
    first = player1;
    second = player2;
  }
  else {
    first = player2;
    second = player1;
  }
  std::cout << "The computer has randomly decided that " << first << " will go first as the Xs and " << second << " will go second as the Os!\n\n"; 

  // provide instruction and initial board layout
  std::cout << "This is what the gameboard looks like:\n\n";
 gameboard(boardrow1, boardrow2, boardrow3, boardrowX);
  std::cout << "When it is your turn, enter the letter of the space you want to go in.\n\n";

while (gameover == false) {
// first turn
std::cout << "Ok, " << first << " it is your turn.\n";
//check to make sure it is a valid move
choice = false;
while (choice == false) {
std::cout << "Enter the letter of the space you want to go in.\n\nHere is the current gameboard for reference:\n\n";
gameboard(boardrow1, boardrow2, boardrow3, boardrowX);
std::cin >> move;
for (int i=0; i < boardrow1.size(); i++) {
     if (move == boardrow1[i] && move != '|' && move != ' ') {
       boardrow1[i] = 'X';
       moves++;
       choice = true;
     }
  }
for (int i=0; i < boardrow2.size(); i++) {
     if (move == boardrow2[i] && move != '|' && move != ' ') {
       boardrow2[i] = 'X';
       moves++;
       choice = true;
     }
  }
for (int i=0; i < boardrow3.size(); i++) {
     if (move == boardrow3[i] && move != '|' && move != ' ' ) {
       boardrow3[i] = 'X';
       moves++;
       choice = true;
     }
  }
  if (choice == false) {
  std::cout << "---->>>>That is not a valid choice.\n Please try again.<<<<----\n\n";
  }
} // end first turn while

// check to see if there is a winner yet
checkwinner();

// second turn
if (gameover == false) {
std::cout << "Ok, " << second << " it is your turn.\n";
//check to make sure it is a valid move
choice = false;
while (choice == false) {
std::cout << "Enter the letter of the space you want to go in.\n\nHere is the current gameboard for reference:\n\n";
gameboard(boardrow1, boardrow2, boardrow3, boardrowX);
std::cin >> move;
for (int i=0; i < boardrow1.size(); i++) {
     if (move == boardrow1[i] && move != '|' && move != ' ') {
       boardrow1[i] = 'O';
       moves++;
       choice = true;
     }
  }
for (int i=0; i < boardrow2.size(); i++) {
     if (move == boardrow2[i] && move != '|' && move != ' ') {
       boardrow2[i] = 'O';
       moves++;
       choice = true;
     }
  }
for (int i=0; i < boardrow3.size(); i++) {
     if (move == boardrow3[i] && move != '|' && move != ' ' ) {
       boardrow3[i] = 'O';
       moves++;
       choice = true;
     }
  }
  if (choice == false) {
  std::cout << "---->>>>That is not a valid choice.\n Please try again.<<<<----\n\n";
  }
} // end second turn while
} // end if

// check to see if there is a winner yet
checkwinner();

} // end gameover while
} // end main



// functions

void intro() {
  std::cout << "-------------------------------\nWelcome to the World Championships\nof Tic-Tac-Toe\n-------------------------------\n";
}


void gameboard (std::vector<char> boardrow1, std::vector<char> boardrow2, std::vector<char> boardrow3, std::string boardrowX) {
  for (int i=0; i < boardrow1.size(); i++) {
     std::cout << boardrow1[i];
  }
  std::cout << boardrowX;
  for (int i=0; i < boardrow2.size(); i++) {
     std::cout << boardrow2[i];
  }
  std::cout << boardrowX;
  for (int i=0; i < boardrow3.size(); i++) {
     std::cout << boardrow3[i];
  }
}

void checkwinner() {
  std::cout << "Here is the current gameboard:\n\n";
gameboard(boardrow1, boardrow2, boardrow3, boardrowX);
//check top row
  if (boardrow1[1] == boardrow1[5] && boardrow1[1] == boardrow1[9]) {
  announcewinner(boardrow1[1]);
  }
  //check middle row
  else if (boardrow2[1] == boardrow2[5] && boardrow2[1] == boardrow2[9]) {
  announcewinner(boardrow2[1]);
  }
  //check bottom row
  else if (boardrow3[1] == boardrow3[5] && boardrow3[1] == boardrow3[9]) {
  announcewinner(boardrow3[1]);
  }
  //check left column
  else if (boardrow1[1] == boardrow2[1] && boardrow1[1] == boardrow3[1]) {
  announcewinner(boardrow1[1]);
  }
  //check middle column
  else if (boardrow1[5] == boardrow2[5] && boardrow1[5] == boardrow3[5]) {
  announcewinner(boardrow1[5]);
  }
  //check right column
  else if (boardrow1[9] == boardrow2[9] && boardrow1[9] == boardrow3[9]) {
  announcewinner(boardrow1[9]);
  }
  //check \ diagonal
  else if (boardrow1[1] == boardrow2[5] && boardrow1[1] == boardrow3[9]) {
  announcewinner(boardrow1[1]);
  }
  //check / diagonal
  else if (boardrow1[9] == boardrow2[5] && boardrow1[9] == boardrow3[1]) {
  announcewinner(boardrow1[9]);
  }
  else if (moves == 9) {
    std::cout << "Cats Eye! It's a draw! Nobody won.\n";
    gameover = true;
  }
}

void announcewinner(char XO) {
  if (XO == 'X') {
    std::cout << first << " is the winner!\n\n";
    gameover = true;
  }
  else {
    std::cout << second << " is the winner!\n\n";
    gameover = true;
  }
}
