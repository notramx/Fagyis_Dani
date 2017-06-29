#ifndef SELECTOR_HPP_INCLUDED
#define SELECTOR_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "window.hpp"
#include <vector>

class Selector : public Widget {
protected:
    bool _checked;
    int _selected, _start, _items;
    bool _checked2, _nyit;
    bool _kijelolos_e;
    std::string _s;
    std::vector<Widget::elem> _vs;
public:
    Selector(int x, int y, int sx, int sy, std::vector<Widget::elem> vs, bool kijelolos_e);
    virtual void draw();
    virtual void handle(genv::event ev);
    inline void setvs(std::vector<Widget::elem> vs) {_vs = vs;}
    inline int getvssize() {return _vs.size();}
    inline int getselected() {return _selected;}
};

#endif // SELECTOR_HPP_INCLUDED
