#include "HandPosition.h"

int HandPosition::updateHands(const Frame & frame) {
	if (frame.hands().count() == 2) {
		rightmost = frame.hands().rightmost();
		leftmost = frame.hands().leftmost();

		if (rightmost.isRight() && leftmost.isLeft()) 
			return 1;
		else 
			return -2;
	}
	else 
		return -1;
}

int HandPosition::getRightPosition(const Frame & frame)
{
	rightpalm = rightmost.palmPosition();
	return (int)rightpalm.y - appHight;
}

int HandPosition::getLeftPosition(const Frame & frame)
{
	leftpalm = leftmost.palmPosition();
	return (int)leftpalm.y - appHight;
}

int HandPosition::isShut(const Frame & frame)
{
	if (leftmost.grabStrength)
	return 0;
}
