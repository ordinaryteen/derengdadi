#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
int chanceLeft;
int playerGuess;
int playerChoiceLevel;
int TotalGuess;

void display(){
	cout << "Oi, ayo main tebak-tebakan!\n" <<endl;
	cout << "mau level yang gimana niihh?\n1.level ez "<< endl	<< "2.level lumayan"<< endl <<"3.level hardd" << endl;
	cout << "\nLevel pilihan:" ;
}

int random(){
    srand(time(NULL)); 
    return rand() % 100 + 1;
}

void Logic(int guess_sum_BasedOnLevel){
	while (chanceLeft < guess_sum_BasedOnLevel) {
        cout << "Coba tebak angka dari 1-100: ";
        cin >> playerGuess;
        chanceLeft++;
        TotalGuess++;
		
        if (playerGuess == random()) {
            cout << "Sip, luwh nebak sebanyak " << TotalGuess << " kali." << endl;
            break;
        } else if (playerGuess < random()) {
            cout << "terlalu rendah, mas." << endl;
        } else {
            cout << "dugaanmu kebesaran, paman" << endl;
        } 
		
		if (TotalGuess != guess_sum_BasedOnLevel){
			cout << "P ingfo, kesempatanmu kurang " << guess_sum_BasedOnLevel - chanceLeft << "\n"<< endl;
		} else{
			gameOver = true;
			
		if (gameOver == true){
				cout << "angka yang bener itu sebenernya " << random();
			}
			
			break;
		}
    }
}

void levelChoice(){
	cin >> playerChoiceLevel;
	bool validchoice = false;
	
	do {
		if (playerChoiceLevel == '1' || playerChoiceLevel == '2' || playerChoiceLevel == '3') {
			validchoice = true;
		}
		
		if (validchoice == true){
			system ("cls");
			cout << "Dimulai pada:\n";
	    	for (int i = 3; i >= 1; i--) {
	        cout << i << endl;
	        Sleep(1000);
	    	}
		}
		
		else{
			system ("cls");
			cout << "Pilihan tdiak valdi! Dimohon untuk memilih pliehan yg fadil." << random() << endl;
			break;
		}
	}
	while (!validchoice);
	
}




int main () {
	
	while (!gameOver) {
		display();
		levelChoice();
		//logic();
	}
}


