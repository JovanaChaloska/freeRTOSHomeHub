#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    //Declare virtual functions and later override them in Presenter
    virtual void setNewTemp(float temp){}
    virtual void setNewPollution(int pollution){}
    virtual void setNewLight(float light){}
    virtual void setNewIsHome(int ishome){}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
