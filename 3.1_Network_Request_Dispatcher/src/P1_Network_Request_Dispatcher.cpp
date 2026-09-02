//============================================================================
// Name        : 1_Network_Request_Dispatcher.cpp
// Author      : Ritik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

enum class HttpStatus {
	Ok = 200,
	Created = 201,
	BadRequest = 400,
	Unauthorized = 401,
	NotFound = 404,
	ServerError = 500
};

void handleResponse(HttpStatus status, const string& endpoint){

	switch(static_cast<int>(status)){
	case 200:
		cout << endpoint << " -> " << 200 << " Ok" << endl;
		break;
	case 201:
		cout << endpoint << " -> " << 201 << " Created" << endl;
		break;
	case 400:
		cout << endpoint << " -> " << 400 << " BadRquest" << endl;
		break;
	case 401:
		cout << endpoint << " -> " << 401 << " Unauthorized" << endl;
		break;
	case 404:
		cout << endpoint << " -> " << 404 << " Not Found" << endl;
		break;
	case 500:
		cout << endpoint << " -> " << 500 << " Server Error" << endl;
		break;
	default:
		cout << "Invalid Status" << endl;
	}
};



int main1() {

	handleResponse(HttpStatus::Ok,"[GET/api/users]");
	handleResponse(HttpStatus::Unauthorized,"[GET/api/login]");
	handleResponse(HttpStatus::NotFound,"[GET/api/products/99]");
	handleResponse(HttpStatus::ServerError,"[GET/api/order]");

	return 0;
}
