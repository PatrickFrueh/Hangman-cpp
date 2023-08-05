#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototyping functions
char guessLetter();
bool checkLetterInWord(std::string randomWord, char guessedLetter);

// Main
int main()
{

    // Initialize array of possible answers
    std::string words[13] = {"Squat", "Dinner", "Laser", "Button",
                             "Explorer", "Empty", "Assist", "Number",
                             "Sunny", "Ranger", "Messy", "Robot", "Pointer"};

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
    std::string randomWord = "Number";

    // Initialize some new variables
    char letter;
    int timesGuessed = 0;
    if (timesGuessed < 8)
    {
        // Let the player guess a word
        letter = guessLetter();

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
    };

    return 0;
}

// Defining functions
char guessLetter()
{
    char guessedLetter;
    std::cout << "Guess a letter: "; // Type a number and press enter

    // @@ Check if guessed letter is an actual letter (case-sensitive, symbols, umlaute)

    std::cin >> guessedLetter; // Get user input from the keyboard

    // @@ Remove from pool of possible letters and check if already picked ! {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z}

    return guessedLetter;
};

// Check if the picked letter is part of the randomly picked word
bool checkLetterInWord(std::string randomWord, char guessedLetter)
{
    // @@ Make randomWord, guessesdLetter small

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
