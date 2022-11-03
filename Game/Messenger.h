#pragma once
#include "Application.h"
class Messenger :
    public Application
{
public:
    Messenger(std::string title);
    virtual void display() override;
private:

};

