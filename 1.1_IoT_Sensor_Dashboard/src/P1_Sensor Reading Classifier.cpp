//============================================================================
// Name        : Day-4-LP-Sensor_Reading_Classifier.cpp
// Author      : Ritik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


void classification_module(double c) {

	string action;
	string status;
	int statusCode;

	//check actions
	if(c < 0) {
		action = "Sensor fault — check wiring";
		statusCode = -1;
	} else if(c > 0 && c < 29) {
		action="No action required";
		statusCode = 0;
	} else if(c > 30 && c < 44) {
		action="Alert sent to supervisor";
		statusCode = 1;
	} else if(c > 45 && c < 59) {
		action="Cooling system triggered";
		statusCode = 2;
	} else if(c >= 60) {
		action="Emergency shutdown initiated";
		statusCode = 3;
	} else {
		action="No action";
	}

	//check status
	switch(statusCode){
	   case -1: status="SENSOR_ERROR"; break;
	   case 0: status="NORMAL"; break;
	   case 1: status="WARNING"; break;
	   case 2: status="CRITICAL"; break;
	   case 3: status="SHUTDOWN"; break;
	   default: status="Invalid status code";
	}


	//check Fahrenheit
	double f = (c * 9 / 5) + 32;

	cout<< "Temperature: " << c << "\u00B0C" << " / " << f << "\u00B0F" <<endl;
	cout<< "Status: " << status <<endl;
	cout<< "Action: " << action <<endl;
	cout<< "Reading: " << ((c>25)? "Above Average" : "Above Average") <<endl;



}

int main2() {

	double temp;
	cout << "Enter a Temperature: ";
	cin >> temp;
	classification_module(temp);
	return 0;
}
