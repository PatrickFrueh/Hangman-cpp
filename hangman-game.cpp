#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototyping functions
char guessLetter();
bool compareLetters();

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
    std::string word = words[randomIndex];

    //* Console output: *
    char letter;
    letter = guessLetter();

    std::cout << "Your letter: " << letter << std::endl;
    // std::cout << words[randomIndex] << std::endl;

    return 0;
}

// Defining functions
char guessLetter()
{
    char guessedLetter;
    std::cout << "Guess a letter: "; // Type a number and press enter
    std::cin >> guessedLetter;       // Get user input from the keyboard

    // Remove from pool of possible letters and check if already picked ! {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z}

    return guessedLetter;
};

// // Check if the picked letter is part of the randomly picked word
// bool checkLetterInWord(std::string word, char guessedLetter){
//     // if isinword: return true
//     // else: return false
// };

// @@@
// Depending on outcome -> add one to 7 limit counter;
// or replace hidden message with correct one: how would this be done?