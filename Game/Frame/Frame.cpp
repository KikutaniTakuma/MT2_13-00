#include "Frame.h"
#include "Game/Camera/Camera.h"
#include <cmath>

Frame::Frame(void):
	frame(0.0L),
	startFlag(false),
	add(1.0f)
{}

void Frame::Start() {
	if (startFlag == true) {
		add *= Camera::getDelta();
		frame += static_cast<long double>(add);
		add = 1.0f;
	}
}

unsigned long long Frame::getFrame() const {
	return static_cast<unsigned long long>(roundl(frame));
}

void Frame::Pause(void) {
	startFlag = false;
}

void Frame::Stop(void){
	startFlag = false;
	frame = 0.0L;
}

void Frame::Restart(void) {
	startFlag = true;
}