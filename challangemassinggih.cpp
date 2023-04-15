#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

//INITIALIZE!
bool gameOver;
int chanceLeft;
int playerGuess;
int playerChoiceLevel;
int TotalGuess;

//laziness come inside me fr
void clr(){
	system("cls");
}

//just to give the user an information of the game itself
void display(){
	cout << "Oi, ayo main tebak-tebakan!\n" <<endl;
	cout << "mau level yang gimana niihh?\n1.level ez "<< endl	<< "2.level lumayan"<< endl <<"3.level hardd" << endl;
	cout << "\nLevel pilihan:" ;
}

//to generate random number
int random(){
    srand(time(NULL)); 
    return rand() % 100 + 1;
}

//what's inside of them, pretty easy.
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
		} 
		
		else{
			gameOver = true;
			
			if (gameOver == true){
				char playAgain;
				clr();
				cout << "angka yang bener itu sebenernya " << randomNumber << endl;
				cout << "mw main lg kh bliaw? (Y/T)";
				cin >> playAgain;
				if (playAgain == 'Y'){
					MAS SINGGIH IKI YOKPO, AKU PENGEN NYELOK VOID LEVELCHOICE (BARIS 77), TAPI NDEK ISOR E
				}
			}
				break;
		}
    }
}

//this is when it comes to sculpt it to be a beautiful terminal
void levelChoice(){
	cin >> playerChoiceLevel;
	bool validchoice = false;
	
	do {
		if (playerChoiceLevel == 1 || playerChoiceLevel == 2 || playerChoiceLevel == 3) {
			validchoice = true;
		}
		
		if (validchoice == true){
			clr();
			cout << "Dimulai pada:\n";
	    	for (int i = 3; i >= 1; i--) {
	        cout << i << endl;
	        Sleep(1000);
	    	} clr();
	    	
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

