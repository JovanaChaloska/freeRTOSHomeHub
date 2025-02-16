#ifndef SCREEN3VIEW_HPP
#define SCREEN3VIEW_HPP

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

class Screen3View : public Screen3ViewBase
{
public:
    Screen3View();
    virtual ~Screen3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

    void setRotationSpeed(int speed);
    void updateLight(float lightval);
    void updateIsHome(int isHome);
    void updatePollution(int pollutionval);
private:
    int rotationAngle;
    int rotationSpeed;
    float alphavalue;
    int ishome;
    int tickCounter;
};

#endif // SCREEN3VIEW_HPP
