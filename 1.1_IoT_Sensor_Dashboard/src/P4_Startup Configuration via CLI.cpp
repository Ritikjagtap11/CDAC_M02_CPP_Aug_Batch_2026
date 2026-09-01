/*
 * P4_Startup Configuration via CLI.cpp
 *
 *  Created on: 28-Aug-2026
 *      Author: RitikJ
 */


#include <iostream>
#include <cstdlib>
using namespace std;

void StartupCLI(int warn, int critical, int num_readings){

	int size = num_readings;
	int arr[size];
	int nor=0,war=0,cri=0,shu=0;

	//number readings
	for(int i=0; i<size; i++){
		arr[i] = rand()%70;

		if(arr[i] < 0) {
		        cout << "SENSOR_ERROR" <<endl;
		 } else if(arr[i] >= 0 && arr[i] <= 29) {
			 	 nor++;
		 } else if(arr[i] >= 30 && arr[i] <= 44) {
		         war++;
		 } else if(arr[i] >= 45 && arr[i] <= 59) {
		          cri++;
		 } else if(arr[i] >= 60) {
			 	  shu++;
		 }
	}


	if(warn < critical && (num_readings >=1 && num_readings <=500)){

		cout << "$ ./sensor_monitor " << warn << " " << critical << " "<< num_readings << endl;
		cout << "Config :" << " " << "Warn=" << warn << "°C " << "Critical=" << critical << "°C " << "Readings=" << num_readings << endl;
		cout << "Result :" << " " << "Normal:" << nor <<" " <<"Warning:" << war <<" " <<"Critical:" << cri<<" " <<"Shutdown:" << shu <<endl;

	}



}

int main(int argc, char* argv[]){


	if(argc != 4){

//			cout << "$ ./sensor_monitor " << warn << " " << critical << " "<< num_readings << endl;
			cout << "Usage :" << " " << "./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>" << endl;
			cout << "Error :" << " " << "Missing arguments." <<endl;
		}

	StartupCLI(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));


	return 0;
}

