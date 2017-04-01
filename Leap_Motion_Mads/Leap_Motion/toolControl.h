#pragma once
#include"Leap.h"
using namespace std;
using namespace Leap;
class toolControl
{
public:
	toolControl();
	~toolControl();

	void inputFrame(Leap::Frame frame);

private:
	void forward(int hard); 
	void backward(int hard);
	void left(int hard);
	void right(int hard);

	int handNum, leftFor, rightFor, isLeft, isRight, cir, change;

};

