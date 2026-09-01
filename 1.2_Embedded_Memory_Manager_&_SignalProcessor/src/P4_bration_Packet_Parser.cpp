/*
 * P4_bration_Packet_Parser.cpp
 *
 *  Created on: 29-Aug-2026
 *      Author: RitikJ
 */

#include <iostream>

using namespace std;

bool parsePacket(int* rawData, int size, int** outMin, int** outMax) {

    if (size <= 0) {
        return false;
    }

    *outMin = &rawData[0];
    *outMax = &rawData[0];

    for (int i = 0; i < size; i++) {

       if(rawData[i] < **outMin) {
    	   *outMin = &rawData[i];
       }
       if(rawData[i] > **outMax) {
    	   *outMax = &rawData[i];
       }
    }

    return true;
}

int main4(){

	int packet[] = {45, 12, 67, 8, 55, 31};
	int* minPtr = nullptr;
	int* maxPtr = nullptr;

	if (parsePacket(packet, 6, &minPtr, &maxPtr)) {
	    cout << "Calibration Min : " << *minPtr << endl;
	    cout << "Calibration Max : " << *maxPtr << endl;
	}

	return 0;
}
