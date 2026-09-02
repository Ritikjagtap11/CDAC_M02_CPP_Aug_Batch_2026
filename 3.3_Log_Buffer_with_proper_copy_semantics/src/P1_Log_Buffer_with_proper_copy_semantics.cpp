//============================================================================
// Name        : 3_Log_Buffer_with_proper_copy_semantics.cpp
// Author      : Ritik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

class LogBuffer{

	char* buffer;
	int capacity;
	int size;
	static int instanceCount;
	mutable int accessCount=0;

public:


	LogBuffer(int capacity){

		this->capacity = capacity;
		this->size = 0;

		buffer = new char[capacity + 1];
		buffer[0] = '\0';

		instanceCount++;

		cout << "[LogBuffer Created] capacity=" << capacity << endl;
	}

	LogBuffer(const LogBuffer& other){

		capacity = other.capacity;
		size = other.size;

		buffer = new char[capacity + 1];

		memcpy(buffer, other.buffer, size + 1);

		instanceCount++;

		cout << "[LogBuffer Deep Copied] capacity=" << capacity << endl;
	}

	LogBuffer& operator=(const LogBuffer& other) {

		if (this == &other) {

			cout << "[Self-assignment detected — no operation]" << endl;

			return *this;
		}

		delete[] buffer;

		capacity = other.capacity;
		size = other.size;

		buffer = new char[capacity + 1];

		memcpy(buffer, other.buffer, size + 1);

		cout << "[LogBuffer Assigned]" << endl;

		return *this;
	}

	~LogBuffer(){

		delete[] buffer;

		instanceCount--;

		cout << "[LogBuffer Destroyed]" << endl;
	}

	void append(const char* msg){

		int msgLength = strlen(msg);
		int availableSpace = capacity - size;

		if (msgLength <= availableSpace)
		{
			memcpy(buffer + size, msg, msgLength);

			size += msgLength;

			buffer[size] = '\0';
		}
		else
		{
			memcpy(buffer + size, msg, availableSpace);

			size = capacity;

			buffer[size] = '\0';
		}
	}

	void print() const{

		cout << buffer << endl;
		accessCount++;
	}

	void clear(){

		size = 0;
		buffer[0] = '\0';
	}

	static int getInstanceCount(){

		return instanceCount;
	}

	int getAccessCount() const{
		return accessCount;
	}

};

int LogBuffer::instanceCount = 0;

int main() {

	// Objective 1 : Basic usage

	LogBuffer log1(256);

	log1.append("Server started on port 8080");

	log1.append(" | Request received from 192.168.1.10");

	log1.print();


	// Objective 2 : Deep copy via copy constructor

	LogBuffer log2 = log1;

	log2.append(" | Cached response sent");

	cout << "log1 : ";

	log1.print();

	// log1 must NOT contain log2's append

	cout << "log2 : ";

	log2.print();


	// Objective 3 : Copy assignment operator

	LogBuffer log3(128);

	log3 = log1;

	log3.print();


	// Objective 4 : Self-assignment guard

	log1 = log1;

	log1.print();


	// Objective 5 : Static member

	cout << "Live LogBuffer objects : "
		 << LogBuffer::getInstanceCount()
		 << endl;

	const LogBuffer readOnly(log1);
	// copy construct into a const object

	readOnly.print();
	readOnly.print();
	readOnly.print();

	cout << "Times printed: " << readOnly.getAccessCount() << endl;// must print 3

	return 0;
}

/*
Why mutable?

print() is a const function, so it cannot modify normal data members.
But we need to increase accessCount whenever print() is called.

Therefore, accessCount must be mutable:

    mutable int accessCount;

mutable allows accessCount to change even when the object is const.

const member function means:
- Cannot modify normal data members.
- Can only read them.
- Cannot call non-const member functions.

So mutable is used here because accessCount is only tracking usage.
*/
