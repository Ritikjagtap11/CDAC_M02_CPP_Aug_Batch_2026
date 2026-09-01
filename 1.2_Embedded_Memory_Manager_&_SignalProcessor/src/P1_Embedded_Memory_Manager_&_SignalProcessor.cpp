//============================================================================
// Name        : Q2_Embedded_Memory_Manager_&_SignalProcessor.cpp
// Author      : Ritik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void resetSensorPairV1(int reading1,int reading2){
	int temp = reading1;
	reading1 = reading2;
	reading2 = temp;
}

void resetSensorPairV2(int &reading1,int &reading2){
	int temp = reading1;
		reading1 = reading2;
		reading2 = temp;
}

void resetSensorPairV3(int *reading1,int *reading2){
	int temp = *reading1;
		*reading1 = *reading2;
		*reading2 = temp;
}

int main1() {

	int reading1 = 10;
	int reading2 = 20;

	cout << "--- V1: Call by Value ---" << endl;
	cout << "Before: " << " ";
	cout << "A=" << reading1 << " "  << "B=" << reading2 << endl;
	resetSensorPairV1(reading1, reading2);
	cout << "After: " << " ";
	cout << "A=" << reading1 << " " << "B=" << reading2 << "   " << "<- values unchanged" << endl;

	cout << "--- V2: Call by Reference ---" << endl;
	cout << "Before: " << " ";
	cout << "A=" << reading1  << " "  << "B=" << reading2 << endl;
	resetSensorPairV2(reading1, reading2);
	cout << "After: " << " ";
	cout << "A=" << reading1 << " " << "B=" << reading2 << "   " << "<- values swapped" << endl;

	cout << "--- V3: Call by Pointer ---" << endl;
	cout << "Before: " << " ";
	cout << "A=" << reading1 << " "  << "B=" << reading2 << endl;
	resetSensorPairV3(&reading1, &reading2);
	cout << "After: " << " ";
	cout << "A=" << reading1 << " "  << "B=" << reading2 << "   " << "<- values swapped back" << endl;


	return 0;
}
