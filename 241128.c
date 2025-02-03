/*******************************************************************************

    This is to certify that this project is my own work, based on my
    personal efforts in studying and applying the concepts learned. I have
    constructed the functions and their respective algorithms and
    corresponding code by myself.

    The program was run, tested, and debugged by my own efforts. I further
    certify that I have not copied in part or whole or otherwise plagiarized
    the work of other students and/or persons.

    Jon Chester C. Donguines, DLSU ID# 12413933

*******************************************************************************/

/*******************************************************************************

    Description:        A simple but fun math game based on the style of
                        popular arcade game "Space Invaders."

    Programmed by:      Donguines, Jon Chester C. - S28
    
    Last modified:      2024.11.24
    
    Version:            v241124
    
    Acknowledgements:   ASCII art generated using patorjk.com
    
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>             // For rand() [Random value]
#include <conio.h>              // For getch() [Press any key...]
#include <time.h>               // For seeding random integer

void clearScreen(int);

void printError();

void printDivider();

void printFace(int);

void printChest(int);

void printXeno(int);

void printQueen(int);

void printMainMenu();

float displayMainMenu();

void displayExit();

void displayHowToPlay();

void saveHighScore(int, int, int*, int*, int*, int*, int*,
                             int*, int*, int*, int*, int*);

void displayHighScores(int, int, int, int, int, int, int, int, int, int);

int askID();

int randomNum(int, int);

void printAliens(int, float*, float*, float*, float*);

void displayStats(int, int, int);

int checkAnswers(float, int*);

int askAnswers(int*, int, float, float, float, float);

void displayEnd(int);

int play();

int main()
{
    clearScreen(100);
    
    float fMenuChoice;
    
    // Temporarily stores user ID and score for sorting high scores
    int nTempUser, nTempScore;
    
    // Initialize top scores as -1 to move them to bottom if user gets zero
    int nScore1 = -1,
        nScore2 = -1,
        nScore3 = -1,
        nScore4 = -1,
        nScore5 = -1;
    
    // Initialize top user IDs as zero
    int nUser1 = 0,
        nUser2 = 0,
        nUser3 = 0,
        nUser4 = 0,
        nUser5 = 0;

    do
    {
        // Clear screen to display menu at bottom
        clearScreen(100);
        fMenuChoice = displayMainMenu();

        // If else for float values
        // Numbers with decimal digits will be invalid

        // Play game
        if(fMenuChoice == 1)
        {
            // Ask user for ID
            clearScreen(100);
            nTempUser = askID();

            // Start game
            clearScreen(100);
            nTempScore = play();

            // Save high score
            saveHighScore(nTempUser, nTempScore,
                         &nScore1, &nScore2, &nScore3, &nScore4, &nScore5,
                         &nUser1,  &nUser2,  &nUser3,  &nUser4,  &nUser5);
        }
        // How to play
        else if(fMenuChoice == 2)
        {
            clearScreen(100);
            displayHowToPlay();
        }
        // High scores
        else if(fMenuChoice == 3)
        {
            clearScreen(100);
            displayHighScores(nScore1, nScore2, nScore3, nScore4, nScore5,
                              nUser1,  nUser2,  nUser3,  nUser4,  nUser5);
        }
       
    }
    while(fMenuChoice == 1 || fMenuChoice == 2 || fMenuChoice == 3);
    
    displayExit();

    return 0;
}



// "Clears" the screen
// Precondition: nLineCount is a positive integer (set by programmer)
// @param nLineCount is the number of '\n' characters to be printed
void clearScreen(int nLineCount)
{
    // Prints new line nLineCount times
    for(int nCounter = 0; nCounter < nLineCount; nCounter++)
    {        
        printf("\n");
    }
}

// Prints colored error message
// NOTE: "\x1b[31m" and "\x1b[0m" are ANSI escape codes
void printError()
{
    // ANSI escape sequence (31 = red)
    printf("\x1b[31mERROR:\x1b[0m Invalid Entry! Try again.\n");
}

// Prints screen divider
void printDivider()
{
    printf("============================================================\n");
}

// Prints yellow facehugger nCount times
// Precondition: nCount is a positive integer
// @param nCount is the number of Facehuggers to be printed
void printFace(int nCount)
{
    for(int nCounter = 0; nCounter < nCount; nCounter++)
        // ANSI escape sequence (33 = yellow)
        printf("\x1b[33m//(~O~)\\\\ ");
    
    // Revert color
    printf("\x1b[0m");
}

// Prints red chestbuster nCount times
// Precondition: nCount is a positive integer
// @param nCount is the number of Chestbusters to be printed
void printChest(int nCount)
{
    for(int nCounter = 0; nCounter < nCount; nCounter++)
        // ANSI escape sequence (31 = red)
        printf("\x1b[31m\\\\<^o^>// ");
    
    // Revert color
    printf("\x1b[0m");
}

// Prints green xenomorph nCount times
// Precondition: nCount is a positive integer
// @param nCount is the number of Xenomorphs to be printed
void printXeno(int nCount)
{
    for(int nCounter = 0; nCounter < nCount; nCounter++)
        // ANSI escape sequence (32 = green)
        printf("\x1b[32m(((((((O,,,o) ");
    
    // Revert color
    printf("\x1b[0m");
}

// Prints magenta queen nCount times
// Precondition: nCount is a positive integer
// @param nCount is the number of Queens to be printed
void printQueen(int nCount)
{
    for(int nCounter = 0; nCounter < nCount; nCounter++)
        // ANSI escape sequence (35 = magenta)
        printf("\x1b[35m)))O***O((( ");
    
    // Revert color
    printf("\x1b[0m");
}

// Displays main menu
void printMainMenu()
{
    int nVer = 241124;
    
    // SpaceInvaders ASCII Art
    printDivider();
    printf("\x1b[34m    ____                  ____                 __\n");
    printf("   / __/__  ___ ________ /  _/__ _  _____ ____/ /__ _______\n");
    printf("  _\\ \\/ _ \\/ _ `/ __/ -_)/ // _ \\ |/ / _ `/ _  / -_) __(_-<\n");
    printf(" /___/ .__/\\_,_/\\__/\\__/___/_//_/___/\\_,_/\\_,_/\\__/_/ /___/");
    printf("\n    /_/\x1b[0m%45sv%d\n", "", nVer); // version number
    
    // Menu Options
    printDivider();
    printf("%24s%s\n", "[1] ", "Play Game");
    printf("%24s%s\n", "[2] ", "How to Play");
    printf("%24s%s\n", "[3] ", "High Scores");
    printf("%24s%s\n", "[4] ", "Quit Game");

    printDivider();
    printf("%35s", "Choose option: ");
}

// Displays main menu and asks user for menu option
// @return the option chosen by the user
float displayMainMenu()
{
    float fMenuChoice;
    
    do
    {
        // Reset value after first run / Invalid entry by default
        fMenuChoice = 0;

        printMainMenu();

        if(scanf("%f", &fMenuChoice) != 1)
        {
            // Prevent loop when entering char
            while(getchar() != '\n');
            
            // Display error when option is a char/str
            clearScreen(100);
            printError();
        }

        // Display error when option is an invalid number
        else if(fMenuChoice != 1 && fMenuChoice != 2 
             && fMenuChoice != 3 && fMenuChoice != 4)
        {
            clearScreen(100);
            printError();
        }
    }
    // Ask again when invalid
    while(fMenuChoice != 1 && fMenuChoice != 2
       && fMenuChoice != 3 && fMenuChoice != 4);

    return fMenuChoice;
}

// Displays exit screen with aliens
void displayExit()
{
    clearScreen(100);

    printDivider();

    printf("\n\n%33s", "Thank you for playing");
    printf("\x1b[34m SpaceInvaders\x1b[0m!\n");
    
    // Prints aliens :3
    printf("\n%11s", "");
    printFace(4);
    printf("\n%11s", "");
    printChest(4);
    printf("\n%17s", "");
    printXeno(2);
    printf("\n%25s", "");
    printQueen(1);

    printf("\n\n\n");
    printDivider();

    printf("Press any key to continue... ");
    getch();
}

// Displays how to play screen
void displayHowToPlay()
{
    // First page
    printDivider();
    printf("%35s%24s\n", "HOW TO PLAY", "1/2");
    
    printDivider();
    printf("\n The player must compute the number of shots by multiplying\n");
    printf(" each number of aliens by their corresponding HP (shown on\n");
    printf(" next page). The player starts with 3 lives, losing 1 life\n");
    printf(" per incorrect answer. A correct answer gives 1 point per\n");
    printf(" level. The player wins by completing all 10 levels and\n");
    printf(" earning a total of 10 points.\n\n");
    
    printDivider();
    printf("Press any key to continue... ");
    getch();

    clearScreen(100);
    
    // Second page
    printDivider();
    printf("%35s%24s\n", "HOW TO PLAY", "2/2");
    
    printDivider();
    printf("\n%16s%22s%11s\n\n", "Name", "Appearance", "HP");
    printf("%22s\x1b[33m%15s\x1b[0m%12s\n", "Facehugger", "//(~O~)\\\\", "1");
    printf("%23s\x1b[31m%14s\x1b[0m%12s\n", "Chestbuster", "\\\\<^o^>//", "2");
    printf("%21s\x1b[32m%20s\x1b[0m%8s\n", "Xenomorph", "(((((((O,,,o)", "4.2");
    printf("%17s\x1b[35m%22s\x1b[0m%10s\n\n", "Queen", ")))O***O(((", "7.3");
    
    printDivider();
    printf("Press any key to return to main menu... ");
    getch();
}

// Saves and swaps high scores and user IDs accordingly
// @param nTempUser is the user ID of the latest player
// @param nTempScore is the score of the latest player
// @param *nScore1 is the highest score
// @param *nScore2 is the 2nd highest score
// @param *nScore3 is the 3rd highest score
// @param *nScore4 is the 4th highest score
// @param *nScore5 is the 5th highest score
// @param *nUser1 is the User ID of the player with the highest score
// @param *nUser2 is the User ID of the player with the 2nd highest score
// @param *nUser3 is the User ID of the player with the 3rd highest score
// @param *nUser4 is the User ID of the player with the 4th highest score
// @param *nUser5 is the User ID of the player with the 5th highest score
void saveHighScore(int nTempUser, int nTempScore,
        int *nScore1, int *nScore2, int *nScore3, int *nScore4, int *nScore5,
        int *nUser1,  int *nUser2,  int *nUser3,  int *nUser4,  int *nUser5)
{
    int nSwapScore = 0, nSwapUser = 0;

    // Check if duplicate user ID is found
    if(nTempUser == *nUser1 || nTempUser == *nUser2 || nTempUser == *nUser3 
                            || nTempUser == *nUser4 || nTempUser == *nUser5)
    {
        // Replace scores of existing users if higher
        if(nTempUser == *nUser1 && nTempScore > *nScore1)
        {
            *nScore1 = nTempScore;
        }
        else if(nTempUser == *nUser2 && nTempScore > *nScore2)
        {
            *nScore2 = nTempScore;
        }
        else if(nTempUser == *nUser3 && nTempScore > *nScore3)
        {
            *nScore3 = nTempScore;
        }
        else if(nTempUser == *nUser4 && nTempScore > *nScore4)
        {
            *nScore4 = nTempScore;
        }
        else if(nTempUser == *nUser5 && nTempScore > *nScore5)
        {
            *nScore5 = nTempScore;
        }

        // Check and shift from bottom to top of high scores
        if (*nScore5 > *nScore4)
        {
            nSwapScore = *nScore5;
            *nScore5 = *nScore4;
            *nScore4 = nSwapScore;

            nSwapUser = *nUser5;
            *nUser5 = *nUser4;
            *nUser4 = nSwapUser;
        }
        if (*nScore4 > *nScore3)
        {
            nSwapScore = *nScore4;
            *nScore4 = *nScore3;
            *nScore3 = nSwapScore;

            nSwapUser = *nUser4;
            *nUser4 = *nUser3;
            *nUser3 = nSwapUser;
        }
        if (*nScore3 > *nScore2)
        {
            nSwapScore = *nScore3;
            *nScore3 = *nScore2;
            *nScore2 = nSwapScore;

            nSwapUser = *nUser3;
            *nUser3 = *nUser2;
            *nUser2 = nSwapUser;
        }
        if (*nScore2 > *nScore1)
        {
            nSwapScore = *nScore2;
            *nScore2 = *nScore1;
            *nScore1 = nSwapScore;

            nSwapUser = *nUser2;
            *nUser2 = *nUser1;
            *nUser1 = nSwapUser;
        }
    }
    // Execute if new nUserID
    else if(nTempUser != *nUser1 && nTempUser != *nUser2 && nTempUser != *nUser3 
                                && nTempUser != *nUser4 && nTempUser != *nUser5)
    {
        if(nTempScore > *nScore5)
        {
            // Insert into 5th position
            *nScore5 = nTempScore;
            *nUser5 = nTempUser;
        }
        if(nTempScore > *nScore4)
        {
            // Shift and insert into 4th position
            *nScore5 = *nScore4;
            *nUser5 = *nUser4;

            *nScore4 = nTempScore;
            *nUser4 = nTempUser;
        }
        if(nTempScore > *nScore3)
        {
            // Shift and insert into 3rd position
            *nScore4 = *nScore3;
            *nUser4 = *nUser3;

            *nScore3 = nTempScore;
            *nUser3 = nTempUser;
        }
        if(nTempScore > *nScore2)
        {
            // Shift and insert into 2nd position
            *nScore3 = *nScore2;
            *nUser3 = *nUser2;

            *nScore2 = nTempScore;
            *nUser2 = nTempUser;
        }
        if(nTempScore > *nScore1)
        {
            // Insert into 1st position
            *nScore2 = *nScore1;
            *nUser2 = *nUser1;

            *nScore1 = nTempScore;
            *nUser1 = nTempUser;
        }
    }
}

// Displays high score screen
// @param nScore1 is the highest score
// @param nScore2 is the 2nd highest score
// @param nScore3 is the 3rd highest score
// @param nScore4 is the 4th highest score
// @param nScore5 is the 5th highest score
// @param nUser1 is the user ID of the player with the highest score
// @param nUser2 is the user ID of the player with the 2nd highest score
// @param nUser3 is the user ID of the player with the 3rd highest score
// @param nUser4 is the user ID of the player with the 4th highest score
// @param nUser5 is the user ID of the player with the 5th highest score
void displayHighScores(int nScore1, int nScore2, int nScore3, 
                                    int nScore4, int nScore5,
                        int nUser1, int nUser2,  int nUser3,  
                                    int nUser4,  int nUser5)
{  
    printDivider();
    printf("%43s\n", "HIGH SCORES (this session)");

    printDivider();
    printf("\n%16s%18s%15s\n", "Rank", "Player ID#", "Score");

    // Print user ID and score if available
    // Else leave blank

    printf("%14s", "1)");
    if(nUser1 > 0)
    {
        printf("%18d%17d", nUser1, nScore1);
    }

    printf("\n%14s", "2)");
    if(nUser2 > 0)
    {
        printf("%18d%17d", nUser2, nScore2);
    }

    printf("\n%14s", "3)");
    if(nUser3 > 0)
    {
        printf("%18d%17d", nUser3, nScore3);
    }

    printf("\n%14s", "4)");
    if(nUser4 > 0)
    {
        printf("%18d%17d", nUser4, nScore4);
    }

    printf("\n%14s", "5)");
    if(nUser5 > 0)
    {
        printf("%18d%17d", nUser5, nScore5);
    }
    
    printf("\n\n");
    
    printDivider();
    printf("Press any key to return to main menu... ");
    getch();
}

// Asks and validates user ID
// @return the user ID of player when valid
int askID()
{
    int nUserID;
    
    do
    {
        printDivider();
        printf("%32s\n", "PLAY");
        printDivider();
        printf("\n\n\n");

        printf("%52s\n", "Enter 8-digit user ID below to start playing");
        printf("\n\n\n\n");
        printDivider();

        printf("%30s", "User ID: ");

        if(scanf("%d", &nUserID) != 1)
        {
            // Prevent loop when entering char
            while(getchar() != '\n');
            
            // Display error when option is a char/str
            clearScreen(100);
            printError();
        }
        // Display error when option is out of range
        else if(nUserID < 10000000 || nUserID > 99999999)
        {
            clearScreen(100);
            printError();
        }
    }
    while(nUserID < 10000000 || nUserID > 99999999);

    return nUserID;
}

// Returns a random value within a range
// Preconditions: nMin is a positive integer
//                nMax is a positive integer
// @param nMin is the minimum number to be generated
// @param nMax is the maximum number to be generated
// @return the number of aliens to be printed
int randomNum(int nMin, int nMax)
{
    int nAlienCount = rand() % (nMax - nMin + 1) + nMin;

    return nAlienCount;
}

// Prints random amount of aliens depending on level
// Preconditions: nLevel is an integer from 1 to 10
// @param nLevel will be used to determine the range of aliens to be displayed
//      Levels 1-4:   2-4 aliens
//      Levels 5-7:   4-8 aliens
//      Levels 8-10: 6-10 aliens (exc. Queen)
void printAliens(int nLevel, float *fAnsFace, float *fAnsChest,
                             float *fAnsXeno, float *fAnsQueen)
{    
    int nMin, nMax;
    float fLivesFace = 1, fLivesChest = 2, fLivesXeno = 4.2, fLivesQueen = 7.3;

    // Assign count vars to zero for levels with only some alien types
    int nCountFace = 0, nCountChest = 0, nCountXeno = 0, nCountQueen = 0;
    
    // Number of aliens to be printed per level
    // Can be adjusted in the future
    if(nLevel <= 4)
    {
        nMin = 1;
        nMax = 5;
    }
    else if(nLevel <= 7)
    {
        nMin = 4;
        nMax = 9;
    }
    else if(nLevel <= 10)
    {
        nMin = 7;
        nMax = 12;
    }

    // Levels where each alien type will be printed
    if(nLevel >= 1 && nLevel <= 10) // Added conditional for future proofing
    {
        printFace(nCountFace = randomNum(nMin, nMax));
        // Assign generated number as correct answer
        *fAnsFace = nCountFace * fLivesFace;
    }

    if(nLevel != 2 && nLevel != 5)
    {
        printChest(nCountChest = randomNum(nMin, nMax));
        // Assign generated number as correct answer
        *fAnsChest = nCountChest * fLivesChest;
    }

    if(nLevel % 2 == 0)
    {
        printXeno(nCountXeno = randomNum(nMin, nMax));
        // Assign generated number as correct answer
        *fAnsXeno = nCountXeno * fLivesXeno;
    }

    if(nLevel == 10)
    {
        printQueen(nCountQueen = randomNum(1, 5)); // nMax 5 queens
        // Assign generated number as correct answer
        *fAnsQueen = nCountQueen * fLivesQueen;
    }
}

// Displays level information (score, level, lives)
// Preconditions: nScore, nLevel, and nLives are positive integers
// @param nScore is the current score
// @param nLevel is the current game level
// @param nLives is the current amount of lives
void displayStats(int nScore, int nLevel, int nLives)
{
    printDivider();
    printf("%12s%20s%20s\n", "SCORE", "LEVEL", "LIVES");
    printf("%7s%-20d%-20d%d\n", "", nScore, nLevel, nLives);
    printDivider();
}

// Checks the answer provided by user; decrements user's lives when incorrect
// Preconditions: fAnsCorrect is a positive integer
//                *nLives is a positive integer from 1-3
// @param fAnsCorrect is the correct answer
// @param *nLives is the number of lives the user currently has
// @return nFlag to determine if user gets a score in the level
int checkAnswers(float fAnsCorrect, int *nLives)
{
    float fAnsUser;
    int nFlag = 1;

    if(scanf("%f", &fAnsUser) != 1)
    {
        // Prevent loop when entering char
        while(getchar() != '\n');
    }

    // Round the answers to avoid float precision errors (mismatch)
    int nUserRounded = fAnsUser * 10 + 0.5;
    int nCorrectRounded = fAnsCorrect * 10 + 0.5;
    
    // Execute when answer is incorrect
    if(nUserRounded != nCorrectRounded)
    {
        // Decrement life if answer is incorrect
        (*nLives)--;

        // Print "-1 life" in red
        printf("\x1b[31m-1 life\n\x1b[0m");

        // Print correct answer
        printf("\x1b[31mCorrect answer: %.1f\x1b[0m\n", fAnsCorrect);

        nFlag = 0;
    }

    return nFlag;
}

// Asks user for the answers and checks if they are correct
// Preconditions: *nLives is a positive integer from 1-3
//                nLevel is a positive integer from 1-10
//                fAnsFace, fAnsChest, fAnsXeno, fAnsQueen are positive integers
// @param *nLives is the number of lives the user currently has
// @param nLevel is the current level of the user
// @param fAnsFace is the answer for Facehugger provided by the user
// @param fAnsChest is the answer for Chestbuster provided by the user
// @param fAnsXeno is the answer for Xenomorph provided by the user
// @param fAnsQueen is the answer for Queen provided by the user
// @return score earned by user in current level
int askAnswers(int *nLives, int nLevel, float fAnsFace, float fAnsChest,
                                        float fAnsXeno, float fAnsQueen)
{
    int nCorrectFace = 1, nCorrectChest = 1;
    int nCorrectXeno = 1, nCorrectQueen = 1;
    
    if(nLevel >= 1 && nLevel <= 10) // Added conditional for future proofing
    {
        if(*nLives > 0)
        {
            printf("Shoot Facehugger:  ");
            nCorrectFace = checkAnswers(fAnsFace, nLives);
        }
    }

    if(nLevel != 2 && nLevel != 5)
    {
        if(*nLives > 0)
        {
            printf("Shoot Chestbuster: ");
            nCorrectChest = checkAnswers(fAnsChest, nLives);
        }      
    }

    if(nLevel % 2 == 0)
    {
        if(*nLives > 0)
        {
            printf("Shoot Xenomorph:   ");
            nCorrectXeno = checkAnswers(fAnsXeno, nLives);
        }
    }

    if(nLevel == 10)
    {
        if(*nLives > 0)
        {
            printf("Shoot Queen:       ");
            nCorrectQueen = checkAnswers(fAnsQueen, nLives);
        }        
    }

    return nCorrectFace && nCorrectChest && nCorrectXeno && nCorrectQueen;
}

// Displays the end screen when the player completes the game or loses all lives
// Preconditions: nScore is a positive integer from 0-10
// @param nScore is the score of the user after the game
void displayEnd(int nScore)
{
    printf("\n");
    printDivider();
    printf("\n\n");

    printf("\x1b[34m            _____                 ____\n");
    printf("           / ___/__ ___ _  ___   / __ \\_  _____ ____\n");
    printf("          / (_ / _ `/  ' \\/ -_) / /_/ / |/ / -_) __/\n");
    printf("          \\___/\\_,_/_/_/_/\\__/  \\____/|___/\\__/_/\x1b[0m\n\n");

    printf("%23sFinal Score: %d\n", "", nScore);
    printf("\n\n");

    printDivider();
}

// Main game function
// Displays the main game level and contains the game logic
// @return final score of the user
int play()
{
    int nScore = 0;
    int nLives = 3;
    int nLevel, nAllCorrect;
    float fAnsFace = 0,
          fAnsChest = 0,
          fAnsXeno = 0,
          fAnsQueen = 0;
    
    // Repeat until level 10
    for(nLevel = 1; nLevel <= 10; nLevel++)
    {
        // Check if user has lives remaining
        if(nLives > 0)
        {
            printf("\n");
            displayStats(nScore, nLevel, nLives);
            printf("\n");
            
            // Print the aliens in the level
            printAliens(nLevel, &fAnsFace, &fAnsChest, &fAnsXeno, &fAnsQueen);

            printf("\n\n");
            printDivider();
            
            // Ask for answers
            nAllCorrect = askAnswers(&nLives, nLevel, fAnsFace, fAnsChest, 
                                                      fAnsXeno, fAnsQueen);
        }
        
        // Only increment score if all answers in the level are correct
        // Update and store to high score variable
        if(nAllCorrect)
        {
            nScore++;
        }
    }
    
    // End screen
    displayEnd(nScore);

    printf("Press any key to return to the main menu...");
    getch();

    return nScore;
}





/*******************************************************************************

    Changelog:

    v241124
    ~ Fixed float imprecision errors
        ~ Fixed error where correct answer will be marked as incorrect
    - Removed unused variable in play() (nTempScore)

    v241123
    ~ Adjusted difficulty
    ~ Improved changelog
    - Replaced constants with local variables


    v241120
    + Added missed function comments
    ~ Converted missed identifier to follow Hungarian notation
    - Removed unnecessary comments

    v241119
    ~ Converted remaining variable identifiers to follow Hungarian notation

    v241106
    ~ Fixed high score bugs
        ~ No more duplicate IDs
        ~ Scores of existing users now arranged properly
        ~ Score of existing user will not be displayed if lower than previous
    
    v241028
    + Added high score page
        ~ Temporarily stores top 5 scores in the high score page 
        ~ Only in memory (not saved through runs)
    + Added more function comments
    ~ Future-proofed some code
    ~ Changed alien 'lives' to 'HP' in how to play
    
    v241021
    + Added more function comments
    
    v241019
    + Main game logic implemented
        + Assigned correct answers to each alien type (count * lives)
        + Added heck answer function
        + Added working lives
        + Added working score
    + Added game end screen
    ~ Cleaned up some code

    v241015
    + Added randomized alien display function

    v241014
    + Added main game function
    + Added working game level information (dynamic score, level, lives)
    
    v241009
    + Added game level information display
    + Added detailed function comments
    
    v241007
    ~ Placed main() on top
        + Added function prototypes
    ~ Main menu fixes
        ~ Fixed infinite loop on menu when entering char
    + Added User ID screen
        + Added input validation
    
    v241004
    + Added random number function
    + Improved main menu option validation

    v241001
    + Added more comments
    ~ Replaced \t characters with printf() flags for better compatibility
    ~ Revised identifier names

    v240929
    + Added "How to play" option on main menu
    + Added alien types on "How to play" screen

    v240928
    + Added clear screen function
    + Added print alien functions
        + Added colored alien types
    + Added tentative quit screen
    + Added "How to play" screen

    v240927
    + Program started
    + Added tentative welcome menu
    + Added functional menu options

*******************************************************************************/
