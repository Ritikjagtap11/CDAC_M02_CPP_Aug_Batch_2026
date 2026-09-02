/*
 * 3.2_Type_Aliases_for_Readability.cpp
 *
 *  Created on: 02-Sept-2026
 *      Author: RitikJ
 */


#include <iostream>
#include <vector>
#include <utility>
using namespace std;

using Header = pair<string,string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;

typedef unsigned long long RequestId;

void printHeaders(const HeaderList& headers) {

	cout<<"Headers: "<<endl;

	for (const Header& header : headers) {
	    cout << header.first << " : " << header.second << endl;
	}
}

int main() {
	HeaderList headers = {
			{"Content-Type","application/json"},
			{"Authorization","Bearer eyJhbGci..."},
			{"Accept-Language","en-US"}
	};

	Port serverPort = 8080;
	IPAddress ipaddress = "192.168.1.66";
	RequestId requestid = 1748293847;

	cout <<"Request Id: " << requestid << endl;
	cout <<"Port: " << serverPort << endl;
	cout <<"IP Address: " << ipaddress << endl;

	printHeaders(headers);

	return 0;
}

