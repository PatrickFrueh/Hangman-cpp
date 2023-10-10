#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include <algorithm>

// Prototyping functions
char guessLetter(std::string &letters);
bool checkLetterInWord(std::string randomWord, char guessedLetter);

// Main
int main()
{

    // Initialize array of possible answers
    std::string words[13] = {"Squat", "Dinner", "Laser", "Button",
                             "Explorer", "Empty", "Assist", "Number",
                             "Sunny", "Ranger", "Messy", "Robot", "Pointer"};

    // // Letters that have NOT been picked
    std::string alphabetLetters = "abcdefghijklmnopqrstuvwxyz";

    //* Initialize random seed for the rand function: *
    // The random seed is initialized to a value
    // representing the current time (calling time)
    // to generate a different value every time the program is run.
    srand(time(NULL));

    // Generate a random index using a seed
    int randomIndex = std::rand() % 13;

    // Randomly pick word
    // std::string randomWord = words[randomIndex];

    // Interim: Use "Pointer" as fixed word
    std::string randomWord = "pointepr";

    // Initialize new variables
    // Generate preview using the length of the randomly generated word
    // Letters at position: 3, 5, 7, 9, ...
    std::string preview = "[ _";
    for (int i = 0; i < randomWord.length() - 1; i++)
    {
        preview += " _";
    }
    preview += " ]";

    std::cout << "Preview of the word to guess: " << preview << std::endl;

    char letter;
    int timesGuessed = 0;
    while (timesGuessed < 8)
    {
        // Let the player guess a letter
        letter = guessLetter(alphabetLetters);

        // Check if the letter is in the word to guess
        bool checkForLetter;
        checkForLetter = checkLetterInWord(randomWord, letter);
        std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

        // Preview with indices of correctly guessed letter
        int index = 0;
        while ((index = randomWord.find(letter, index)) != std::string::npos)
        {
            // Place letter in the preview list
            if (index == 0)
            {
                preview[(2 * index) + 2] = toupper(letter); // Capitalize if its the first letter
            }
            else
            {
                preview[(2 * index) + 2] = letter;
            }

            index += 1;

            std::cout << "Correctly guessed letters: " << preview << std::endl;
        }

        // Display remaining lives
        if (checkForLetter == true)
        {
        }
        else
        {
            timesGuessed += 1;
            std::cout << "Remaining lives: " << (8 - timesGuessed) << std::endl;
        }
    };

    // End of the game
    // @@@ Winning doesn't actually lead to winning rn
    if (timesGuessed == 8)
    {
        std::cout << "No more lives left!\nThe word to guess would have been: " << randomWord << std::endl;
    }
    else
    {
        // @@@ Check if all missing letters from string are in word
        std::cout << "Correctly guessed the word:" << randomWord << std::endl;
    };

    return 0;
}

// Defining functions
char guessLetter(std::string &letters)
{
    char guessedLetter;

    do
    {
        std::cout << "Guess a letter: ";
        std::cin >> guessedLetter; // Get user input from the keyboard

        // Checks if the letter isalphabet
        if (!isalpha(guessedLetter))
        {
            printf("Make sure you pick a valid letter, i.e. (a-z)\n");
        }

        // Pick a letter that has NOT been picked yet: if "guessedLetter" is part of "letters" -> break
        if (isalpha(guessedLetter) && !(letters.find(guessedLetter) != std::string::npos)) // found in string
        {
            printf("Make sure you pick a letter that has not been picked yet!\n");
        }

        // Guessed letter not an alphabet letter OR in the letters list
    } while (!isalpha(guessedLetter) || (letters.find(guessedLetter) == std::string::npos));

    std::cout << "The first entered letter will be used: " << guessedLetter << std::endl;

    // Remove guessed letter from string of possible letters
    letters.erase(std::remove(letters.begin(), letters.end(), guessedLetter), letters.end());

    return guessedLetter;
};

// Check if the picked letter is part of the randomly picked word
bool checkLetterInWord(std::string randomWord, char guessedLetter)
{
    // @@@ Make randomWord, guessesdLetter small

    // Check if the guessedLetter is in in the randomWord
    if (randomWord.find(guessedLetter) != std::string::npos)
    {
        std::cout << "You guessed correctly!" << std::endl;
    }
    else
    {
        std::cout << "You guessed incorrectly." << std::endl;
        return false;
    };

    return true;
};
