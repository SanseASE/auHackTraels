#include "Motor.h"

Motor::Motor()
{

}

int Motor::getRight(const Frame & frame)
{
	iBox = frame.interactionBox();
	//pointable = frame.pointables().frontmost();
	//leapPoint = pointable.stabilizedTipPosition();
	leapPoint = frame.hand(frame.id()).stabilizedPalmPosition();

	normalizedPoint = iBox.normalizePoint(leapPoint, false);

	int appZ = (normalizedPoint.z * 600)-300 ;

	return appZ; 
}
