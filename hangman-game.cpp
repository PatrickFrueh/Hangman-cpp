#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include <algorithm>

// Prototyping functions
// @@@ Call by reference?
char guessLetter(std::string &letters);
bool checkLetterInWord(std::string randomWord, char guessedLetter);

// Main
int main()
{

    // Initialize array of possible answers
    std::string words[13] = {"Squat", "Dinner", "Laser", "Button",
                             "Explorer", "Empty", "Assist", "Number",
                             "Sunny", "Ranger", "Messy", "Robot", "Pointer"};

    // Letters that have NOT been picked
    std::string alphabetLetters[26] = {"a", "b", "c", "d", "e", "f", "g", "h",
                                       "i", "j", "k", "l", "m", "n", "o", "p",
                                       "q", "r", "s", "t", "u", "v", "w", "x",
                                       "y", "z"};

    //* Initialize random seed for the rand function: *
    // The random seed is initialized to a value
    // representing the current time (calling time)
    // to generate a different value every time the program is run.
    srand(time(NULL));

    // Generate a random index using a seed
    int randomIndex = std::rand() % 13;

    // Randomly pick word
    // std::string randomWord = words[randomIndex];

    // Interim: Use "Number" as fixed word
    std::string randomWord = "Pointer";

    // Initialize new variables
    // Generate preview using the length of the randomly generated word
    // Letters at position: 3, 5, 7, 9, ...
    std::string preview = "[ _";
    for (int i = 0; i < randomWord.length() - 1; i++)
    {
        preview += " _";
    }
    preview += " ]";

    char letter;
    int timesGuessed = 0;
    if (timesGuessed < 8)
    {
        // @@ Print the CorrectlyGuessedWord up until this point
        //

        // @@@ Let the player guess a letter
        letter = guessLetter(alphabetLetters[26]);

        // Check if the letter is in the set word
        bool checkForLetter;
        checkForLetter = checkLetterInWord(randomWord, letter);
        if (checkForLetter == true)
        {
        }
        else
        {
            timesGuessed += 1;
        }

        // @@ Print lives left/timesGuessed
    };

    return 0;
}

// Defining functions
// @@@ Call by reference?
char guessLetter(std::string &letters)
{
    char guessedLetter;

    do
    {
        std::cout << "Guess a letter: "; // Type a number and press enter
        std::cin >> guessedLetter;       // Get user input from the keyboard

        // @@@ LIMIT TO ONE letter

        // Checks if the letter isalphabet
        if (!isalpha(guessedLetter))
        {
            printf("Make sure you pick a valid letter, i.e. (a-z)\n");
        }

        // Pick a letter that has NOT been picked yet
        if (isalpha(guessedLetter) && (letters.find(guessedLetter) != std::string::npos))
        {
            printf("Make sure you pick a letter that has not been picked yet!\n");
        }

        // Meaning: Guessed letter not an alphabet letter OR in the letters list
    } while (!isalpha(guessedLetter) || (letters.find(guessedLetter) != std::string::npos));

    // Remove guessed letter from string of possible letters
    // @@ Remove from pool of possible letters (by check if already picked) ! {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z}
    letters.erase(std::remove(letters.begin(), letters.end(), guessedLetter), letters.end());

    return guessedLetter;
};

// Check if the picked letter is part of the randomly picked word
bool checkLetterInWord(std::string randomWord, char guessedLetter)
{
    // @@ Make randomWord, guessesdLetter small

    // Check if the guessedLetter is in in the randomWord
    if (randomWord.find(guessedLetter) != std::string::npos)
    {
        std::cout << "The guessed letter is part of " << randomWord << std::endl;

        // @@@ int indexRandomWord = randomWord.find(guessedLetter);
        // --> Call by reference: change value of CorrectlyGuessedLetters
    }
    else
    {
        std::cout << "WRONG: " << randomWord << std::endl;
        return false;
    };
    return true;
};
