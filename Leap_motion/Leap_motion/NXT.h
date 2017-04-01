#pragma once
#include <iostream>

using namespace std;


class NXT {
public:
	void connect();
	void write(char);
	void motor(char motor, int speeed);

private:
	char leftMotor = 0x10, rightMotor = 0x20;
	char forward = 0x0B, back = 0x03, stop = 0x08;
};

void NXT::connect() {
	// connect kode
}

void NXT::write(char m) {
	cout << (int)m << endl;
}


void NXT::motor(char motor, int speed) {
	write((motor == 'l' ? leftMotor : rightMotor) | (speed == 0 ? stop : (speed < 0 ? back : forward)));
}