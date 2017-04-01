#pragma once

#include <iostream>
#include <string>
#include "Leap.h"

using namespace Leap;
using namespace std;

class HandPosition {
public:
	int updateHands(const Frame & frame);
	int getRightPosition(const Frame & frame);
	int getLeftPosition(const Frame & frame);
	int isShut(const Frame & frame);

private:
	Hand rightmost, leftmost;
	Vector rightpalm, leftpalm;


	int appHight = 200;

};
