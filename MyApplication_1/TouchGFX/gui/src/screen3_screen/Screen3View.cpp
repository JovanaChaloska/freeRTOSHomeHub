#include <gui/screen3_screen/Screen3View.hpp>
#include <cmath>

Screen3View::Screen3View() : rotationAngle(0), rotationSpeed(2) {
    tickCounter = 0;
}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();

    fanImage.setRotation(rotationAngle);
    
    // Set rotation center (adjust based on image size)
    fanImage.setRotationCenter(fanImage.getWidth() / 2, fanImage.getHeight() / 2);
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}

void Screen3View::handleTickEvent()
{
    rotationAngle = (rotationAngle + rotationSpeed) % 360;
    fanImage.setRotation(rotationAngle);
    fanImage.invalidate();
}

void Screen3View::setRotationSpeed(int speed)
{
    rotationSpeed = speed;
}

void Screen3View::updatePollution(int pollutionval){	
	Unicode::snprintf(textAreaPollutionBuffer, TEXTAREAPOLLUTION_SIZE, "%d", pollutionval);
    setRotationSpeed(pollutionval);
	textAreaPollution.invalidate();
}