/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GuessTheWord.cpp
 * Author: anitageorge
 *
 * Created on September 15, 2017, 4:20 PM
 * Compiler Used: 
 * 
 * This is a implementation file of the class GuessTheWord
 */
#include "locale"
#include "cstdlib"
#include "ctime"
#include "GuessTheWord.h"
using namespace std;

/**
 * Constructor to initialize the values of the variables 
 */
GuessTheWord::GuessTheWord() {
    currentState = "";
    currentWord = "";
    currentGuess = "";
    dictionarySize = 0;
}
/**
 * This function loads the words in the file to an array. 
 * In order to make the application case insensitive, the words are all stored in Upper case
 * The parameter is a default parameter, So if the file is not specified by a client, then the application uses default file in the system
 * 
 * @param filename
 */
void GuessTheWord::LoadDictionary(string filename) {
    ifstream input(filename);
    string word;
    locale loc;
    while (input >> word) {
        for(int i=0;i<word.length();i++)
            word[i] = toupper(word[i],loc);
        dictionary[dictionarySize] = word;
        dictionarySize++;
    } 
}
/**
 * Function to randomly select a word from the array
 * Random function seeded with the system time
 * 
 * @return word length
 */
int GuessTheWord::GetSecretWord() {
    srand(time(0));
    int randomWord = rand() % (dictionarySize);
    
    currentWord = dictionary[randomWord];
    
    GenerateHint();

    return currentWord.length();
}

/**
 * Function to generate a hint to the player at the start of a new game
 * Hint is showing one letter in the word that occurs in all position in the word
 */
void GuessTheWord::GenerateHint() {
    int len = currentWord.size();
    for(int i=0; i<len; i++)
        currentState += "_";
    
    srand(time(0));
    int randomLetter = rand() % (len);
    repeat:
    if(randomLetter < len) {
        string tip(1,currentWord.at(randomLetter));
        if(CheckVowel(tip)) {
            currentState.replace(randomLetter, 1, tip);
            string::size_type position = currentWord.find(tip);
            while(position != string::npos) {
                currentState.replace(position, 1, tip);
                position = currentWord.find(tip , position+1);
            }
        }
        else {
            randomLetter = rand() % (len);
            goto repeat;
        }
    }
}
/**
 * Function to check if the hint letter is a vowel or not
 * Also checks the edge case of words containing only vowels
 * 
 * @param str
 * @return true for vowel letter and false for consonant
 */
bool GuessTheWord::CheckVowel(string str) {
    string::size_type vowelpos = vowels.find(str);
   
    int i = 0;
    string::size_type vowelposword[currentWord.length()];
    while(i < currentWord.length()) {
        vowelposword[i] = vowels.find(currentWord.at(i));
        if(vowelposword[i] == string::npos)
            break;
        i++;
    }
    if(i == currentWord.length()) {
        return true;
    }
    else if(vowelpos != string::npos) {
        return false;
    }
    return true;
}
/**
 * Function to check if the user guessed the letter correctly and replaces the guessed letter on all positions of occurrences 
 * Includes check for 
 * 1. Entries other than strings like numbers and special characters
 * 2. Repeated letter guessed by the player
 * 3. More than one letter entry by the player
 * @return true for correct guess and false for incorrect guess
 */
bool GuessTheWord::CheckChar() {
    bool result = false;
    locale loc;
    currentGuess[0] = toupper(currentGuess[0],loc);
    if(currentGuess.length()>1) {
        cout << "Please enter only one Character at a time\n";
        return result;
    }
    if(!isalpha(currentGuess[0])) {
         cout << "Please enter only Characters, no Numbers or Special Characters are allowed\n";
    }   
    string::size_type repeatchar = currentState.find(currentGuess);
    if(repeatchar != string::npos) {
        result = true;
        cout << "Oops this character is already guessed. Unfortunately you have lost an attempt!\n";
        return result;
    }

    string::size_type position = currentWord.find(currentGuess);
    while(position != string::npos) {
        currentState.replace(position, 1, currentGuess);
        position = currentWord.find(currentGuess , position+1);
        result=true;
    }
    
    return result;
}
/**
 * Function to check if the player has won the game or not
 * 
 * @return true for won and false for losing the game
 */
bool GuessTheWord::IsWin() {
    bool result = false;
    if(currentWord.compare(currentState) == 0) {
        result = true;
    }
    return result;
}
/**
 * Function to reinitialize the variables when playing the game again
 */
void GuessTheWord::Clear() {
    currentWord = "";
    currentState = "";
    currentGuess = "";
}



