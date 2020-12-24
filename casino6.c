// write preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "casino.h"

//function declarations/prototypes for Scratch Offs
char getBonus(int type) {
    const int ONE_TWO = 6;
    const int FIVE_RAND = 8;
    char SYMBOLS[] = {'$','%','&','#','@','!','^','*'};
    char bonus;
    int sym;

    if((type == ONE)||(type == TWO)) {
        sym = rand() % ONE_TWO;

        switch(sym) {
            case 0:
                bonus = SYMBOLS[0];
                break;
            case 1:
                bonus = SYMBOLS[1];
                break;
            case 2:
                bonus = SYMBOLS[2];
                break;
            case 3:
                bonus = SYMBOLS[3];
                break;
            case 4:
                bonus = SYMBOLS[4];
                break;
            case 5:
                bonus = SYMBOLS[5];
                break;
        }
    }

    else if(type == FIVE) {
        sym = rand() % FIVE_RAND;

        switch(sym) {
            case 0:
                bonus = SYMBOLS[0];
                break;
            case 1:
                bonus = SYMBOLS[1];
                break;
            case 2:
                bonus = SYMBOLS[2];
                break;
            case 3:
                bonus = SYMBOLS[3];
                break;
            case 4:
                bonus = SYMBOLS[4];
                break;
            case 5:
                bonus = SYMBOLS[5];
                break;
            case 6:
                bonus = SYMBOLS[6];
                break;
            case 7:
                bonus = SYMBOLS[7];
                break;
        }
    }

    return(bonus);
}

int cashOneDollar(OneDollar OneDollar) {
    const int SYMS = 2; //number of bonus symbols
    const int NUMS = 5; //number of player symbols
    float cash; //for the player's cash
    int n; //looping variable
    char bonus = getBonus(ONE);
    int usedSyms[] = {};

    printf("Bonus symbol is %c\n\n", bonus);

    for(n = 0; n < NUMS; n++) {
        if(OneDollar.numbers[n] == OneDollar.winNumber) {
            cash = cash + OneDollar.prizes[n];
        }
    }

    for(n = 0; n < SYMS; n++) {
        if(OneDollar.bonus[n] == bonus) {
            cash = cash + BONUS;
        }
    }

    printf("Your One Dollar Scratch Off won you $%0.2lf\n\n", cash);

    return(cash);
}

int cashTwoDollar(TwoDollar TwoDollar) {
    const int WINS = 2; //number of winning numbers
    const int SYMS = 2; //number of bonus symbols
    const int NUMS = 10; //number of player numbers and prizes
    float cash;
    int w;
    int n;
    char bonus = getBonus(TWO);

    printf("Bonus symbol is %c\n\n", bonus);

    for(w = 0; w < WINS; w++) {
        for(n = 0; n < NUMS; n++) {
            if(TwoDollar.winNumbers[w] == TwoDollar.numbers[n]) {
                cash = cash + TwoDollar.prizes[n];
            }
        }
    }

    for(n = 0; n < SYMS; n++) {
        if(TwoDollar.bonus[n] == bonus) {
            cash = cash + BONUS;
        }
    }

    printf("Your Two Dollar Scratch Off won you $%0.2lf\n\n", cash);

    return(cash);
}

int cashFiveDollar(FiveDollar FiveDollar) {
    const int WINS = 4; //number of winning numbers
    const int SYMS = 4; //number of bonus symbols
    const int NUMS = 12; //number of player numbers and prizes
    float cash;
    int w;
    int n;
    char bonus = getBonus(FIVE);

    printf("Bonus symbol is %c\n\n", bonus);

    for(w = 0; w < WINS; w++) {
        for(n = 0; n < NUMS; n++) {
            if(FiveDollar.winNumbers[w] == FiveDollar.numbers[n]) {
                cash = cash + FiveDollar.prizes[n];
            }
        }
    }

    for(n = 0; n < SYMS; n++) {
        if(FiveDollar.bonus[n] == bonus) {
            cash = cash + BONUS;
        }
    }

    printf("Your Five Dollar Scratch Off won you $%0.2lf\n\n", cash);

    return(cash);
}

OneDollar createScratchOffOne(OneDollar OneDollar){
    //declare constants
    const int SYMS = 2; //number of bonus symbols
    const int NUMS = 5; //number of player numbers
    const int BASE = 20; //random function to generate numbers
    const char SYMBOLS[] = {'$','%','&','#','@','!'};
    int usedSyms[] = {0,0,0,0,0,0}; //keep track of used symbols
    int used = 0; //indicate is a symbol has been used

    int sym; //random symbol
    int n; //looping variable

    OneDollar.winNumber = (rand()) % BASE + 1;

    for(n = 0; n < NUMS; ++n) {
        OneDollar.numbers[n] = (rand()) % BASE + 1;
    }

    for(n = 0; n < NUMS; ++n) {
        OneDollar.prizes[n] = (rand()) % (BASE*5) + 5;
    }

    for(n = 0; n < SYMS; ++n) {
        used = 0;

        while(used == 0) {
            sym = rand() % 6;

            if(usedSyms[sym] == 0) {
                usedSyms[sym] = 1;
                used = 1;
                break;
            }
        }

        switch(sym) {
            case 0:
                OneDollar.bonus[n] = SYMBOLS[0];
                break;
            case 1:
                OneDollar.bonus[n] = SYMBOLS[1];
                break;
            case 2:
                OneDollar.bonus[n] = SYMBOLS[2];
                break;
            case 3:
                OneDollar.bonus[n] = SYMBOLS[3];
                break;
            case 4:
                OneDollar.bonus[n] = SYMBOLS[4];
                break;
            case 5:
                OneDollar.bonus[n] = SYMBOLS[5];
                break;
        }
    }

    return OneDollar;
}

void displayScratchOffOne(OneDollar OneDollar) {
    const int SYMS = 2; //number of bonus symbols
    const int NUMS = 5; //number of player numbers

    int i; //looping variable

    printf("Getting your scratch offs...\n");

    printf("+---------------------------------------------------------+\n");

    printf("WINNING NUMBER   %d   \n", OneDollar.winNumber);
    printf("YOUR NUMBERS\n");

    for(i = 0; i < NUMS; ++i) {
        if(i != 4) {
            printf("   %d   ", OneDollar.numbers[i]);
        }
        else {
            printf("   %d   \n\n", OneDollar.numbers[i]);
        }
    }

    printf("PRIZES\n");

    for(i = 0; i < NUMS; ++i) {
        if(i != 4) {
            printf("   %0.2lf   ", OneDollar.prizes[i]);
        }
        else {
            printf("   %0.2lf   \n\n", OneDollar.prizes[i]);
        }
    }

    printf("SYMBOLS\n");

    for(i = 0; i < SYMS; ++i) {
        if(i != 1) {
            printf("   %c   ", OneDollar.bonus[i]);
        }
        else {
            printf("   %c   \n", OneDollar.bonus[i]);
        }
    }

    printf("+---------------------------------------------------------+\n");
}

TwoDollar createScratchOffTwo(TwoDollar TwoDollar) {
    //declare constants
    const int SYMS = 2; //number of bonus symbols
    const int NUMS = 10; //number of player numbers
    const int BASE = 30; //random function to generate numbers
    const char SYMBOLS[] = {'$','%','&','#','@','!'};
    int usedSyms[] = {0,0,0,0,0,0}; //keep track of used symbols
    int usedNums[] = {0,0}; //keep track of used winning numbers
    int num; //store the randomly generated number
    int used = 0; //control variable indicating if a symbol or number has been used

    int sym; //random symbol
    int n; //looping variable

    for(n = 0; n < 2; ++n) {
        used = 0;

        while(used == 0) {
            num = (rand()) % BASE + 1;
            if(usedNums[n] == 0) {
                usedNums[n] = 1;
                if(n == 1) { //second symbol
                    TwoDollar.winNumbers[n] = (rand()) % BASE + 1;
                    while(TwoDollar.winNumbers[n] == TwoDollar.winNumbers[0]) { //if winning number is used, it will be randomized until it is not the used symbol
                        TwoDollar.winNumbers[n] = (rand()) % BASE + 1;
                    }
                }
                else {
                    TwoDollar.winNumbers[n] = num; //assign first symbol to the one
                }
                used = 1;
            }
            break;
        }
    }

    for(n = 0; n < NUMS; ++n) {
        TwoDollar.numbers[n] = (rand()) % BASE + 1;
    }

    for(n = 0; n < NUMS; ++n) {
        TwoDollar.prizes[n] = (rand()) % (BASE*5) + 5;
    }

    for(n = 0; n < SYMS; ++n) {
        used = 0;

        while(used == 0) {
            sym = rand() % 6;

            if(usedSyms[sym] == 0) {
                usedSyms[sym] = 1;
                used = 1;
                break;
            }
        }

        switch(sym) {
            case 0:
                TwoDollar.bonus[n] = SYMBOLS[0];
                break;
            case 1:
                TwoDollar.bonus[n] = SYMBOLS[1];
                break;
            case 2:
                TwoDollar.bonus[n] = SYMBOLS[2];
                break;
            case 3:
                TwoDollar.bonus[n] = SYMBOLS[3];
                break;
            case 4:
                TwoDollar.bonus[n] = SYMBOLS[4];
                break;
            case 5:
                TwoDollar.bonus[n] = SYMBOLS[5];
                break;
        }
    }

    return TwoDollar;
}

void displayScratchOffTwo(TwoDollar TwoDollar) {
    const int SYMS = 2; //number of bonus symbols
    const int NUMS = 10; //number of player numbers
    const int BREAK = 4; //start second line of the player's numbers and prizes

    int i; //looping variable

    printf("Getting your scratch offs...\n");

    printf("+---------------------------------------------------------+\n");

    for(i = 0; i < SYMS; ++i) {
        if(i != 1)  {
            printf("WINNING NUMBERS   %d   ", TwoDollar.winNumbers[i]);
        }

        else {
            printf("   %d   \n\n", TwoDollar.winNumbers[i]);
        }
    }

    printf("YOUR NUMBERS\n");

    for(i = 0; i < NUMS; ++i) {
        if((i != BREAK)&&(i != 9))  {
            printf("   %d   ", TwoDollar.numbers[i]);
        }

        else if(i == BREAK) {
            printf("   %d   \n", TwoDollar.numbers[i]);
        }
        else if(i == 9) {
            printf("   %d   \n\n", TwoDollar.numbers[i]);
        }
    }

    printf("PRIZES\n");

    for(i = 0; i < NUMS; ++i) {
        if((i != BREAK)&&(i != 9)) {
            printf("   %0.2lf   ", TwoDollar.prizes[i]);
        }
        else if(i == BREAK) {
            printf("   %0.2lf   \n", TwoDollar.prizes[i]);
        }
        else if(i == 9) {
            printf("   %0.2lf   \n\n", TwoDollar.prizes[i]);
        }
    }

    printf("SYMBOLS\n");

    for(i = 0; i < SYMS; ++i) {
        if(i != 1) {
            printf("   %c   ", TwoDollar.bonus[i]);
        }
        else {
            printf("   %c   \n", TwoDollar.bonus[i]);
        }
    }

    printf("+---------------------------------------------------------+\n");
}

FiveDollar createScratchOffFive(FiveDollar FiveDollar) {
    //declare constants
    const int SYMS = 4; //number of bonus symbols
    const int NUMS = 12; //number of player numbers
    const int BASE = 50; //random function to generate numbers
    const char SYMBOLS[] = {'$','%','&','#','@','!','^','*'};
    int usedSyms[] = {0,0,0,0,0,0,0,0}; //keep track of used symbols
    int usedNums[] = {0,0,0,0}; //keep track of used winning numbers
    int num; //store the randomly generated number
    int used = 0; //control variable indicating if a symbol or number has been used

    int sym; //random symbol
    int n; //looping variable

    for(n = 0; n < 4; ++n) {
        used = 0;

        while(used == 0) {
            num = (rand()) % BASE + 1;
            if(usedNums[n] == 0) {
                usedNums[n] = 1;
                if(n == 1) { //second symbol
                    FiveDollar.winNumbers[n] = (rand()) % BASE + 1;
                    while(FiveDollar.winNumbers[n] == FiveDollar.winNumbers[0]) { //if winning number is used, it will be randomized until it is not the used symbol
                        FiveDollar.winNumbers[n] = (rand()) % BASE + 1;
                    }
                }
                else if(n == 2) { //third symbol
                    FiveDollar.winNumbers[n] = (rand()) % BASE + 1;
                    while((FiveDollar.winNumbers[n] == FiveDollar.winNumbers[1]) || (FiveDollar.winNumbers[n] == FiveDollar.winNumbers[0])) { //if winning number is used, it will be randomized until it is not the used symbol
                        FiveDollar.winNumbers[n] = (rand()) % BASE + 1;
                    }
                }
                else if(n == 3) { //fourth symbol
                    FiveDollar.winNumbers[n] = (rand()) % BASE + 1;
                    while((FiveDollar.winNumbers[n] == FiveDollar.winNumbers[0]) || (FiveDollar.winNumbers[n] == FiveDollar.winNumbers[1]) || (FiveDollar.winNumbers[n] == FiveDollar.winNumbers[2])) { //if winning number is used, it will be randomized until it is not the used symbol
                        FiveDollar.winNumbers[n] = (rand()) % BASE + 1;
                    }
                }
                else {
                    FiveDollar.winNumbers[n] = num; //assign first symbol to the one
                }
                used = 1;
            }
            break;
        }
    }

    for(n = 0; n < NUMS; ++n) {
        FiveDollar.numbers[n] = (rand()) % BASE + 1;
    }

    for(n = 0; n < NUMS; ++n) {
        FiveDollar.prizes[n] = (rand()) % (BASE*5) + 5;
    }

    for(n = 0; n < SYMS; ++n) {
        used = 0;

        while(used == 0) {
            sym = rand() % 8;

            if(usedSyms[sym] == 0) {
                usedSyms[sym] = 1;
                used = 1;
                break;
            }
        }

        switch(sym) {
            case 0:
                FiveDollar.bonus[n] = SYMBOLS[0];
                break;
            case 1:
                FiveDollar.bonus[n] = SYMBOLS[1];
                break;
            case 2:
                FiveDollar.bonus[n] = SYMBOLS[2];
                break;
            case 3:
                FiveDollar.bonus[n] = SYMBOLS[3];
                break;
            case 4:
                FiveDollar.bonus[n] = SYMBOLS[4];
                break;
            case 5:
                FiveDollar.bonus[n] = SYMBOLS[5];
                break;
            case 6:
                FiveDollar.bonus[n] = SYMBOLS[6];
                break;
            case 7:
                FiveDollar.bonus[n] = SYMBOLS[7];
                break;
        }
    }

    return FiveDollar;
}

void displayScratchOffFive(FiveDollar FiveDollar) {
    const int SYMS = 4; //number of bonus symbols
    const int NUMS = 12; //number of player numbers
    const int BREAK = 4; //start second line of the player's numbers and prizes

    int i; //looping variable

    printf("Getting your scratch offs...\n");

    printf("+---------------------------------------------------------+\n");

    for(i = 0; i < SYMS; ++i) {
        if(i == 0)  {
            printf("WINNING NUMBERS   %d   ", FiveDollar.winNumbers[i]);
        }

        else if ((i > 0)&&(i < 3)){
            printf("   %d   ", FiveDollar.winNumbers[i]);
        }
        else if ((i == 3)) {
            printf("   %d   \n\n", FiveDollar.winNumbers[i]);
        }
    }

    printf("YOUR NUMBERS\n");

    for(i = 0; i < NUMS; ++i) {
        if((i != BREAK)&&(i != 8)&&(i != 11))  {
            printf("   %d   ", FiveDollar.numbers[i]);
        }
        else if ((i == BREAK)||(i == 8)) {
            printf("   %d   \n", FiveDollar.numbers[i]);
        }
        else if (i == 11){
            printf("   %d   \n\n", FiveDollar.numbers[i]);
        }
    }

    printf("PRIZES\n");

    for(i = 0; i < NUMS; ++i) {
        if((i != BREAK)&&(i != 8)&&(i != 11)) {
            printf("   %0.2lf   ", FiveDollar.prizes[i]);
        }
        else if ((i == BREAK)||(i == 8)) {
            printf("   %0.2lf   \n", FiveDollar.prizes[i]);
        }
        else if (i == 11){
            printf("   %0.2lf   \n\n", FiveDollar.prizes[i]);
        }
    }

    printf("SYMBOLS\n");

    for(i = 0; i < SYMS; ++i) {
        if(i != 3) {
            printf("   %c   ", FiveDollar.bonus[i]);
        }
        else {
            printf("   %c   \n", FiveDollar.bonus[i]);
        }
    }

    printf("+---------------------------------------------------------+\n");
}

//define necessary functions
//set the welcome screen that appears and then disappears
void welcomeScreen(){
    printf("##########################################################\n");
    printf("##########################################################\n");
    printf("############                                  ############\n");
    printf("############          Knights Casino          ############\n");
    printf("############                                  ############\n");
    printf("##########################################################\n");
    printf("##########################################################\n");
}

void clearScreen(){
    printf("<Hit Enter to continue>\n");

/*declare a variable of data type char for the user's character input to be
scanned and saved into the code*/
//e for enter
    char e;
    scanf("%c", &e);

//if operating system is Windows
  system("cls");

//if operating system is Mac or Linux
//    system("clear");
}

int displayMenu(){
    // userNumber means the number associated with the game the user selected
    int userNumber;

    //establish user's game selection
    do{
        printf("Select a game to play by entering the number next to the game.\n");
        printf("1. Slots\n");
        printf("2. Scratch Offs\n");
        printf("3. Black Jack\n");
        printf("4. Quit\n");
    //scan the number/game that the user selected
        scanf("%d", &userNumber);

    //ensure the user's game selection is limited between the options given
    }
    while((userNumber < SLOTS)||(userNumber > EXIT));

    return userNumber;
}

//declare and define each game's functions
//establish randomSymbol function first for the slots game
char randomSymbol(){
    const int SYMBOLS = 6;
    const char symbols[7] = "$%&#@!";
    char symbol;
    int num;

    //establish random number generator b/w 0 and 5
    num = (rand() % 6);

    switch(num) {
        case 0:
            symbol = symbols[0];
            break;
        case 1:
            symbol = symbols[1];
            break;
        case 2:
            symbol = symbols[2];
            break;
        case 3:
            symbol = symbols[3];
            break;
        case 4:
            symbol = symbols[4];
            break;
        case 5:
            symbol = symbols[5];
            break;
    }

    return symbol;
}

int playSlots(int cash){
    //declare function's constants
    const int BET = 5;
    const int MATCH_TWO = 5;
    const int MATCH_THREE = 50;

    //declare function's variables
    //establish loop control variable
    int play = 1;
    char symOne;
    char symTwo;
    char symThree;

    //establish an extra char variable to read the user's decision to play again or not
    char decision[5];

    //print instructions for the user
    printf("Let's play the slot machines!\n\n");
    printf("Your cash balance is $%d. The bet is $5.\n", cash);
    printf("Match two symbols to win $5.\n");
    printf("Match all three symbols to win $50.\n\n");

    //determine if user's cash balance is enough to play
    //if user has enough cash, then the game plays
    if(cash >= 5) {
        while(play == 1) {

            //deduct user's money for bet
            cash = cash - BET;

            printf("Spinning...\n\n");

            symOne = randomSymbol();
            symTwo = randomSymbol();
            symThree = randomSymbol();

            //for when the user has the option to play slots again or not
            int decision;

            printf("%c %c %c\n\n", symOne, symTwo, symThree);

            if((symOne == symTwo)&&(symOne == symThree)&&(symTwo == symThree)) {
                cash = cash + MATCH_THREE;

                //provide result
                printf("All three symbols matched\n\n");
            }
            else if((symOne == symTwo)||(symOne == symThree)||(symTwo == symThree)) {
                cash = cash + MATCH_TWO;
                printf("Two symbols matched\n\n");
            }
            else if ((symOne != symTwo)&&(symOne != symThree)&&(symTwo != symThree)){

                cash = cash + 0;
                printf("No symbols matched\n\n");
            }

            //provide the change in the cash amount
            printf("CASH = $%d\n", cash);

            // check if user has enough money to play again before asking
            if (cash >= 5) {
            printf("Would you like to spin again (Yes = 1, No = 0)\n");
            scanf("%d", &decision);
                if (decision == 1) {
                    continue;
                }
                else {
                    break;
                }
            }
            else {


                break;
            }
        }
    }

    //add a thank you for playing IF they played and got results
    printf("Thank you for playing at Knights Casino! Your cash out is $%d\n\n", cash);

    return (cash);

}

//define playScratchOffs function
int playScratchOffs(int cash){
    int type; //store the type of scratch off
    int count; //store the number of scratch offs
    struct OneDollar oneSO;
    struct TwoDollar twoSO;
    struct FiveDollar fiveSO;
    int i; //looping variable
    int play = 1;

    printf("Let's play with scratch offs!\n");
    printf("Players can select from One Dollar, Two Dollar, and Five Dollar tickets.\n");
    printf("Prizes are based on the ticket selected.\n\n");

    while (play == 1) {
        printf("Which type of scratch off would you like\n");
        printf("(1 = One Dollar, 2 = Two Dollar, 5 = Five Dollar)?\n");
        scanf("%d", &type);
        printf("How many scratch offs would you like?\n");
        scanf("%d", &count);

        for(i = 0; i < count; ++i) {
            switch(type) {
                case ONE:
                    if(cash >= type) {
                        cash = cash - type;
                        oneSO = createScratchOffOne(oneSO);
                        displayScratchOffOne(oneSO);
                        cash += cashOneDollar(oneSO);
                    }
                    else {
                        printf("\nPlayer does not have enough money to play!\n\n");
                        i = count;
                    }
                    break;

                case TWO:
                    if(cash >= type) {
                        cash = cash - type;
                        twoSO = createScratchOffTwo(twoSO);
                        displayScratchOffTwo(twoSO);
                        cash += cashTwoDollar(twoSO);
                    }
                    else {
                        printf("\nPlayer does not have enough money to play!\n\n");
                        i = count;
                    }
                    break;

                case FIVE:
                    if(cash >= type) {
                        cash = cash - type;
                        fiveSO = createScratchOffFive(fiveSO);
                        displayScratchOffFive(fiveSO);
                        cash += cashFiveDollar(fiveSO);
                    }
                    else {
                        printf("\nPlayer does not have enough money to play!\n\n");
                        i = count;
                    }
                    break;
            }
        }
        printf("Player's cash $%d\n\n", cash);
        printf("Player, play another scratchoff? (0 = No, 1 = Yes)\n\n");
        scanf("%d", &play);
    }

    return cash;
}

void initializeUsed (char used[SUITS][FACES]){

    //declare two int looping variables
    int s;
    int f;

    for(s = 0; s < SUITS; ++s) {
        for(f = 0; f < FACES; ++f){
            used[s][f] = 0;
        }
    }

}

void initializeDeck (char deck[SUITS][FACES]){

    //declare constant array
    const char face[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};

    //declare two int looping variables
    int s;
    int f;

    for(s = 0; s < SUITS; ++s) {
        for(f = 0; f < FACES; ++f) {
            deck[s][f] = face[f];
        }
    }
}

void printDeck (char deck[SUITS][FACES]){

    //declare two int looping variables
    int s;
    int f;

    for(s = 0; s < SUITS; ++s) {
        for(f = 0; f < FACES; ++f) {
            switch(s) {
                case CLUBS:
                    printf("%c of Clubs\n", deck[s][f]);
                    break;
                case DIAMONDS:
                    printf("%c of Diamonds\n", deck[s][f]);
                    break;
                case HEARTS:
                    printf("%c of Hearts\n", deck[s][f]);
                    break;
                case SPADES:
                    printf("%c of Spades\n", deck[s][f]);
                    break;
            }
        }
    }
}

int deal (char deck[SUITS][FACES], char dealt[SUITS][FACES]){
    const int cardsValue = 52;
    int used = 0;
    int score;
    int suit;
    int face;

    if(cards == cardsValue) {
        cards = 0;
        initializeUsed(dealt);
    }

    while (used == 0) {

        //randomize cards
        suit = rand() % SUITS;
        face = rand() % FACES;

        if (dealt[suit][face] == 0) {
            used = 1;
            dealt[suit][face] = 1;
            cards = cards + 1;
            }
    }

    switch(face) {
        case 0:
            score = face + 2;
            break;
        case 1:
            score = face + 2;
            break;
        case 2:
            score = face + 2;
            break;
        case 3:
            score = face + 2;
            break;
        case 4:
            score = face + 2;
            break;
        case 5:
            score = face + 2;
            break;
        case 6:
            score = face + 2;
            break;
        case 7:
            score = face + 2;
            break;
        case 8:
            score = 10;
            break;
        case 9:
            score = 10;
            break;
        case 10:
            score = 10;
            break;
        case 11:
            score = 10;
            break;
        case 12:
            score = 11;
            break;
    }

    //output randomized card result
    return (score);
}

int results (int player, int dealer){

    //declare local constant integers variable
    const int WIN = 20;
    const int PUSH = 10;
    const int LOSE = 0;

    if(dealer > BUST) {
        printf("Dealer BUSTED.\n\n");
        return 10;
    }
    else if(player == dealer) {
        printf("It was a PUSH.\n\n");
        return 10;
    }
    else if(player > dealer) {
        printf("Player won!!\n\n");
        return 20;
    }
    else {
        printf("Dealer won!!\n\n");
        return 0;
    }
}

//define playBlackJack function
int playBlackJack(int cash){
    //declare local Black Jack constants and variables
    const int BET = 10;
    const int MIN_HIT = 16;
    const int HIT = 1;
    const int STAND = 0;

    //integers
    int play = 1;
    int choice = 0;
    int bust = 0;
    int player = 0;
    int dealer = 0;
    char deck[4][13];
    char dealt[4][13];

    printf("Let's play black jack!\n\n");
    printf("Your cash balance is $%d\n\n", cash);
    printf("The bet is $10\n");
    printf("Dealer must HIT if their score is 16 or less.\n");
    printf("Dealer must STAND if their score is 17 or higher.\n");
    printf("If the player wins the hand, they receive $20.\n");
    printf("If the dealer wins the hand, the $10 bet is lost.\n");
    printf("If it is a PUSH, the player keeps their $10 bet.\n");

    //call ClearScreen function
    clearScreen();

    //determine if the player's cash balance is enough to play
    if(cash < 10) {
        printf("Player does not have enough money to play!\n\n");
        return (cash);
    }

        //shuffle cards
        initializeUsed (dealt);
        printf("Shuffling the cards...\n");

        initializeDeck (deck);
        printf("Here's the deck...\n");
        printDeck (deck);

        //clear screen
        clearScreen();

        printf("Dealing...\n\n");

        while(play == 1) {

            printf("Player's cash $%d\n\n", cash);

            if(cash < 10) {
                printf("Player does not have enough money to play!\n\n");
                play = 0;
                continue;
            }

            //deduct BET from cash
            cash = cash - BET;

            //reinitialize some local variables
            player = 0;
            dealer = 0;
            bust = 0;

            //player score
            player = player + deal(deck, dealt);
            player = player + deal(deck, dealt);
            printf("Player's score %d\n\n", player);

            //dealer score
            dealer = dealer + deal(deck, dealt);
            dealer = dealer + deal(deck, dealt);

            printf("Player, another card? (0 = STAND, 1 = HIT)\n\n");
            scanf("%d", &choice);

            while((choice == HIT) && (player < BUST)) {
                player = player + deal(deck, dealt);
                printf("Player's cash $%d\n\n", cash);
                printf("Player chose to HIT.\n\n");
                printf("Player's score %d\n\n", player);

                if(player > BUST) {
                    bust = 1;
                    printf("Player BUSTED! Dealer wins the hand!\n\n");
                    break;
                }
                else {
                    printf("Player, another card? (0 = STAND, 1 = HIT)\n\n");
                    scanf("%d", &choice);
                }
            }

            if(bust > 0) {
                printf("Player, play another hand? (0 = No, 1 = Yes)\n\n");
                scanf("%d", &play);
                clearScreen();
                continue;
            }
            else {
                if(dealer <= MIN_HIT) {
                    choice = HIT;
                }
                else {
                    choice = STAND;
                }

                while(choice == HIT) {
                    dealer = dealer + deal(deck, dealt);
                    if(dealer <= MIN_HIT) {
                        choice = HIT;
                    }
                    else {
                        choice = STAND;
                    }
                }
            }

            printf("Dealer's score %d\n\n", dealer);

            cash = cash + results (player, dealer);

            printf("Player, play another hand? (0 = No, 1 = Yes)\n\n");
            scanf("%d", &play);

            clearScreen();
        }

        printf("Thank you for playing Black Jack at Knights Casino! Your cash out is $%d\n", cash);

    return (cash);
}

//start the first piece of program
int main() {
    int selectedGame;
    int play = 1;
    int cash = 1000;

    srand(time(NULL));

    welcomeScreen();

    while(play == 1) {
        clearScreen();
        selectedGame = displayMenu();
        clearScreen();

        switch (selectedGame) {
            case SLOTS:
                cash = playSlots(cash);
                break;
            case SCRATCH:
                cash = playScratchOffs(cash);
                break;
            case BLACKJACK:
                cash = playBlackJack(cash);
                break;
            case EXIT:
                selectedGame = 0;
                return 0;
        }

        printf("\nPlayer's cash $%d\n\n", cash);
        printf("Player, play another game? (0 = No, 1 = Yes)\n\n");
        scanf("%d", &play);
    }

    return 0;
}
