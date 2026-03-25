#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int secretNumber, guess, attempts = 0;

   
    srand(time(0));
    secretNumber = rand() % 100 + 1;

    cout << "...... Number Guessing Game ......" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl << endl;

   
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } 
        else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } 
        else {
            cout << "\ncorrect" << endl;
            cout << "You guessed the correct number in "
                 << attempts << " attempts." << endl;
        }

    } while (guess != secretNumber);
  
    cout << "--------------" << endl;

    return 0;
}
