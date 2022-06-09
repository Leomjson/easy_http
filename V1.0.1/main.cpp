#include "HTTP_1.h"
#include <iostream>
#include <string>
#include <fstream>

// External Requirements.
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "HTTP.lib")

// any line with the comment "RELIABILITY" is complete optinal and can be removed safely.

string IpAddress;
int port;
int serverport;

int main()
{
	ifstream ReadFormat("info/ip.txt"); ifstream ReadFormat1("info/http_port.txt"); ifstream ReadFormat2("info/server_port.txt");
	if (!ReadFormat.is_open() & !ReadFormat1.is_open() & !ReadFormat.is_open()) // RELIABILITY
	{
		system("mkdir info");
		ofstream WriteFormat_IP("info/ip.txt");
		cout << "IP Address: ";
		cin >> IpAddress;
		WriteFormat_IP << IpAddress;
		WriteFormat_IP.close(); // RELIABILITY

		ofstream WriteFormat_HPORT("info/http_port.txt");
		cout << "HTTP Port: ";
		cin >> port;
		WriteFormat_HPORT << port;
		WriteFormat_HPORT.close(); // RELIABILITY

		ofstream WriteFormat_SPORT("info/server_port.txt");
		cout << "ENet/Server Port: ";
		cin >> serverport;
		WriteFormat_SPORT << serverport;
		WriteFormat_SPORT.close(); // RELIABILITY

		system("cls");
	}
	else
	{
		ifstream ReadFormat_IP("info/ip.txt");
		ReadFormat_IP >> IpAddress;
		ReadFormat_IP.close(); // RELIABILITY

		ifstream ReadFormat_HPORT("info/http_port.txt");
		ReadFormat_HPORT >> port;
		ReadFormat_HPORT.close(); // RELIABILITY

		ifstream ReadFormat_SPORT("info/server_port.txt");
		ReadFormat_SPORT >> serverport;
		ReadFormat_SPORT.close(); // RELIABILITY
	}

	cout << "HTTP Running on " + IpAddress + ":" + to_string(port) 
		<< endl;

	cout << "---------------------------------------------" 
		<< endl;

	http_Request(1, IpAddress, port, serverport);

	while (true);
	return false;
}