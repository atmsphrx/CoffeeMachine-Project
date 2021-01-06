#include <iostream>

#define PIN 		 9999
#define ESPRESSO     1.0
#define CAPPUCCINO   1.5
#define LATTE        1.5

using namespace std;

int cups = 7;
double proceeds = 0.0;

double inputingMoneyInMachine(double balance);
double makingCoffee(double balance, double coffeeCost, int userChoice);
void coffeeHasBeenTaken();
double pinMenu(double balance);

int main() {
	double balance = 0.0;
	
	while(true){
		if(cups == 0){
			cout << "We are sorry but there are not cups left" << endl;
			cout << "5 - Service" << endl;
		}else{
			cout << balance << " BYN" << endl;
			cout << "1 - Deposit money" << endl;
			cout << "2 - Espresso\t   1 BYN" << endl;
			cout << "3 - Cappuccino\t 1.5 BYN" << endl;
			cout << "4 - Latte\t 1.5 BYN" << endl;
			cout << "5 - Service" << endl;
		}
		
		int userChoice;
		
		cout << "Dear Customer, make your choice: ";
		cin >> userChoice;
			
		if(userChoice == 1 && cups!= 0){
			balance = inputingMoneyInMachine(balance);
		}else if(userChoice == 2 && cups!= 0){
			if(balance >= ESPRESSO){
				balance = makingCoffee(balance, ESPRESSO, userChoice);
			}else{
				balance = inputingMoneyInMachine(balance);
			}
		}else if(userChoice == 3 && cups!= 0){
			if(balance >= CAPPUCCINO){
				balance = makingCoffee(balance, CAPPUCCINO, userChoice);
			}else{
				balance = inputingMoneyInMachine(balance);
			}
		}else if(userChoice == 4 && cups!= 0){
			if(balance >= LATTE){
				balance = makingCoffee(balance, LATTE, userChoice);
			}else{
				balance = inputingMoneyInMachine(balance);
			}
		}else if(userChoice == 5){
			balance = pinMenu(balance);
			
			if(balance == -1){
				return -1;
			}
		}else{
			cout << "Wrong operation!" << endl << endl;
		}
	}
		
	return 0;
}

double inputingMoneyInMachine(double balance){
	double inputingMoney;
	
	cout << endl << "Pay attention that the coffee machine doesn't give change" << endl;
	cout << "1 - 10 coins" << endl;
	cout << "2 - 20 coins" << endl;
	cout << "3 - 50 coins" << endl;
	cout << "4 - 1 BYN" << endl;
	cout << "5 - 2 BYN" << endl;
	cout << "Please deposit coins: ";
	cin >> inputingMoney;
	
	if(inputingMoney == 1){
		balance += 0.1;
		proceeds += 0.1;
	}else if(inputingMoney == 2){
		balance += 0.2;
		proceeds += 0.2;
	}else if(inputingMoney == 3){
		balance += 0.5;
		proceeds += 0.5;
	}else if(inputingMoney == 4){
		balance += 1;
		proceeds += 1;
	}else if(inputingMoney == 5){
		balance += 2;
		proceeds += 2;
	}else{
		cout << "Unidentified coin!" << endl;
	}
	
	cout << endl;
	
	return balance;
}

double makingCoffee(double balance, double coffeeCost, int userChoice){
	balance -= coffeeCost;
	cups--;
	
	if(userChoice == 2){
		cout << endl << "Here is the best Espresso in the city. Please help yourself!" << endl;
	}else if(userChoice == 3){
		cout << endl << "Here is the best Cappuccino in the city. Please help yourself!" << endl;
	}else{
		cout << endl << "Here is the best Latte in the city. Please help yourself!" << endl;
	}
	
	coffeeHasBeenTaken();
	
	return balance;	
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
			cout << "Wrong operation!" << endl;
		}
	}
}

double pinMenu(double balance){
	int pin, pinCounter = 0;
	
	cout << endl << "1 - Back to Main menu" << endl;
	cout << "Please, input PIN: ";
	
	while(true){
		cin >> pin;
		
		if(pin == 1 && pinCounter == 0){
			cout << endl;
			return proceeds;
		}else if(pin == PIN){
			int choice;
			
			pinCounter = 0;
			
			while(true){
				cout << endl << "Proceeds is " << proceeds << " BYN" << endl;
				cout << "There are " << cups << " cups loaded" << endl;
				cout << "1 - Add cups" << endl;
				cout << "2 - Withdrawal of proceeds" << endl;
				cout << "3 - Back to Main Menu" << endl;
				cout << "Choose the option: ";
				cin >> choice;
				
				if(choice == 1){
					int temp;
					
					cout << endl << "How many cups are you adding?" << endl;
					cout << "Input cups: ";
					cin >> temp;
					
					if(temp < 0){
						cout << "You inputed wrong amount of cups!" << endl;
					}else{
						cups += temp;
					}
				}else if(choice == 2){
					cout << endl << proceeds << " BYN were given away" << endl;
					proceeds = 0.0;
					balance = 0.0;
				}else if (choice == 3){
					cout << endl;
					return balance;
				}else{
					cout << "You inputed wrong option!" << endl ;
				}
			}
		}else if(pinCounter == 2){
			cout << "Blocking machine!";
			return -1;
		}else{
			cout << "PIN is wrong." << endl << endl;
			cout << "Please, input PIN: ";
			pinCounter++;	
		}
	}
	
}

