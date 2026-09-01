//============================================================================
// Name        : 2_Hospital_Patient_Registry.cpp
// Author      : Ritik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct layout1 {
	char c1;
	int i;
	char c2;
};

struct layout2 {
	int i;
	char c1;
	char c2;
};

int main() {
	cout << "layout1: " << sizeof(layout1)<< endl;
	cout << "layout2: " << sizeof(layout2)<< endl;
	return 0;
}

/*
1. Why the sizes differ:
   - Layout1 (12 bytes): [1B char] + [3B pad] + [4B int] + [1B char] + [3B pad]
   - Layout2 (8 bytes):  [4B int]  + [1B char] + [1B char] + [2B pad]
   Grouping the two chars together saves space.

2. What padding is and why it's added:
   - Padding is empty filler bytes added by the compiler.
   - The CPU reads memory faster when 4-byte ints start at addresses divisible by 4.

3. Why member order matters for network/hardware:
   - Network packets and hardware registers require exact byte-by-byte matching.
   - Extra padding bytes will shift data to the wrong positions and corrupt communication.
*/
