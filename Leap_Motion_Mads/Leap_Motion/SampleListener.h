#include"Leap.h"
#include<iostream>
#pragma on

using namespace Leap;
using namespace std;

class SampleListener : public Listener {
public:
	virtual void onConnect(const Controller&);
	virtual void onFrame(const Controller&);
};

void SampleListener::onConnect(const Controller& controller) {
	std::cout << "Connected" << std::endl;
}

void SampleListener::onFrame(const Controller& controller) {
	const Frame frame = controller.frame();

	if (frame.hands().leftmost().isLeft()) {
		cout << "Jeg kan se din venstre hånd" << endl;
	}
	else if (frame.gesture(Gesture::TYPE_KEY_TAP).isValid()) {
	
		cout << "du har trykket på en tast" << endl;
	}
