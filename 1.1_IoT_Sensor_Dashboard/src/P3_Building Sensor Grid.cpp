/*
 * P3_Building Sensor Grid.cpp
 *
 *  Created on: 28-Aug-2026
 *      Author: RitikJ
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Building_Sensor_Grid(int grid) {

	double arr[grid][grid];

	double hottest;
	int h_floor,h_room;

	double floor_avg=0,sum=0;
	int floor;

	int room_war = 0;

	//Add temp into
	cout << "Enter temp: " << endl;
	hottest = arr[0][0];
	for(int i=0; i<grid;i++){ //-> floor
		for(int j=0; j<grid;j++){ //-> room
			cin >> arr[i][j];
			hottest = max(hottest,arr[i][j]);
			h_floor = i;
			h_room = j;
		}
	}

	//avg floors
	for(int i=0; i<grid;i++){ //-> floor
		double avg;
			for(int j=0; j<grid;j++){ //-> room
				sum+=arr[i][j];
				avg = sum/3;

				if(arr[i][j] >= 30){
					room_war++;
				}
			}
//			cout<< "f:" << i+1 << " " << avg <<endl;
			floor_avg = max(floor_avg,avg);
			floor = i;

			sum=0;
			avg=0;
		}
//	cout<< "floor_avg" << floor_avg;

	//display floor
//	cout << "Show -----" << endl;

	 cout << "           "
	         << setw(7) << "Room1"
	         << setw(7) << "Room2"
	         << setw(7) << "Room3"
	         << endl;

	for(int i=0; i<grid;i++){ //-> floor
			cout<<"Floor "<<i+1 <<" :";
			for(int j=0; j<grid;j++){ //-> room

				cout << setw(7) << arr[i][j] << " ";

			}
			cout << endl;
		}

	cout << "Hottest Room " << " : "<< "Floor " << h_floor+1 << ", "<< "Room " << h_room+1 << " -> " << hottest <<"\u00B0C" <<endl;
	cout <<"Hottest Floor " << " : " << "Floor " << floor << " (avg " << floor_avg << "\u00B0C)" <<endl;
	cout <<"Rooms at WARNING or above : " << room_war <<endl;


}

int main3(){

	Building_Sensor_Grid(3);


	return 0;
}


