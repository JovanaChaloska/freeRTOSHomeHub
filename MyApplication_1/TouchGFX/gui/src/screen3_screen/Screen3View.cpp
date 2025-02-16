#include <gui/screen3_screen/Screen3View.hpp>
#include <cmath>

Screen3View::Screen3View() : rotationAngle(0), rotationSpeed(2) {
    tickCounter = 0;
}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();

    fanImage.setRotation(rotationAngle);
    
    fanImage.setRotationCenter(fanImage.getWidth() / 2, fanImage.getHeight() / 2);
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}

void Screen3View::handleTickEvent()
{
    rotationAngle = (rotationAngle + rotationSpeed)*ishome % 360;
    fanImage.setRotation(rotationAngle);
    fanImage.invalidate();
}

void Screen3View::setRotationSpeed(int speed)
{
    rotationSpeed = speed;
}

void Screen3View::updatePollution(int pollutionval){	
	Unicode::snprintf(textAreaPollutionBuffer, TEXTAREAPOLLUTION_SIZE, "%d", pollutionval);
	textAreaPollution.invalidate();
    setRotationSpeed(pollutionval);
}

void Screen3View::updateLight(float lightval){	
	box1.setAlpha(lightval);
    box1.invalidate(); 
}

void Screen3View::updateIsHome(int isHome){	
    ishome = isHome;
	scalableImage2.setAlpha(255*isHome);
    scalableImage2.invalidate(); 
}