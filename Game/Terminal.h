    #pragma once
#include "Application.h"
class Terminal :
    public Application
{
public:
    Terminal(std::string title);
    virtual void display() override;
    void makeWindowBar();
private:

};

