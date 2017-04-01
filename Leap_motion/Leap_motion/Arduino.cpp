#include "Arduino.h"

void Arduino::resetCharsRead()	//Resets cmd_, para_ and countRecieved_
{
	cmd_ = 0;					
	para_ = 0;
	countRecieved_ = 0;
}

char Arduino::getCmd() const	//Recieves cmd_
{
	return cmd_;
}

char Arduino::getPara() const	//recieves para_
{
	return para_;
}

void Arduino::sendToArduino(char sCmd, char sPara)				//Sends the cmd in hex to arduino, waits and then sends para in hex, 1 is the number of chars send
{
	try
	{
		serialObj_.send(&sCmd, 1);
		Sleep(1);
		serialObj_.send(&sPara, 1);
	}
	catch (const char *e)
	{
		printf("%s\n", e);
		_getch();
		exit(1);
	}
}

void Arduino::recieveFromArduino() 
{
	char c = 0;
	try
	{
		if (serialObj_.inWatingBuffer())
		{
			c = serialObj_.receiveOneChar();   //Recieves one char from arduino, saves it in variable
		}
	}
	catch (const char *e)
	{
		printf("%s\n", e);
		_getch();
		exit(1);
	}

	if (c > 0)								//Aslong as c is higher than 0(Blank ascii)
	{
		if (countRecieved_ == 0)			//If countRecieved_ == 0, c will be save in cmd_, countRecieved_ is set to 1
		{
			cmd_ = c;
			countRecieved_ = 1;
		}
		else								//Else c wil be saved in para_ and countRecieved_ reset
		{
			para_ = c;
			countRecieved_ = 0;
		}
	}
}

Arduino::Arduino(int comPort, int baudRate)    // Constructor that opens port X, sets baudrate, databit to 8, and none parity 
{
	countRecieved_ = 0;						
	cmd_ = 0;
	para_ = 0;

	try
	{
		serialObj_.open(comPort, baudRate, 8, PARITY_NONE, 1);
	}
	catch (const char *e)
	{
		printf("%s\n", e);
		_getch();
		exit(1);
	}
	cout << "COM" << comPort << " er aaben og klar til brug" << endl;
}


