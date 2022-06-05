#include "HTTP_1.h"
#include <string>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "HTTP.lib")

// debug
#include <iostream>


string IpAddress;
int port;
int serverport;

int main()
{
	cout << "IP Address: ";
	cin >> IpAddress;

	cout << "HTTP Port: ";
	cin >> port;

	cout << "ENet/Server Port: ";
	cin >> serverport;
	system("cls");


	cout << "HTTP Running on " + IpAddress + ":" + to_string(port) 
		<< endl;

	cout << "------------------------------------------------------\n\n"
		<< endl;

	http_Request(1, IpAddress, port, serverport);

	while (true); // RELIABILITY
	return false;
}