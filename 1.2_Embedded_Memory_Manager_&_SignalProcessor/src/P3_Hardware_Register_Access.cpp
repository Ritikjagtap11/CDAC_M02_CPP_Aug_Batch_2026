/*
 * P3_Hardware_Register_Access.cpp
 *
 *  Created on: 29-Aug-2026
 *      Author: RitikJ
 */


#include <iostream>
using namespace std;

int main3(){

	int statusReg = 0b10110001;
	// Read-only from firmware side
	int controlReg = 0b00000000;
	// Firmware writes here
	int dataReg = 0b11001010;

//   const int* regptr1 = &statusReg;
//   cout<< *regptr1;//read it
//	*regptr1 = 10;//can't change value
//	regptr1 = &dataReg; // can repoint
//
//	int* const regptr2 = &controlReg;
//	*regptr2 = 10; // change value
//	regptr2 = &dataReg; //can't repoint

//	const int* const regptr3 = &dataReg;
//	cout << *regptr3;//read it
//	*regptr3 = 10;//can't change value
//	regptr3 = &dataReg;

//	statusReg  → const int*            → READ ONLY
//	controlReg → int* const            → WRITE + FIXED ADDRESS
//	statusReg  → const int* const      → READ ONLY + FIXED ADDRESS

//	const int*        →  Read only data, pointer can move
//	int* const        →  Data can change, pointer cannot move
//	const int* const  →  Neither data nor pointer can change


	return 0;
}
