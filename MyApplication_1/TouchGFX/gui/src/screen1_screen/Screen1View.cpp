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

void Screen1View::handleTickEvent()
{
    coolWidth = 36 + ((tempvalue > 20) ? (0.9f * (tempvalue - 20)) : 0.0f)*ishome;
    coolHeight = 39 + ((tempvalue > 20) ? (0.9f * (tempvalue - 20)) : 0.0f)*ishome;
    heatWidth  = 36 - ((tempvalue < 20) ? (0.9f * (tempvalue - 20)) : 0.0f)*ishome;
    heatHeight = 39 - ((tempvalue < 20) ? (0.9f * (tempvalue - 20)) : 0.0f)*ishome;

    heatIcon.setWidth(heatWidth); 
    heatIcon.setHeight(heatHeight);
    heatIcon.invalidate();

    coolIcon.setWidth(coolWidth); 
    coolIcon.setHeight(coolHeight);
    coolIcon.invalidate();
}

void Screen1View::updateTemp(float tempval){
	Unicode::snprintf(textAreaTempBuffer, TEXTAREATEMP_SIZE, "%d", int(tempval));
	textAreaTemp.invalidate();
    tempvalue = tempval;
}

void Screen1View::updateLight(float lightval){	
	box1.setAlpha(lightval);
    box1.invalidate(); 
}

void Screen1View::updateIsHome(int isHome){	
    ishome = isHome;
	scalableImage2.setAlpha(255*isHome); 
    scalableImage2.invalidate(); 
}