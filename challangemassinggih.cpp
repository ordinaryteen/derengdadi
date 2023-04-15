#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

bool gameOver;
int chanceLeft;
int playerGuess;
int playerChoiceLevel;
int TotalGuess;

void clr(){
	system("cls");
}

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
	int randomNumber = random(); 
	while (chanceLeft < guess_sum_BasedOnLevel) {
        cout << "Coba tebak angka dari 1-100: ";
        cin >> playerGuess;
        chanceLeft++;
        TotalGuess++;
		
        if (playerGuess == randomNumber) {
        	clr();
            cout << "Sip, luwh nebak sebanyak " << TotalGuess << " kali." << endl;
            break;
        } else if (playerGuess < randomNumber) {
        	clr();
            cout << "terlalu rendah, mas." << endl;
            
        } else {
        	clr();
            cout << "dugaanmu kebesaran, paman" << endl;
        } 
		
		if (TotalGuess != guess_sum_BasedOnLevel){
			cout << "P ingfo, kesempatanmu kurang " << guess_sum_BasedOnLevel - chanceLeft << "\n"<< endl;
		} else{
			gameOver = true;
			
		if (gameOver == true){
			char playAgain;
			cout << "angka yang bener itu sebenernya " << randomNumber;
			cout << "mw main lg kh bliaw? (Y/T)";
			cin >> playAgain;
			if (playAgain == 'Y'){
				cout << "\nsementara ini dulu lah, gpp ntar dilanjut";
			}
			else{
				break;
			}
		}
			break;
		}
    }
}

void levelChoice(){
	cin >> playerChoiceLevel;
	bool validchoice = false;
	
	do {
		if (playerChoiceLevel == 1 || playerChoiceLevel == 2 || playerChoiceLevel == 3) {
			validchoice = true;
		}
		
		if (validchoice == true){
			system ("cls");
			cout << "Dimulai pada:\n";
	    	for (int i = 3; i >= 1; i--) {
	        cout << i << endl;
	        Sleep(1000);
	    	} system("cls");
	    	
	    	switch (playerChoiceLevel) {
	    		case 1:
	    			Logic(10);
	    			break;
	    		case 2:
	    			Logic(5);
	    			break;
	    		case 3:
	    			Logic(3);
	    			break;
	    		default:
	    			cout << "prikitiwww"; 
	    			break;
			}
		}
		
		else{
			system ("cls");
			cout << "ALERT!-------Pilihan tdiak valdi! Dimohon untuk memilih pliehan yg fadil.--------"<< endl;
			break;
		}
	}
	while (!validchoice);
	
}

int main () {
	
	while (!gameOver) {
		display();
		levelChoice();
	}
}

