/*
 * P3_weak_ptr_Non_owning_observer.cpp
 *
 *  Created on: 02-Sept-2026
 *      Author: RitikJ
 */

#include <iostream>
#include <memory>
using namespace std;

class AudioClip{
	string name;
	double vol;

public:

	AudioClip(string name, double vol){
		this->name=name;
		this->vol=vol;
		cout << "AudioClip Observer Complied" << endl;
	}


	string getName(){
		return name;
	}


	~AudioClip(){
		cout << "AudioClip observer Destroyed" << endl;
	}

};

int main(){

	auto audio = make_shared<AudioClip>("explosion",3.5);
	weak_ptr<AudioClip> observer = audio;

	if(auto clip = observer.lock()){
		cout << "Clip alive: " << clip->getName() << endl;
	}

	audio.reset();//unload

	if(observer.expired()){
		cout << "Clip already unloaded." << endl;
	}

	return 0;
}





