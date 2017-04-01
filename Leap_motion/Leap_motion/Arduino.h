#pragma once
#pragma comment(lib, "SerialCom.lib")   // Essential
#include <SerialCom.h>
#include <iostream>	
#include <conio.h>  //Used for getch, kbhit
#include <stdio.h>  //Used for printf

using namespace std;

class Arduino
{
public:
	Arduino(int comPort = 3, int baudRate = 9600);
	void recieveFromArduino();
	void sendToArduino(char sendCmd, char sendPara);
	char getCmd() const;
	char getPara() const;
	void resetCharsRead();

private:
	SerialCom serialObj_;
	char cmd_;
	char para_;
	int countRecieved_;
};
