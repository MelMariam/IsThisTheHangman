#include <iostream>
#include "hangman.h"
#include <array>
#include <string>
#include <exception>
#include <random>
#include <cctype>
using namespace std;

bool tryAgain() {
    return true;
}
void check_input(int ch) {
    do {
        ch;
        if (ch == 1) play();
        else if (ch == 2) { cout << "Okay, bye\n";  exit(-1); }
        else {
            cout << "\nInvalid input, try again\n";
            tryAgain() == true;
            cin.clear(); // Clear error flags  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
       
    } while (tryAgain() == true);
   
}  
void Menu() {
        cout << "=======================\n";
        cout << "         Hangman       \n";
        cout << "=======================\n";
        cout << "> START      (press 1) \n";
        cout << "> How To Play(press 2) \n";
        cout << "> EXIT       (press 3) \n";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1: play(); break;

        case 2:
            cout << "Cmooon, who doesn't know how to play the hangman?\n";
            cout << "...\n";
            cout << "Okay, fine!\n";
            cout << "Instructions: Save your friend from being hanged by guessing the letters in the codeword.\n";
            cout << "So, are we playing?\n 1- yes, 2- No: ";
            cin >> choice;
            check_input(choice);
            

        case 3:
            cout << "Bye, Thank You for playing! \n";
            break;
        default:
            cout << "-_- you have to press 1,2,3 or 4!\n";
            cin >> choice;
            check_input(choice);
            break;
        }
}
void  play() {

    array <string, 3> words_library = { "apple", "banana", "cherry" };
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, words_library.size() - 1);
    string code_word = words_library[dis(gen)];
    string answer;
    for (int i = 0; i < code_word.length(); ++i) {
        answer += '_'; // Use underscores or any other placeholder character you prefer
    }
   
    //counter for wrong guesses
    int wrong_guesses=0;
    //size of the word
    int charNumber = code_word.length();
    //
    char guessedLetter;
    bool guessed = false;
    cout << "Hi there, you know the rules so let's start\n";
    cout << "The word you have to guess has " << charNumber << " characters\n";
    cout << "This is how your man looks for now :) GOOD LUCK! \n";
    cout << "  +---+ \n";
    cout << "  |   | \n";
    cout << "      | \n";
    cout << "      | \n";
    cout << "      | \n";
    cout << "      | \n";
    cout << " ========= \n";
    

    //___________________________________________________________________________
    while (answer != code_word && wrong_guesses < charNumber)
    {
        for (int i = 0; i < answer.length(); i++)
        {
            cout << answer[i] << " ";
        }
        cout << "\n\nPlease enter your guess: ";
        cin >> guessedLetter;
        if (isalpha(guessedLetter)) {
            for (int i = 0; i < code_word.length(); i++)
            {
                if (guessedLetter == code_word[i])
                {
                    answer[i] = guessedLetter;
                    guessed = true;
                }
                
            }
            if (guessed)
            {
                cout << "\nCorrect!\n";
            }
            else
            {
                cout << "\nIncorrect! Man is hanging! \n\n";
                wrong_guesses++;
                draw_hangman(wrong_guesses);
            }
           
            guessed = false;
        }
        else {
            cout << "Invalid input \n";
        }
    }
//____________________________________________________________________
  if (answer == code_word)
  { 
    cout << "Code word was:";
    for (int i = 0; i < answer.length(); i++) {
          cout << answer[i] << " ";
    }
    int ch;
    cout << "Hooray! You won!\n\n";
    cout << "Try again? yes - 1, no -2\n\n";  
    cin >> ch;
    check_input(ch);
  }
  else{
     int ch;
     cout << "On no! The man is hanged!\n\n";
     cout << "Try again? yes - 1, no - 2\n";
     cin >> ch;
     check_input(ch);
  }

}
void draw_hangman(int wrong_guesses) {
 if (wrong_guesses == 1)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
    }
    else if (wrong_guesses == 2)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << "  |   | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
    }
    else if (wrong_guesses == 3)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << " /|   | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
    }
    else if (wrong_guesses == 4)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << " /|\\  | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
    }
    else if (wrong_guesses == 5)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << " /|\\  | \n";
        cout << " /    | \n";
        cout << "      | \n";
        cout << " ========= \n";
    }
    else if (wrong_guesses == 6)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << " /|\\  | \n";
        cout << " / \\  | \n";
        cout << "      | \n";
        cout << " ========= \n";
    }

}

