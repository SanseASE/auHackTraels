#pragma once

#include <iostream>
#include <string>
#include "Leap.h"

using namespace Leap;
using namespace std;

class Motor {
public:
	Motor();
	int getRight(const Frame & frame);


private:
	InteractionBox iBox;
	Pointable pointable;
	Vector leapPoint, normalizedPoint;



};
