/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GuessTheWord.h
 * Author: anitageorge
 *
 * Created on September 15, 2017, 4:10 PM
 * Compiler Used: 
 * 
 * This is a header file that entails the variables and the function signatures of the class GuessTheWord
 */

#ifndef GUESSTHEWORD_H
#define GUESSTHEWORD_H

#include "iostream"
#include "fstream"
#include "string"
using namespace std;

class GuessTheWord {
    string dictionary[50];
    string currentWord;
    string currentState;
    string currentGuess;
    int dictionarySize;
    const string vowels = "AEIOU"; 
    bool CheckVowel(string);
    void GenerateHint();
public: 
    GuessTheWord();
    void LoadDictionary(string filename="InputFile.txt"); //Usage of default parameter
    void Clear();
    int GetSecretWord();
    bool CheckChar();
    bool IsWin();
    friend istream& operator>>(istream &input, GuessTheWord &guess) { //operator overloading of >> as a friend function to input an object
        input >> guess.currentGuess;
        return input;
    }
    friend ostream& operator<<(ostream &output,const GuessTheWord &guess) { //operator overloading of << as a friend function to output and object
        output << guess.currentState <<"\n";
        return output;
    }
};


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* GUESSTHEWORD_H */

