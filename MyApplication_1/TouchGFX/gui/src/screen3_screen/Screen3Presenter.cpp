#include <gui/screen3_screen/Screen3View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

Screen3Presenter::Screen3Presenter(Screen3View& v)
    : view(v)
{

}

void Screen3Presenter::activate()
{

}

void Screen3Presenter::deactivate()
{

}
void Screen3Presenter::setNewPollution(int pollutionval){
	view.updatePollution(pollutionval);
}

void Screen3Presenter::setNewLight(float lightval){
	view.updateLight(lightval);
}

void Screen3Presenter::setNewIsHome(int ishomeval){
	view.updateIsHome(ishomeval);
}