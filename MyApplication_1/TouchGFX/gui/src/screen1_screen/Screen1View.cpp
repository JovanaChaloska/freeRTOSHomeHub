#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{
	tickCounter = 0;
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateTemp(float tempval){
	Unicode::snprintf(textAreaTempBuffer, TEXTAREATEMP_SIZE, "%d", int(tempval));
	textAreaTemp.invalidate();
}

