//============================================================================
// Name        : 3_Game_Engine_Entity_System.cpp
// Author      : Ritik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Entity {

public:
	string name;
	int health;
	int level;
	string type;//"Player", "Enemy", "Item"

	//setter
	Entity& setName(const string& name){
		this->name=name;
		return *this;
	}

	Entity& setHealth(int health){
		this->health=health;
		return *this;
	}

	Entity& setLevel(int level){
		this->level=level;
		return *this;
	}

	Entity& setType(const string& type){
		this->type=type;
		return *this;
	}

	//getter
	string getName()const {
		return name;
	}

	int getHealth()const{
		return health;
	}

	int getLevel()const{
		return level;
	}

	string getType()const{
		return type;
	}

	void displayInfo()const{
		cout<<"--------Game-------"<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Health: "<<health<<endl;
		cout<<"Level: "<<level<<endl;
		cout<<"Type: "<<type<<endl;
	}
};

int main1() {

	Entity player,enemy,item;

	player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player");
	enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
	item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");

	player.displayInfo();
	enemy.displayInfo();
	item.displayInfo();

	return 0;
}
