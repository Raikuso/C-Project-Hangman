#include <iostream>
#include <Windows.h>
using namespace std;
#include <conio.h>
#include <time.h>

char restart;
void gotoxy(int x, int y)
{
	HANDLE hConsole;
	COORD cursorLoc;
	cursorLoc.X = x;
	cursorLoc.Y = y;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, cursorLoc);
}

void eingabefeld() {
	gotoxy(27, 11); cout << "**************************";
	gotoxy(27, 12); cout << "*                        *";
	gotoxy(27, 13); cout << "*                        *";
	gotoxy(27, 14); cout << "*                        *";
	gotoxy(27, 15); cout << "**************************";
}

void Rahmen() {
	int rxcounter = 77;
	int rycounter = 22;
	gotoxy(1, 1);
	do {
		cout << "X";
		rxcounter--;
	} while (rxcounter != 0);
	gotoxy(1, 1);
	cout << "XX" << "\n";
	do {
		cout << " X" << endl;
		rycounter--;
	} while (rycounter != 0);
	gotoxy(1, 23);
	rxcounter = 77;
	do {
		cout << "X";
		rxcounter--;
	} while (rxcounter != 0);
	rycounter = 23;
	gotoxy(77, 1);
	do {
		cout << "X";
		rxcounter++;
		rycounter--;
		gotoxy(77, rxcounter);
	} while (rycounter != 0);
}
int main() {
	char restart;
	do {
		restart = 'b';
		system("cls");
		Rahmen();
		int specialedition = 0;
		char rate;
		int fehler = 0;
		int richtig = 0;
		int richtigx = 0;
		int control = 0;
		int wortlaenge = 0;
		int controlo13 = 13;
		int end = 0;
		int ausgabestelle = 0;
		int counter = 0;
		int zeilenlaenge = 80;
		char guesses[27] = "                          ";
		int nbrg = 0;
		int random;
		srand((unsigned)time(NULL));
		random = rand() % 25; //marikierung
		char rndm_word[25][22] = {};
		char text[] = "Willkommen in Hangman!";
		char eingabe[22] = "                     ";
		while (text[counter] != '\0') {
			counter++;
		}
		ausgabestelle = ((zeilenlaenge - counter) / 2);
		gotoxy(ausgabestelle, 5); cout << text;
		char text1[] = "Bitte geben Sie das zu erratende Wort ein. (max. 21 Buchstaben)";
		counter = 0;
		while (text1[counter] != '\0') {
			counter++;
		}
		ausgabestelle = ((zeilenlaenge - counter) / 2);
		gotoxy(ausgabestelle, 8); cout << text1;
		eingabefeld();
		gotoxy(27 , 17);
		cout << "Eingabe 'X' = Einzelspieler"; //Eingabe 'P' = Einzelspieler (Pokemon Modus)
		gotoxy(20,18);
		cout << "Eingabe 'P' = Einzelspieler (Pokemon Modus)";
		gotoxy(20,19);
		cout << "Eingabe 'C' = Einzelspieler (Chemie Modus)";
		gotoxy(30, 13);
		memset(eingabe, 0, sizeof(eingabe));
		cin.getline (eingabe, 22);
		if(eingabe[0] == 'P' || eingabe[0] == 'p'){
			specialedition = 1;
		}else if(eingabe[0] == 'C' || eingabe[0] == 'c'){
			specialedition = 2;
		}
			if(specialedition == 0){
			random = rand() % 25;
            strcpy(rndm_word[0], "ZUG");
            strcpy(rndm_word[1], "BAUM");
            strcpy(rndm_word[2], "RECHNER");
            strcpy(rndm_word[3], "QUALLE");
            strcpy(rndm_word[4], "MILCH");
            strcpy(rndm_word[5], "REIS");
            strcpy(rndm_word[6], "FENSTER");
            strcpy(rndm_word[7], "BAHNHOF");
            strcpy(rndm_word[8], "LIMBO");
            strcpy(rndm_word[9], "HANGMAN");
            strcpy(rndm_word[10], "VOGEL");
            strcpy(rndm_word[11], "JAPAN");
            strcpy(rndm_word[12], "ASIEN");
            strcpy(rndm_word[13], "DIAGNOSTIZIEREN");
            strcpy(rndm_word[14], "ABFALL");
            strcpy(rndm_word[15], "REAKTION");
            strcpy(rndm_word[16], "ANTWORT");
            strcpy(rndm_word[17], "INTERNET");
            strcpy(rndm_word[18], "JAHR");
            strcpy(rndm_word[19], "TAG");
            strcpy(rndm_word[20], "PORTAL");
            strcpy(rndm_word[21], "FOTO");
            strcpy(rndm_word[22], "KORB");
            strcpy(rndm_word[23], "WORT");
            strcpy(rndm_word[24], "ZAHL");
		}else if(specialedition == 1){
			random = rand() % 25;
            strcpy(rndm_word[0], "KAPUNO");
            strcpy(rndm_word[1], "VULPIX");
            strcpy(rndm_word[2], "ZYGARDE");
            strcpy(rndm_word[3], "CHANEIRA");
            strcpy(rndm_word[4], "KOKUNA");
            strcpy(rndm_word[5], "SICHLOR");
            strcpy(rndm_word[6], "KLINGPLIM");
            strcpy(rndm_word[7], "DIGDA");
            strcpy(rndm_word[8], "PINSIR");
            strcpy(rndm_word[9], "PANEKON");
            strcpy(rndm_word[10], "LATIOS");
            strcpy(rndm_word[11], "DIALGA");
            strcpy(rndm_word[12], "KINOSO");
            strcpy(rndm_word[13], "MEWTWO");
            strcpy(rndm_word[14], "GOLBAT");
            strcpy(rndm_word[15], "TERRAKIUM");
            strcpy(rndm_word[16], "REMORAID");
            strcpy(rndm_word[17], "DONPHAN");
            strcpy(rndm_word[18], "POKEMON");
            strcpy(rndm_word[19], "MILTANK");
            strcpy(rndm_word[20], "LUGIA");
            strcpy(rndm_word[21], "LUCARIO");
            strcpy(rndm_word[22], "WINGULL");
            strcpy(rndm_word[23], "SCOPPEL");
            strcpy(rndm_word[24], "AZUMARILL");
        }else if(specialedition == 2){
        	random = rand() % 25;
        	strcpy(rndm_word[0], "ALUMINIUM");
            strcpy(rndm_word[1], "CHLOR");
            strcpy(rndm_word[2], "BROM");
            strcpy(rndm_word[3], "SAUERSTOFF");
            strcpy(rndm_word[4], "WASSERSTOFF");
            strcpy(rndm_word[5], "KOHLENSTOFF");
            strcpy(rndm_word[6], "NATRIUM");
            strcpy(rndm_word[7], "HELIUM");
            strcpy(rndm_word[8], "VANADIUM");
            strcpy(rndm_word[9], "GOLD");
            strcpy(rndm_word[10], "SILBER");
            strcpy(rndm_word[11], "EISEN");
            strcpy(rndm_word[12], "GALIUM");
            strcpy(rndm_word[13], "CALCIUM");
            strcpy(rndm_word[14], "SCANDIUM");
            strcpy(rndm_word[15], "JOD");
            strcpy(rndm_word[16], "BOR");
            strcpy(rndm_word[17], "CAESIUM");
            strcpy(rndm_word[18], "URAN");
            strcpy(rndm_word[19], "NEON");
            strcpy(rndm_word[20], "FLOUR");
            strcpy(rndm_word[21], "XENON");
            strcpy(rndm_word[22], "LITHIUM");
            strcpy(rndm_word[23], "SAMARIUM");
            strcpy(rndm_word[24], "KUPFER");
		}
		if(!(eingabe[1] == '\0' && (eingabe[0] == 'x' || eingabe[0] == 'X' || eingabe[0] == 'P' || eingabe[0] == 'p' || eingabe[0] == 'c' || eingabe[0] == 'C'))){
            counter = 0;
            do {
                if (eingabe[control] <= 'z' && eingabe[control] >= 'a') eingabe[control] -= 32;
                if ((eingabe[control] < 'A') || (eingabe[control] > 'Z' && eingabe[control] < 'a') || (eingabe[control] > 'z'))  {
                    gotoxy(25, 17);
                    cout << "Bitte starte das Programm neu.";
                    end = 1;
                    break;
                } control++;
            } while (eingabe[control] != '\0' && eingabe[control] != ' ');
		}else{
		    memset(eingabe, 0, sizeof(eingabe));
            counter = 0;
            do {
                eingabe[counter] = rndm_word[random][counter];
                counter++;
            } while (rndm_word[random][counter] != '\0');
            control = counter;
		}
		wortlaenge = control;
		if (end == 0) {
			//Spieleinterface
			system("cls");
			Rahmen();
			gotoxy(14, 15); cout << "A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q";
			gotoxy(22, 17); cout << "R   S   T   U   V   W   X   Y   Z";
			gotoxy(54, 4);  cout << "***********";
			gotoxy(54, 5);  cout << "*         *";
			gotoxy(54, 6);  cout << "*   0/6   *";
			gotoxy(54, 7);  cout << "*         *";
			gotoxy(54, 8);  cout << "***********";
			gotoxy(23, 6);
			if (control > 13) {
				ausgabestelle = (((25 - control) / 2) + 22);
				do {
					cout << "_ ";
					control--;
					controlo13--;
				} while (controlo13 != 0);
				gotoxy(ausgabestelle, 8);
				do {
					cout << "_  ";
					control--;
				} while (control != 0);
			}
			else {
				do {
					cout << "_ ";
					control--;
				} while (control != 0);
			}
			gotoxy(5, 4); cout << "Raten sie einen Buchstaben: ";
			//Spielbeginn
			do {
				do {
					counter = 0;
					gotoxy(33, 4); 	rate = _getch();
					if (rate <= 'z' && rate >= 'a') rate -= 32;
					while (guesses[counter] != rate && guesses[counter] != '\0') {
						counter++;
					}
				} while (guesses[counter] == rate);
				guesses[nbrg] = rate;
				nbrg++; counter = 0;
				if (rate >= 'A' && rate <= 'Z') {
					do {
						if (eingabe[control] == rate) {
							if (rate < 'R') {
								ausgabestelle = 14 + ((rate - 65) * 3);
								gotoxy(ausgabestelle, 15); {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 10);
									cout << rate; }
							}
							else {
								ausgabestelle = 22 + ((rate - 82) * 4);
								gotoxy(ausgabestelle, 17); {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 10);
									cout << rate; }
							}
							if (control < 13) {
								ausgabestelle = 23 + control * 2;
								gotoxy(ausgabestelle, 6); {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 15);
									cout << rate;}
								richtigx++;
							}
							else {
								ausgabestelle = ((25 - wortlaenge) / 2) + control * 3 - 17;
								gotoxy(ausgabestelle, 8); {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 15);
									cout << rate;}
								richtigx++;
							}
							richtig = 1;

						}
						if (richtig == 0) {
							if (rate < 'R') {
								ausgabestelle = 14 + ((rate - 65) * 3);
								gotoxy(ausgabestelle, 15); {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 12);
									cout << rate; }
							}
							else {
								ausgabestelle = 22 + ((rate - 82) * 4);
								gotoxy(ausgabestelle, 17); {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 12);
									cout << rate; }
							}
						}
						control++;
					} while (eingabe[control] != '\0');
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 15);
					control = 0;
					if (richtig == 0) {
						fehler++;
					} gotoxy(58, 6); if (fehler<5) cout << fehler;
					else {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 12);
						cout << fehler;
					}
					richtig = 0;
					gotoxy(33, 4); cout << " ";
				}
			} while (fehler < 6 && richtigx < wortlaenge);
			if (fehler == 6) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 12);
				gotoxy(23, 11); cout << "Verloren..";
				counter = 0;
				do {
					control = 0;
					if (guesses[control] != eingabe[counter]) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 12);
						do {
							control++;
						} while (guesses[control] != eingabe[counter] && guesses[control] != '\0');
					}if (guesses[control] == '\0') {
						if (counter < 13) {
							ausgabestelle = 23 + counter * 2;
							gotoxy(ausgabestelle, 6);
							cout << eingabe[counter];
						}
						else {
							ausgabestelle = ((25 - wortlaenge) / 2) + counter * 3 - 17;
							gotoxy(ausgabestelle, 8);
							cout << eingabe[counter];
						}
					}if (guesses[control] == eingabe[counter]) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 2);
						if (counter < 13) {
							ausgabestelle = 23 + counter * 2;
							gotoxy(ausgabestelle, 6);
							cout << eingabe[counter];
						}
						else {
							ausgabestelle = ((25 - wortlaenge) / 2) + counter * 3 - 17;
							gotoxy(ausgabestelle, 8);
							cout << eingabe[counter];
						}
					}
					counter++;
				} while (eingabe[counter] != '\0' && eingabe[counter] != ' ');
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 15);
			gotoxy(19, 21); cout << "Moechten Sie das Spiel neustarten? (y/n) ";
			if (richtigx == wortlaenge) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 10);
				gotoxy(23, 11); cout << "Gewonnen!";
			}
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 15);
			do {
				gotoxy(59, 21); restart = _getch();
			} while (restart != 'n' && restart != 'N' && restart != 'y' && restart != 'Y');
			if (restart == 'n' || restart == 'N')	break;
		}
	} while (restart == 'y' || restart == 'Y');
	return 0;
}

