#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}
void Screen1Presenter::setNewTemp(float tempval){
	view.updateTemp(tempval);

}

void Screen1Presenter::setNewLight(float lightval){
	view.updateLight(lightval);
}

void Screen1Presenter::setNewIsHome(int ishomeval){
	view.updateIsHome(ishomeval);
}
