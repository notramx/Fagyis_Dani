#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>


class Window {
protected:
    std::vector<Widget*> widgets;
     Widget::elem ls;
    std::vector<Widget::elem> vs;
public:
    virtual void esemeny(std::string mitortent){}

    void event_loop() ;
};



#endif // WINDOW_HPP_INCLUDED
