#include <iostream>

#define TEN_COINS    0.10
#define TWENTY_COINS 0.20
#define FIFTY_COINS  0.50
#define ONE_RUBLE    1.0
#define TWO_RUBLES   2.0

#define ESPRESSO     1.0
#define CAPPUCCINO   1.5
#define LATTE        1.5

using namespace std;

double inputingCoinInMachine(double inputedCoin){
    cin >> inputedCoin;

    if(inputedCoin == 1){
        inputedCoin = TEN_COINS;
    }else if(inputedCoin == 2){
        inputedCoin = TWENTY_COINS;
    }else if(inputedCoin == 3){
        inputedCoin = FIFTY_COINS;
    }else if(inputedCoin == 4){
        inputedCoin = ONE_RUBLE;
    }else if(inputedCoin == 5){
        inputedCoin = TWO_RUBLES;
    }else{
        cout << "Unidentified coin!" << endl;

        return 0;
    }

    return inputedCoin;
}

double determineCoffeeCost(int userChoice){
    double coffeeCost;

    if(userChoice == 2){
        coffeeCost = ESPRESSO;
    }else if(userChoice == 3){
        coffeeCost = CAPPUCCINO;
    }else{
        coffeeCost = LATTE;
    }

    return coffeeCost;
}

void coffeeHasBeenTaken(){
    int coffeeTaken;

    while(true){
        cout << "Press 0 if Customer has taken his cup of coffee: ";

        cin >> coffeeTaken;

        if(coffeeTaken == 0){
            cout << endl;

            break;
        }else{
            cout << "Wrong operation!" << endl << endl;
        }
    }
}

int loadingCups(int cupsInMachine){
    int loadedCups;

    cout << endl << "How many cups are you adding?" << endl;
    cout << "Input amount: ";

    cin >> loadedCups;

    if(loadedCups < 0){
        cout << "You inputed wrong amount of cups!" << endl;
    }else{
        cupsInMachine += loadedCups;
    }

    return cupsInMachine;
}