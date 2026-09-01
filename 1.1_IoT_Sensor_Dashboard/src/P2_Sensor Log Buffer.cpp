//============================================================================
// Name        : Day-5-LP-Sensor_Reading_Classifier.cpp
// Author      : Ritik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

void buferr_analysis_module(int N) {

    int skip = 0;
    double cri_F = 0;
    int Idx = 0;
    double mn, mx;
    double avg;
    int nor = 0, war = 0, cri = 0, shu = 0;
    double sm = 0;

    if (N >= 1 && N <= 100) {

        double arr[100];

        // skip count, skip 0
        int validCount = 0;

        cout << "Valid readings : ";

        for (int i = 0; i < N; i++) {

            double value;
            cin >> value;

            if (value <= 0) {
                skip++;
                continue;
            }

            arr[validCount] = value;
            validCount++;
        }

        cout << "----------END----------" << endl;

        // first critical
        for (int i = 0; i < validCount; i++) {

            if (arr[i] > 45) {
                Idx = i + 1;
                cri_F = arr[i];
                break;
            }
        }

        // calculate min, max, avg
        mn = arr[0];
        mx = arr[0];

        for (int i = 0; i < validCount; i++) {

            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);

            sm += arr[i];
        }

        avg = sm / validCount;

        // count nor, war, cri, shu
        for(int i = 0; i < validCount; i++){

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

        cout << "Readings entered : " << N << endl;

        cout << "Valid readings : ";

        for (int i = 0; i < validCount; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;

        cout << "Skipped (errors) : " << skip << endl;

        cout << "First CRITICAL : "
             << "Index " << Idx
             << " -> " << cri_F << "°C" << endl;

        cout << "Min : " << mn << "°C, "
             << "Max : " << mx << "°C, "
             << "Avg : " << avg << "°C" << endl;

        cout << "Normal : " << nor << ", "
             << "Warning : " << war << ", "
             << "Critical : " << cri << ", "
             << "Shutdown : " << shu << endl;

    } else {

        cout << "Enter a valid Readings to range (1 to 100)";
    }
}

int main1() {

    int N;

    cout << "Enter a Readings: " << endl;
    cin >> N;

    buferr_analysis_module(N);

    return 0;
}
