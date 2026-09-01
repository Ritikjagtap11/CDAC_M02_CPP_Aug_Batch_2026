/*
 * 3.4-Scope Resolution Bonus.cpp
 *
 *  Created on: 01-Sept-2026
 *      Author: RitikJ
 */


#include <iostream>
using namespace std;

int level = 1;//difficulty level


namespace Engine :: Audio{
     void playSound(string name) {
    	 cout << "Playing: " << name << endl;
     }
}

int main() {

	int level = 1; //player level

	cout << "Game difficulty level: " << ::level << endl;
	cout << "Player level: " << level << endl;

	Engine::Audio::playSound("sword_clash");


	return 0;
}

