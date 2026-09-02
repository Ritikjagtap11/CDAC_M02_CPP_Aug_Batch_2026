//============================================================================
// Name        : 2_Game_Asset_Manager.cpp
// Author      : Ritik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
using namespace std;

class Texture {
	string name;
	int width;
	int height;

public:
	Texture(string name, int width, int height){
	        this->name = name;
	        this->width = width;
	        this->height = height;
		cout<<"Texture Loaded"<<endl;
	}

	void display(){
		cout << "======Dimension=====" << endl;
		cout << "Name: " << name << endl;
		cout << "Width: " << width << endl;
		cout << "height: " << height << endl;
	}

	~Texture(){
		cout<<"Texture Released"<<endl;
	}
};

int main1() {

//	unique_ptr<Texture> t1 = make_unique<Texture>("player_sprite",512,512);
	auto t1 = make_unique<Texture>("player_sprite",512,512);
	t1->display();

	//unique_ptr<Texture> t2 = t1;

	unique_ptr<Texture> t2 = move(t1);

	cout <<"T1 is null: " << (t1 == nullptr ? "YES" : "NO") << endl;


//	t2->display();

	return 0;
}
