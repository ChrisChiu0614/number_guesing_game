#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function declarations
void displayMenu();// Display the game menu
void displayModeChoice();// Display the mode choice menu
void startGame(int &);// Start the game
void loadingProperty(int &, int &, int &, const int &);// Load game properties based on the selected mode
int getValidatedInput();// Get and validate user input
void provideHint(const int &, const int &);// Provide hints based on the user's guess
int choiceMode();// Get the user's choice of game mode
void finalScore(const int &);// Display the final score and award
void printGoldMedal(); // Print the gold medal
void printSilverMedal();// Print the silver medal
void printBronzeMedal();// Print the bronze medal

// Enumerations for options, modes, and ranges
enum options
{
    START = 1,
    EXIT = 2,

};

enum mode
{
    EASY = 1,
    MEDIUM = 2,
    HARD = 3
};

enum range
{
    EASY_MODE = 50,
    MEDIUM_MODE = 100,
    HARD_MODE = 200
};
enum times
{
    EASY_TIMES = 10,
    MEDIUM_TIMES = 7,
    HARD_TIMES = 5
};

int main()
{
    srand((unsigned int)time(NULL)); // Seed the random number generator
    displayMenu(); // Display the game menu
    int options;
    int mode;
    do
    {
        options = getValidatedInput(); // Get user input
        switch (options)
        {
        case START:
            displayModeChoice(); // Display mode choice menu
            mode = choiceMode(); // Get user's choice of mode

            startGame(mode); // Start the game
            cout << "==============GAME  OVER==============" << endl;
            cout << "Do you want to play again? " << endl;
            cout << "[  1 = YES, 2 = NO   ]" << endl;
            break;
        case EXIT:
            cout << "Bye Bye !" << endl;
            return 1;
            break;
        default:
            break;
        }
    } while (true);
    return 0;
}

/**
 * Function to display the final score and award the appropriate medal
 * @param count - the number of attempts the player made
 */
void finalScore(const int &count)
{
    cout << "[system] Congratulations !! you win !!" << endl;
    cout << "==============Final Score==============" << endl;
    cout << "[system] You made " << count << " attempts." << endl;
    if (count < 3)
    {
        std::cout << "Gold Medal - Congratulations! Outstanding performance!" << std::endl;
        printGoldMedal();
    }
    else if (count >= 3 && count < 5)
    {
        std::cout << "Silver Medal - Well done! Great job!" << std::endl;
        printSilverMedal();
    }
    else if (count >= 5 && count < 7)
    {
        std::cout << "Bronze Medal - Good effort! Keep it up!" << std::endl;
        printBronzeMedal();
    }
}

/**
 * Function to get the user's choice of game mode
 * @return int - the selected game mode
 */
int choiceMode()
{
    int options;
    do
    {
        options = getValidatedInput(); // Get user input
        switch (options)
        {
        case EASY:
            return EASY;
            break;
        case MEDIUM:
            return MEDIUM;
            break;
        case HARD:
            return HARD;
            break;
        default:
            break;
        }
    } while (true);
}

/**
 * Function to display the game menu
 * Provides options to start the game or exit
 */
void displayMenu()
{
    cout << "======================================" << endl;
    cout << "===           WELCOME TO           ===" << endl;
    cout << "===      Number Guessing Game      ===" << endl;
    cout << "===                                ===" << endl;
    cout << "===             BY:Chrs            ===" << endl;
    cout << "===                                ===" << endl;
    cout << "===           1. Start             ===" << endl;
    cout << "===           2. Exit              ===" << endl;
    cout << "===                                ===" << endl;
    cout << "======================================" << endl;
    cout << "[system] Enter your option: ";
}

/**
 * Function to display the mode choice menu
 * Provides options to select game difficulty
 */
void displayModeChoice()
{
    cout << "======================================" << endl;
    cout << "===                                ===" << endl;
    cout << "===         Choice your mode       ===" << endl;
    cout << "===                                ===" << endl;
    cout << "===           1. Easy              ===" << endl;
    cout << "===           2. Medium            ===" << endl;
    cout << "===           3. Hard              ===" << endl;
    cout << "===                                ===" << endl;
    cout << "======================================" << endl;
    cout << "[system] Enter your option: ";
}

/**
 * Function to start the game
 * @param mode - the selected game mode
 */
void startGame(int &mode)
{
    int range;
    int count = 0;
    int times;
    int number;
    int guessing;
    loadingProperty(range, times, number, mode);
    
    while (count < times)
    {
        cout << "[system] You have " << times - count << " attempts remaining. " << endl;
        cout << "[system] Let's guessing... " << endl;
        guessing = getValidatedInput();
        if (guessing == number)
        {
            finalScore(count);
            break;
        }
        else
        {
            provideHint(guessing, number);
        }

        count++;
    }
}

/**
 * Function to load game properties based on the selected mode
 * @param range - the range of the number to guess
 * @param times - the number of attempts allowed
 * @param number - the random number to guess
 * @param mode - the selected game mode
 */
void loadingProperty(int &range, int &times, int &number, const int &mode)
{
    switch (mode)
    {
    case EASY:
        range = EASY_MODE;
        times = EASY_TIMES;
        cout << "[system] You choice EASY MODE." << endl;
        cout << "[system] You have " << EASY_TIMES << " attempts to guess the number. The range is 1 - " << EASY_MODE << ". If you guess correctly, you win."
             << endl;
        break;
    case MEDIUM:
        range = MEDIUM_MODE;
        times = MEDIUM_TIMES;
        cout << "[system] You choice MEDIUM MODE." << endl;
        cout << "[system] You have " << MEDIUM_TIMES << " attempts to guess the number. The range is 1 - " << MEDIUM_MODE << ". If you guess correctly, you win." << endl;
        break;
    case HARD:
        range = HARD_MODE;
        times = HARD_TIMES;
        cout << "[system] You choice HARD MODE." << endl;
        cout << "[system] You have " << MEDIUM_TIMES << " attempts to guess the number. The range is 1 - " << HARD_MODE << ". If you guess correctly, you win." << endl;
        break;
    default:
        break;
    }
    number = (rand() % range) + 1;
}

/**
 * Function to validate user input
 * Ensures that the input is a number
 * @return int - the validated input
 */
int getValidatedInput()
{
    int options;
    while (!(cin >> options))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return options;
}

/**
 * Function to provide a hint based on the user's guess
 * @param guessing - the user's guess
 * @param numbers - the actual number to guess
 */
void provideHint(const int &guessing, const int &numbers)
{
    int distance = abs(numbers - guessing);
    if (distance <= 3)
    {
        cout << "[system] *** Very close! ***" << endl;
    }
    else if (distance <= 10)
    {
        cout << "[system] ** Quite close. **" << endl;
    }
    else if (distance <= 20)
    {
        cout << "[system] * Moderately far. *" << endl;
    }
    else
    {
        cout << "[system] !!! Very far! !!!" << endl;
    }
}

/**
 * Function to print the gold medal
 */
void printGoldMedal()
{
    std::cout << "  *****  " << std::endl;
    std::cout << " *     * " << std::endl;
    std::cout << "* Gold  *" << std::endl;
    std::cout << "* Medal *" << std::endl;
    std::cout << " *     * " << std::endl;
    std::cout << "  *****  " << std::endl;
    std::cout << "   ***   " << std::endl;
    std::cout << "   ***   " << std::endl;
    std::cout << "   ***   " << std::endl;
    std::cout << "   ***   " << std::endl;
    std::cout << "  *****  " << std::endl;
    std::cout << "*********" << std::endl;
}

/**
 * Function to print the silver medal
 */
void printSilverMedal()
{
    std::cout << "  *****  " << std::endl;
    std::cout << " *     * " << std::endl;
    std::cout << "* Silver*" << std::endl;
    std::cout << "* Medal *" << std::endl;
    std::cout << " *     * " << std::endl;
    std::cout << "  *****  " << std::endl;
    std::cout << "   ***   " << std::endl;
    std::cout << "   ***   " << std::endl;
    std::cout << "   ***   " << std::endl;
    std::cout << "   ***   " << std::endl;
    std::cout << "  *****  " << std::endl;
    std::cout << "*********" << std::endl;
}

/**
 * Function to print the bronze medal
 */
void printBronzeMedal()
{
    std::cout << "  *****  " << std::endl;
    std::cout << " *     * " << std::endl;
    std::cout << "* Bronze*" << std::endl;
    std::cout << "* Medal *" << std::endl;
    std::cout << " *     * " << std::endl;
    std::cout << "  *****  " << std::endl;
    std::cout << "   ***   " << std::endl;
    std::cout << "   ***   " << std::endl;
    std::cout << "   ***   " << std::endl;
    std::cout << "   ***   " << std::endl;
    std::cout << "  *****  " << std::endl;
    std::cout << "*********" << std::endl;
}