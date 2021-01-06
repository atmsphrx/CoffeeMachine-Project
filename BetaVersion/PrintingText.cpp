#include <iostream>

using namespace std;

void printingMainMenuIfThereAreNotCups(){
    cout << "We are sorry but there are not cups left" << endl;
    cout << "5 - Service" << endl;
}

void printingMainMenu(double userBalance){
    cout << userBalance << " BYN" << endl;
    cout << "1 - Deposit money" << endl;
    cout << "2 - Espresso\t   1 BYN" << endl;
    cout << "3 - Cappuccino\t 1.5 BYN" << endl;
    cout << "4 - Latte\t 1.5 BYN" << endl;
    cout << "5 - Service" << endl;
}

void printingMenuForInputingCoins(){
    cout << endl << "Pay attention that the coffee machine doesn't give change" << endl;
    cout << "1 - 10 coins" << endl;
    cout << "2 - 20 coins" << endl;
    cout << "3 - 50 coins" << endl;
    cout << "4 - 1 BYN" << endl;
    cout << "5 - 2 BYN" << endl;
    cout << "Please deposit coins: ";
}

void printingCoffeeMakingIsComplete(double userChoice){
    cout << endl << "Here is the best ";

    if(userChoice == 2){
        cout << "Espresso";
    }else if(userChoice == 3){
        cout << "Cappuccino";
    }else{
        cout << "Latte";
    }

    cout << " in the city. Please help yourself!" << endl;
}

void printingPinMenu(){
    cout << endl << "1 - Back to Main menu" << endl;
    cout << "Please, input PIN: ";
}

void printingServiceMenu(double proceeds, int cupsInMachine){
    cout << endl << "Proceeds is " << proceeds << " BYN" << endl;
    cout << "There are " << cupsInMachine << " cups loaded" << endl;
    cout << "1 - Add cups" << endl;
    cout << "2 - Withdrawal of proceeds" << endl;
    cout << "3 - Back to Main Menu" << endl;
    cout << "Choose the operation: ";
}

void printingPinIsWrong(){
    cout << "PIN is wrong." << endl << endl;
    cout << "Please, input PIN: ";
}