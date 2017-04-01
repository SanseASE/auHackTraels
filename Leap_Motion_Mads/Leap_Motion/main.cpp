#include <iostream>
#include <string.h>
#include "Leap.h"
#include "toolControl.h"
//#include"SampleListener.h"

using namespace Leap;
using namespace std;

	int main(int argc, char** argv) {
		Listener listener;
		Controller controller;
		Frame frame;
		controller.addListener(listener);
		controller.enableGesture(Gesture::TYPE_SWIPE, true);
		controller.enableGesture(Gesture::TYPE_CIRCLE, true);
		controller.enableGesture(Gesture::TYPE_KEY_TAP, true);
		toolControl tool;
			
		while (1) {
			
			frame  = controller.frame();

			tool.inputFrame(frame);

			//if (frame.gesture(Gesture::TYPE_SWIPE).isValid()) {
			
		//		exit(1);
		//	}
		}
	
		controller.removeListener(listener);

		return 0;
	}