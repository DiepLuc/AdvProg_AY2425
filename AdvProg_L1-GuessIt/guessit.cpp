#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;


/***
    Args:

    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber() {
    return rand() % 100 + 1;
}


/***
    Args:

    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess() {
    int number ;
    cout << endl <<  "Enter your number: ";
    cin >> number;
    return number;
}

/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
string getAnswer(int number, int randomNumber) {
    string answer;
    if	(number	>	randomNumber){
				answer ="Your number is too	big.";
    }else if(number	<	randomNumber){
				answer ="Your number is too small."	;
    }else{
				answer ="Congratulation! You win.";
    }
    return answer;
}


/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
bool checkSuccess(string answer) {
    if(answer =="Congratulation! You win."){
        return true;
    } else return false;

}


/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued) {
    if (isContinued =='y'){
        return true;
    } else return false;
}


/***
    Args:

    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion() {
    char isContinued;
    cout << "Enter your choice: ";
    cin >> isContinued;
    return isContinued;
}


void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    string answer;

    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int main() {
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
