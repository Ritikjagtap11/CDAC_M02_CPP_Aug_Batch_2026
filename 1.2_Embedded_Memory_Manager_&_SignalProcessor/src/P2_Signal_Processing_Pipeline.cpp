/*
 * P2_Signal_Processing_Pipeline.cpp
 *
 *  Created on: 28-Aug-2026
 *      Author: RitikJ
 */

#include <iostream>
#include <cmath>
using namespace std;

// Returns sqrt( sum of (each element squared) / n )
double computeRMS(double *signal,int n){

	int sum = 0;

	for(int i=0; i<n; i++) {
		sum += *(signal + i);
	}

	return sqrt(sum/n);
}

// Divides every element by the max absolute value in the array (in-place)
void normalise(double *signal,int n){

	double mx = abs(*(signal));

	for(int i=0; i<n; i++) {
		mx = max(mx,abs(*(signal + i)));
	}


	for(int i=0; i<n; i++) {
		*(signal + i) = *(signal + i)/mx;
	}

}

//Returns count of positions where adjacent elements have opposite signs
int countZeroCrossings(double *signal,int n){

	int count = 0;

	for(int i=0; i<n; i++) {
		if(  ((*(signal + i)) > 0 && (*(signal + i+1)) < 0) ||
			 ((*(signal + i)) < 0 && (*(signal + i+1)) > 0)   ) {
			count++;
		}
	}

	return count;
}

// Multiplies every element by gainFactor (in-place)
void applyGain(double *signal,int n, double gainFactor){

	for(int i=0; i<n; i++) {
		*(signal + i) = *(signal + i) * gainFactor;
	}

}

int main2(){

	double signal[] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};
	int n = sizeof(signal) / sizeof(signal[0]);

	//normalise
	cout << endl;
	cout <<"normalise"<<endl;
	cout << "array before : ";
	for(int i=0; i<n; i++) {
		cout << signal[i] << " ";
	}
	normalise(signal,n);
	cout << endl;
	cout << "array after : ";
	for(int i=0; i<n; i++) {
		cout << signal[i] << " ";
	}
	cout << endl;

	//applyGain
	cout << endl;
	cout <<"applyGain"<<endl;
	cout << "array before : ";
	for(int i=0; i<n; i++) {
		cout << signal[i] << " ";
	}
	applyGain(signal,n,2.0);
	cout << endl;
	cout << "array after : ";
	for(int i=0; i<n; i++) {
		cout << signal[i] << " ";
	}
	cout << endl;

	//computeRMS
	cout << endl;
	cout << "computeRMS: " << computeRMS(signal,n);
	cout << endl;

	//countZeroCrossings
	cout << endl;
	cout << "countZeroCrossings: " << countZeroCrossings(signal,n);
	cout << endl;

	return 0;
}



