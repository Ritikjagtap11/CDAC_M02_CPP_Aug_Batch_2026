/*
 * 3.3_Dynamic 2D Game Map.cpp
 *
 *  Created on: 01-Sept-2026
 *      Author: RitikJ
 */

#include <iostream>
using namespace std;

int main3(){

	int grass=0,water=0,mountain=0,forest=0,dungeon=0;

	int R,C;
	cout << "Enter the number of rows: ";
	cin >> R;
	cout << "Enter the number of cols: ";
	cin >> C;

	//arr created
	int** arr = new int*[R];
	for(int i=0; i< R;i++){
		arr[i] = new int [C];
	}

	//fill arr
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			arr[i][j] = rand()%5;
		}
	}

	//(0=grass, 1=water,2=mountain, 3=forest, 4=dungeon)
	//count
	for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(arr[i][j] == 0){
					grass++;
				} else if(arr[i][j] == 1){
					water++;
				} else if(arr[i][j] == 2){
					mountain++;
				} else if(arr[i][j] == 3){
					forest++;
				} else {
					dungeon++;
				}
			}
		}

	cout<<"==== GAME MAP (" << R << "x" << C << ")" << "=====" << endl;

	//print arr
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "Legend: 0=Grass 1=Water 2=Mountain 3=Forest 4=DungeonTile" << endl;

	cout << endl;
	cout << "Title Count: " << endl;
	cout << "Grass : " << grass <<endl;
	cout << "Water : " << water <<endl;
	cout << "Mountain : " << mountain <<endl;
	cout << "Forest : " << forest <<endl;
	cout << "DungeonTile : " << dungeon <<endl;


	//Deallocate memory
	for(int i=0;i<R;i++){
		delete[] arr[i];
	}
	delete[] arr;


	return 0;
}


