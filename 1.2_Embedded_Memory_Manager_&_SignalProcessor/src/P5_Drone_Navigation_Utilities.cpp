/*
 * P5_Drone_Navigation_Utilities.cpp
 *
 *  Created on: 29-Aug-2026
 *      Author: RitikJ
 */

#include <iostream>
#define M_PI = 3.14;
#include <cmath>
using namespace std;

inline double distanceBetween(double x1, double y1, double x2, double y2){
	return sqrt( pow(x2-x1,2) + pow(y2-y1,2) );
}

inline double toRadians(double degrees){
	return degrees * (M_PI / 180.0);
}

inline double clamp(double value, double minVal, double maxVal){
	if(value < minVal) return minVal;
	if(value > maxVal) return maxVal;
	return value;
}

inline bool isInSafeZone(double x, double y, double cx, double cy, double radius){
	return distanceBetween(x,y,cx,cy) <= radius;
}


int main() {

	 double homeX = 0.0;
	 double homeY = 0.0;
	 double safeRadius = 50.0;

	 double wayP[3][2] = {
			 {10.0,20.0},
			 {30.0,40.0},
			 {60.0,10.0}
	 };

	 for (int i = 0; i < 3; i++) {

	         double x = wayP[i][0];
	         double y = wayP[i][1];

	         double distance = distanceBetween(x, y, homeX, homeY);

	         cout << "Waypoint (" << x << ", " << y << ")" << endl;
	         cout << "Distance from home: " << distance << endl;

	         if (isInSafeZone(x, y, homeX, homeY, safeRadius)) {
	             cout << "Inside Safe Zone" << endl;
	         } else {
	             cout << "Outside Safe Zone" << endl;
	         }

	         cout << endl;
	     }

	return 0;
}


