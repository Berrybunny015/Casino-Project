#ifndef CASINO_H_INCLUDED
#define CASINO_H_INCLUDED //start defining header file

//define global constants
#define SLOTS 1
#define SCRATCH 2
#define BLACKJACK 3
int cards;
#define EXIT 4

//define Black Jack constants
#define FACES 13
#define SUITS 4
#define CLUBS 0
#define DIAMONDS 1
#define HEARTS 2
#define SPADES 3
#define BUST 21

//define Scratch Off constants
#define ONE 1
#define TWO 2
#define FIVE 5
#define BONUS 20

//establish basic prototypes

void welcomeScreen();

void clearScreen();

int displayMenu();

int playSlots();

int playScratchOffs();

int playBlackJack();

char randomSymbol();

//declare functions for Black Jack game

void initializeUsed ();

void printDeck ();

void initializeDeck ();

int deal ();

int results ();

//define structs for Scratch Offs
typedef struct OneDollar {
    int winNumber;
    int numbers[5];
    double prizes[5];
    char bonus[2];
}OneDollar;

typedef struct TwoDollar {
    int winNumbers[2];
    int numbers[10];
    double prizes[10];
    char bonus[2];
}TwoDollar;

typedef struct FiveDollar {
    int winNumbers[4];
    int numbers[12];
    double prizes[12];
    char bonus[4];
}FiveDollar;

#endif // end defining header file
