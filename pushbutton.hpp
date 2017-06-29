#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED

#include "widgets.hpp"
#include "window.hpp"
#include <functional>

class PushButton : public Widget {
    std::string _felirat;
public:
    PushButton(int x, int y, int sx,
                int sy, std::string s);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual void action()=0;
};







#endif // PUSHBUTTON_HPP_INCLUDED
