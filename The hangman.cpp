#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "hangman.h"
#include <sstream>
#include <array>
using namespace std;

int main()
{
    cout << "---------------------------------------\n";
    cout << "Hello user! Do you want to play a game?\n";
    cout << "---------------------------------------\n";
    cout << "> Yes (press1) \n";
    cout << "> No  (press2) \n";
    int choice;
    do {
         cout << "Your input:";
         cin >> choice;
         if (choice == 1) {
             Menu();
             break;
         }
         else if (choice == 2) {
             cout << "okay, byebye\n";
             break;
         }
    
         else {    
             cout << "Invalid input, try again\n";
             tryAgain()==true;        
             cin.clear(); // Clear error flags  
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
             continue;
         }       

    } while (tryAgain() ==true);
   
    

}