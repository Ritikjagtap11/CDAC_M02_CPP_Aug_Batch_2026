/*
 * 3.2_Namespaces.cpp
 *
 *  Created on: 01-Sept-2026
 *      Author: RitikJ
 */


#include <iostream>
using namespace std;

namespace Physics {
     double Clamp(double val,double min,double max){

    	 if(val < min) {
    		 return min;
    	 }

    	 if(val > max){
    		 return max;
    	 }

    	 return val;
     }

     double lerp(double a,double b,double t){

    	 return a + (b - a) *t;
     }
}

namespace GameMath {
	double Clamp(double val,double min,double max){

    	 if(val < min) {
    		 return min;
    	 }

    	 if(val > max){
    		 return max;
    	 }

    	 return val;
     }

     double lerp(double a,double b,double t){

    	 return a + (b - a) *t;
     }
}



int main2() {

	double velocity = Physics::Clamp(15.5,-10.0,10.0);

	int health = GameMath::Clamp(120,0,100);

	cout << "Physics clamp (velocity): " << velocity << endl;
	cout << "GameMath clamp (health): " << health << endl;

	 // Limited block scope
	{
	    using namespace GameMath;

	    int level = Clamp(15, 1, 10);

	    cout << "Level: " << level << endl;
	}

	    // GameMath namespace is NOT active here
	    // So we explicitly specify the namespace
		int score = GameMath::Clamp(150, 0, 100);

	    cout << "Score: " << score << endl;

	return 0;
}
