/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Assignment1_DRIVER.cpp
 * Author: anitageorge
 *
 * Created on September 15, 2017, 4:25 PM
 */

#include <iostream>
#include "GuessTheWord.h"
using namespace std;

int main() {

	int playAgain=-1, WordLength = 0;

	//Default constructor should be used to initalize class variables
	GuessTheWord game;

	//Use default parameter for the LoadDictionary() method
	//It should be used if no input filename is passed here
	game.LoadDictionary();

	do
	{
		game.Clear();
	
		//Read from the dictionary of words and select a secret word
		WordLength = game.GetSecretWord();

//		cout << "Game starts "<< endl;
//
//		//Print the initial clue using overloaded <<
//		cout << game;
//
//		int j = 0;
//
//		for (int i = 0; i <= WordLength + 3; i++)
//		{
//
//			cout << "Enter your next Guess"<< endl;
//			cin >> game;
//
//			//Check if guessed character is present in the word
//			if (game.CheckChar())
//				cout << "You got it right | Attempts : "<<(WordLength + 3)-i <<"/"<< WordLength + 3 << endl;
//			else
//				cout << "Oops. You got it wrong | Attempts : " << (WordLength + 3) - i << "/" << WordLength + 3 << endl;
//
//			cout << game;
//
//			//Check for win condition i.e word is complete
//			if (game.IsWin()) {
//				cout << "You won!!";
//				break;
//			}
//		}
//
//		if(!game.IsWin())
//			cout << "Sorry, You lost." << endl;

		cout << "Press 1 to play again, any key to exit";
		cin >> playAgain;

		if (playAgain != 1)
			break;

		playAgain = -1;

	} while (true);

	return 0;
}
