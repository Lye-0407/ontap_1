#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <iostream> 
#include <string> 
#include <vector> 

#define MAX_ATTEMPTS 6 
  
using namespace std; 
  
class HangmanGame { 
public: 

    HangmanGame() 
    { 
        srand(static_cast<unsigned int>(time(nullptr))); 
        secretWord = getRandomWord(); 
        currentWord = string(secretWord.length(), '_'); 
        attemptsLeft = MAX_ATTEMPTS; 
    } 

    void play() 
    { 
        cout << "Welcome to Hangman!" << endl; 
        cout << "Category: Fruits" << endl; 
        cout << "You have " << attemptsLeft 
             << " attempts to guess the fruit name."
             << endl; 

        while (attemptsLeft > 0) { 
            displayGameInfo(); 
            char guess; 
            cout << "Guess a letter: "; 
            cin >> guess; 
  
            if (isalpha(guess)) { 
                guess = tolower(guess); 
                if (alreadyGuessed(guess)) { 
                    cout << "You've already guessed that "
                            "letter."
                         << endl; 
                } 
                else { 
                    bool correctGuess 
                        = updateCurrentWord(guess); 

                    if (correctGuess) { 
                        cout << "Good guess!" << endl; 

                        if (currentWord == secretWord) { 
                            displayGameInfo(); 
                            cout << "Congratulations! You "
                                    "guessed the word: "
                                 << secretWord << endl; 
                            return; 
                        } 
                    } 
                    else { 
                        cout << "Incorrect guess." << endl; 
                        attemptsLeft--; 
                        drawHangman(attemptsLeft); 
                    } 
                } 
            } 
            else { 
                cout << "Please enter a valid letter."
                     << endl; 
            } 
        } 
  
        if (attemptsLeft == 0) { 
            displayGameInfo(); 
            cout << "You've run out of attempts. The word "
                    "was: "
                 << secretWord << endl; 
        } 
    } 
  
private: 
    string secretWord; 
    string currentWord; 
    int attemptsLeft; 
    vector<char> guessedLetters; 

    string getRandomWord() 
    { 
        vector<string> words 
            = { "apple", "banana", "cherry", "grape", 
                "kiwi" }; 
        int index = rand() % words.size(); 
        return words[index]; 
    } 

    bool alreadyGuessed(char letter) 
    { 
        return find(guessedLetters.begin(), 
                    guessedLetters.end(), letter) 
               != guessedLetters.end(); 
    } 

    bool updateCurrentWord(char letter) 
    { 
        bool correctGuess = false; 
        for (int i = 0; i < secretWord.length(); i++) { 
            if (secretWord[i] == letter) { 
                currentWord[i] = letter; 
                correctGuess = true; 
            } 
        } 
        guessedLetters.push_back(letter); 
        return correctGuess; 
    } 

    void displayGameInfo() 
    { 
        cout << "Word: " << currentWord << endl; 
        cout << "Attempts left: " << attemptsLeft << endl; 
        cout << "Guessed letters: "; 
        for (char letter : guessedLetters) { 
            cout << letter << " "; 
        } 
        cout << endl; 
    } 
  
    void drawHangman(int attemptsLeft) 
    { 
        if (attemptsLeft == 5) { 
            cout << "   _____" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |     O" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
        else if (attemptsLeft == 4) { 
            cout << "   _____" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |     O" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
        else if (attemptsLeft == 3) { 
            cout << "   _____" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |     O" << endl; 
            cout << "  |    /|" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
        else if (attemptsLeft == 2) { 
            cout << "   _____" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |     O" << endl; 
            cout << "  |    /|\\" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
        else if (attemptsLeft == 1) { 
            cout << "   _____" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |     O" << endl; 
            cout << "  |    /|\\" << endl; 
            cout << "  |    /" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
        else if (attemptsLeft == 0) { 
            cout << "   _____" << endl; 
            cout << "  |     |" << endl; 
            cout << "  |     O" << endl; 
            cout << "  |    /|\\" << endl; 
            cout << "  |    / \\" << endl; 
            cout << "  |" << endl; 
            cout << "  |" << endl; 
        } 
    } 
}; 
  
// driver code 
int main() 
{ 
  
    HangmanGame game; 
    game.play(); 
  
    return 0; 
}