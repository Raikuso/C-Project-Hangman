#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

// Funktionen
void moveToPosition(int x, int y);
void drawFrame();
void chooseRandomWord(char destination[], int edition);
void playGame(const char* word, int wordLength);
void displayGuessedLetters(const char* guessedLetters, const char* correctLetters, int numGuessed);
void setColor(int color);
void centerText(const string& text, int y);

// Hilfsfunktion zum Setzen der Cursorposition
void moveToPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorLoc;
    cursorLoc.X = static_cast<SHORT>(x);
    cursorLoc.Y = static_cast<SHORT>(y);
    SetConsoleCursorPosition(hConsole, cursorLoc);
}

// Hilfsfunktion zum Setzen der Textfarbe
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(color));
}

// Hilfsfunktion zum zentrieren von Text
void centerText(const string& text, int y) {
    int x = static_cast<int>((80 - text.length()) / 2);
    moveToPosition(x, y);
    cout << text;
}

// Zeichnet den Rahmen um das Spielfenster
void drawFrame() {
    // Zeichne den oberen Rahmen
    moveToPosition(0, 0); for (int i = 0; i < 80; ++i) cout << "X";
    moveToPosition(0, 1); cout << "X" << string(78, ' ') << "X" << endl;
    for (int i = 2; i < 22; ++i) {
        moveToPosition(0, i); cout << "X" << string(78, ' ') << "X" << endl;
    }
    moveToPosition(0, 22); cout << "X" << string(78, ' ') << "X" << endl;
    moveToPosition(0, 23); for (int i = 0; i < 80; ++i) cout << "X";
}

// Funktion zur Auswahl eines zufälligen Wortes
void chooseRandomWord(char destination[], int edition) {
    const char* einfachWords[25] = { "ZUG", "BAUM", "RECHNER", "QUALLE", "MILCH", "REIS", "FENSTER", "BAHNHOF",
                                    "LIMBO", "HANGMAN", "VOGEL", "JAPAN", "ASIEN", "DIAGNOSTIZIEREN", "ABFALL",
                                    "REAKTION", "ANTWORT", "INTERNET", "JAHR", "TAG", "PORTAL", "FOTO", "KORB",
                                    "WORT", "ZAHL" };

    const char* generalWords[25] = { "APFEL", "BUCH", "COMPUTER", "DRACHE", "ELEFANT", "FREIHEIT", "GITARRE", "HAMMER",
                                    "INSEL", "JONGLEUR", "KAKTUS", "LAMPE", "MOND", "NADEL", "OZEAN", "PUZZLE", "QUALLE",
                                    "ROBOTER", "SONNE", "TROMMEL", "UHR", "VULKAN", "WOLKE", "XYLOPHON", "YACHT" };

    const char* pokemonWords[25] = { "KAPUNO", "VULPIX", "ZYGARDE", "CHANEIRA", "KOKUNA", "SICHLOR", "KLINGPLIM",
                                    "DIGDA", "PINSIR", "PANEKON", "LATIOS", "DIALGA", "KINOSO", "MEWTWO", "GOLBAT",
                                    "TERRAKIUM", "REMORAID", "DONPHAN", "POKEMON", "MILTANK", "LUGIA", "LUCARIO",
                                    "WINGULL", "SCOPPEL", "AZUMARILL" };

    const char* chemistryWords[25] = { "ALUMINIUM", "CHLOR", "BROM", "SAUERSTOFF", "WASSERSTOFF", "KOHLENSTOFF",
                                      "NATRIUM", "HELIUM", "VANADIUM", "GOLD", "SILBER", "EISEN", "GALIUM",
                                      "CALCIUM", "SCANDIUM", "JOD", "BOR", "CAESIUM", "URAN", "NEON",
                                      "FLUOR", "XENON", "LITHIUM", "SAMARIUM", "KUPFER" };

    const char* selectedWordArray = nullptr;
    switch (edition) {
    case 0: selectedWordArray = einfachWords[rand() % 25]; break;
    case 1: selectedWordArray = generalWords[rand() % 25]; break;
    case 2: selectedWordArray = pokemonWords[rand() % 25]; break;
    case 3: selectedWordArray = chemistryWords[rand() % 25]; break;
    }

    strcpy_s(destination, 22, selectedWordArray);
}

void displayGuessedLetters(const char* guessedLetters, const char* correctLetters, int numGuessed) {
    centerText("Bereits geraten:", 14);

    // Erstelle ein Array mit allen Buchstaben des Alphabets
    const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabetLength = strlen(alphabet);

    for (int row = 0; row < 2; ++row) {
        // Berechne die Startposition für jede Reihe
        int startX = (80 - ((alphabetLength / 2 + alphabetLength % 2) * 3)) / 2;
        moveToPosition(startX, 16 + row);

        for (int i = row * 13; i < (row + 1) * 13 && i < alphabetLength; ++i) {
            char letter = alphabet[i];
            bool isGuessed = false;
            bool isCorrect = false;

            // Überprüfe, ob der Buchstabe geraten wurde
            for (int j = 0; j < numGuessed; ++j) {
                if (guessedLetters[j] == letter) {
                    isGuessed = true;
                    if (strchr(correctLetters, letter)) {
                        isCorrect = true;
                    }
                    break;
                }
            }

            // Setze die Farbe basierend auf dem Ratestatus
            if (isGuessed) {
                if (isCorrect) {
                    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                }
                else {
                    setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
                }
            }
            else {
                setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Weiß für nicht geratene Buchstaben
            }

            // Gib den Buchstaben aus
            cout << letter << "  ";
        }
    }

    // Setze die Farbe zurück auf Weiß
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void playGame(const char* word, int wordLength) {
    char guessedLetters[27] = { 0 };
    char correctLetters[27] = { 0 };
    int numGuessed = 0;
    int numCorrect = 0;
    int incorrectGuesses = 0;
    bool isCorrect = false;
    char displayWord[22] = { 0 };
    string fehlerString;

    // Initialisiere das Anzeigewort mit Unterstrichen
    for (int i = 0; i < wordLength; ++i) {
        displayWord[i] = '_';
    }

    while (incorrectGuesses < 6) {
        system("cls");
        drawFrame();

        // Zeige das Wort mit erratenen Buchstaben
        string displayString(displayWord);
        centerText(displayString, 6);

        fehlerString = "Fehler: " + to_string(incorrectGuesses) + "/6";
        centerText(fehlerString, 8);

        // Neue Position für "Rate einen Buchstaben:"
        string guessPrompt = "Rate einen Buchstaben: ";
        centerText(guessPrompt, 12);
        moveToPosition(40, 13);

        // Lasse eine Zeile frei

        // Zeige die bereits geratenen Buchstaben
        displayGuessedLetters(guessedLetters, correctLetters, numGuessed);

        // Lese die Benutzereingabe
        char guess = toupper(_getch());
        if (guess < 'A' || guess > 'Z') continue; // Ungültige Eingaben ignorieren

        // Prüfe, ob der Buchstabe schon geraten wurde
        bool alreadyGuessed = false;
        for (int i = 0; i < numGuessed; ++i) {
            if (guessedLetters[i] == guess) {
                alreadyGuessed = true;
                break;
            }
        }
        if (alreadyGuessed) continue;

        isCorrect = false;

        // Überprüfe, ob der Buchstabe im Wort enthalten ist
        for (int i = 0; i < wordLength; ++i) {
            if (word[i] == guess) {
                displayWord[i] = guess;
                isCorrect = true;
            }
        }

        if (isCorrect) {
            correctLetters[numCorrect++] = guess;
        }
        else {
            incorrectGuesses++;
        }
        guessedLetters[numGuessed++] = guess;

        // Überprüfe, ob das Wort vollständig erraten wurde
        if (strcmp(displayWord, word) == 0) {
            system("cls");
            drawFrame();
            centerText(displayWord, 6);
            centerText(fehlerString, 8);
            displayGuessedLetters(guessedLetters, correctLetters, numGuessed);
            setColor(FOREGROUND_GREEN);
            centerText("Gewonnen!", 12);
            setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset to white
            Sleep(2000);
            return;
        }
    }

    // Falls verloren
    system("cls");
    drawFrame();
    centerText(displayWord, 6);
    centerText(fehlerString, 8);
    displayGuessedLetters(guessedLetters, correctLetters, numGuessed);
    setColor(FOREGROUND_RED);
    string lostMessage = "Leider verloren! Das Wort war: " + string(word);
    centerText(lostMessage, 12);
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset to white
    Sleep(2000);
}

int main() {
    SetConsoleTitle(TEXT("Hangman"));


    srand(static_cast<unsigned int>(time(0)));
    char restart;

    do {
        system("cls");
        drawFrame();

        centerText("Waehlen Sie eine Edition:", 6);
        centerText("0 - Einfach", 8);
        centerText("1 - Allgemein", 9);
        centerText("2 - Pokemon", 10);
        centerText("3 - Chemie", 11);

        int edition;
        char input;
        bool validInput = false;

        do {
            input = _getch();

            if (input >= '0' && input <= '3') {
                edition = input - '0';
                validInput = true;
            }
        } while (!validInput);

        char word[22];
        chooseRandomWord(word, edition);
        playGame(word, strlen(word));

        Sleep(1000);
        system("cls");
        drawFrame();

        centerText("Moechten Sie noch einmal spielen?", 11);
        centerText("Druecken Sie 'J' fuer Ja oder 'N' fuer Nein", 13);

        do {
            moveToPosition(39, 15);
            cout << " ";
            moveToPosition(39, 15);
            restart = toupper(_getch());
        } while (restart != 'J' && restart != 'N');

    } while (restart == 'J');

    return 0;
}
