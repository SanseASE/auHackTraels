#include "toolControl.h"

toolControl::toolControl()
{
}

toolControl::~toolControl()
{
}

void toolControl::inputFrame(Leap::Frame frame) {

	if (frame.hands().count() != handNum) {
		handNum = frame.hands().count();
		change = 1;
	}
	if (frame.hands().leftmost().grabStrength() < 0.01) {

		leftFor = 0;
		change = 1;
	}

	if (frame.hands().leftmost().grabStrength() > 0.99) {

		leftFor = 1;
		change = 1;
	}


	if (frame.hands().rightmost().grabStrength() < 0.5) {

		rightFor = 0;
		change = 1;
	}

	if (frame.hands().rightmost().grabStrength() < 0.51) {

		rightFor = 1;
		change = 1;
	}

	if (frame.hands().rightmost().isRight() != isRight) {

		isRight = frame.hands().rightmost().isRight();
		change = 1;
	}

	if (frame.hands().leftmost().isLeft() != isLeft) {

		isLeft = frame.hands().rightmost().isLeft();
		change = 1;
	}

	if (frame.gesture(Gesture::TYPE_SWIPE).isValid() != cir) {

		cir = frame.gesture(Gesture::TYPE_SWIPE).isValid();
		change = 1;
	}
	


	if (handNum == 2 && change == 1){
	

		if (!leftFor && !rightFor) {

			cout << "Standing still" << endl;

		}

		if (!leftFor) {
		
			cout << "Send left motor forward" << endl; 
		
		}

		if (!rightFor) {

			cout << "Send right motor forward" << endl;

		}

		if (isRight && cir) {

			cout << "Send right turn" << endl;

		}

		if (isLeft && cir) {

			cout << "Send left turn" << endl;

		}

		change = 0; 
	}

	else {
		if (change == 1) {
			cout << "You need two hands to drive" << endl;
			change = 0;
		}

	}

	

}

void toolControl::forward(int hard) {
}
void toolControl::backward(int hard) {
}
void toolControl::left(int hard) {

}
void toolControl::right(int hard) {

}
