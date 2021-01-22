#include <iostream>
#include "PrintingText.h"
#include "Functionality.h"

#define PIN 8999

using namespace std;

int main(){
    double userBalance = 0.0, proceeds = 0.0;
    int userChoice, cupsInMachine = 7;

    while(true){
        if(cupsInMachine == 0){
            printingMainMenuIfThereAreNotCups();
        }else{
            printingMainMenu(userBalance);
        }

        cout << "Dear Customer, make your choice: ";

        cin >> userChoice;

        if(userChoice == 1 && cupsInMachine != 0){
            double inputedCoin = 0.0;

            printingMenuForInputingCoins();

            inputedCoin = inputingCoinInMachine(inputedCoin);
            userBalance += inputedCoin;
            proceeds += inputedCoin;

            cout << endl;
        }else if((userChoice >= 2 && userChoice <= 4) && cupsInMachine != 0){
            double costOfChosenCoffee = determineCoffeeCost(userChoice);

            if(userBalance >= costOfChosenCoffee){
                printingCoffeeMakingIsComplete(userChoice);

                userBalance -= costOfChosenCoffee;
                cupsInMachine--;

                cout << endl;

                coffeeHasBeenTaken();

            }else{
                double inputedCoin = 0.0;

                printingMenuForInputingCoins();

                inputedCoin = inputingCoinInMachine(inputedCoin);
                userBalance += inputedCoin;
                proceeds += inputedCoin;

                cout << endl;
            }
        }else if(userChoice == 5){
            int inputedPin, wrongPinCounter = 0;

            printingPinMenu();

            while(true){
                cin >> inputedPin;

                if(inputedPin == 1 && wrongPinCounter == 0){
                    cout << endl;

                    break;
                }else if(inputedPin != PIN){
                    wrongPinCounter++;

                    if(wrongPinCounter == 3){
                        cout << endl << "The machine is blocked!";

                        return -1;
                    }

                    printingPinIsWrong();
                }else{
                    while(true){
                        printingServiceMenu(proceeds, cupsInMachine);

                        int serviceMenuChoice;

                        cin >> serviceMenuChoice;

                        if(serviceMenuChoice == 1){
                            cupsInMachine = loadingCups(cupsInMachine);
                        }else if(serviceMenuChoice == 2){
                            cout << endl << proceeds << " BYN were given away" << endl;

                            userBalance = 0.0;
                            proceeds = 0.0;
                        }else if (serviceMenuChoice == 3){
                            cout << endl;

                            break;
                        }else{
                            cout << "You inputed wrong operation. Please, try again!" << endl ;
                        }
                    }
                    break;
                }
            }
        }else{
            cout << "You inputed wrong operation. Please, try again!" << endl << endl;
        }
    }
}
