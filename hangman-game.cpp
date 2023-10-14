#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <set>

#include <algorithm>

// Prototyping functions
char guessLetter(std::string &letters, std::string &pickedLetters);
bool checkLetterInWord(std::string randomWord, char guessedLetter);
bool matchingCharactersofStrings(std::string &alphabetLetters, std::string randomWord);

// Main
int main()
{

    // Initialize array of possible answers
    std::string words[13] = {"squat", "dinner", "laser", "button",
                             "explorer", "empty", "assist", "number",
                             "sunny", "ranger", "messy", "robot", "pointer"};

    // Letters that have NOT been picked
    std::string alphabetLetters = "abcdefghijklmnopqrstuvwxyz";

    // Letters that have BEEN picked
    std::string pickedLetters = "";

    //* Initialize random seed for the rand function: *
    // The random seed is initialized to a value
    // representing the current time (calling time)
    // to generate a different value every time the program is run.
    srand(time(NULL));

    // Generate a random index using a seed
    int randomIndex = std::rand() % 13;

    // Randomly pick word
    std::string randomWord = words[randomIndex];

    // Initialize new variables
    // Generate preview using the length of the randomly generated word
    // Letters at index: 2, 4, 6, 8, ...
    std::string preview = "[ _";
    for (int i = 0; i < randomWord.length() - 1; i++)
    {
        preview += " _";
    }
    preview += " ]";

    std::cout << "\nPreview of the word to guess: \n"
              << preview << std::endl
              << std::endl;

    char letter;
    int timesGuessed = 0;
    while (timesGuessed < 8)
    {
        // Let the player guess a letter
        letter = guessLetter(alphabetLetters, pickedLetters);

        // Check if the letter is in the word to guess
        bool checkForLetter;
        checkForLetter = checkLetterInWord(randomWord, letter);

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

            std::cout << "\nCorrectly guessed letters so far: \n"
                      << preview << std::endl;
            std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
                      << std::endl;
        }

        // Display remaining lives
        if (checkForLetter == true)
        {
        }
        else
        {
            timesGuessed += 1;
            std::cout << "X Remaining lives: " << (8 - timesGuessed) << std::endl
                      << std::endl;
            std::cout << "\nCorrectly guessed letters so far: \n"
                      << preview << std::endl
                      << std::endl;
            std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
                      << std::endl;
        }

        // End if the guessed letters match the dedicated word
        if (matchingCharactersofStrings(pickedLetters, randomWord) == true)
        {
            preview.erase(remove(preview.begin(), preview.end(), '['), preview.end());
            preview.erase(remove(preview.begin(), preview.end(), ']'), preview.end());
            std::cout << "Correctly guessed the word:" << preview << "\n"
                      << std::endl;
            break;
        }
    };

    if (timesGuessed == 8)
    {
        std::cout << "No more lives left! You lost.\nThe word to guess would have been: " << randomWord << std::endl;
    }
    return 0;
}

// Defining functions
char guessLetter(std::string &letters, std::string &pickedLetters)
{
    char guessedLetter;

    do
    {
        std::cout << "Guess a letter: ";
        std::cin >> guessedLetter;              // Get user input from the keyboard
        guessedLetter = tolower(guessedLetter); // Lower capitalized letter

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
    pickedLetters += guessedLetter;

    return guessedLetter;
};

// Check if the picked letter is part of the randomly picked word
bool checkLetterInWord(std::string randomWord, char guessedLetter)
{

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

// Check if string contains NONE of the characters
bool matchingCharactersofStrings(std::string &alphabetLetters, std::string randomWord)
{
    std::set<char> s1(alphabetLetters.begin(), alphabetLetters.end());
    std::set<char> s2(randomWord.begin(), randomWord.end());
    std::set<char> result;
    std::set_intersection(
        s1.begin(), s1.end(), s2.begin(), s2.end(),
        std::inserter(result, result.begin()));
    return result == s2;
}