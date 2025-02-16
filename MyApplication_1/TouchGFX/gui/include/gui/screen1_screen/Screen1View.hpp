#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
    void updateLight(float lightval);
    void updateIsHome(int isHome);
    void updateTemp(float tempval);
protected:
    float alphavalue;
    int ishome;
    int tickCounter;
    float tempvalue;
    float heatWidth;
    float heatHeight;
    float coolWidth;
    float coolHeight;
};

#endif // SCREEN1VIEW_HPP
