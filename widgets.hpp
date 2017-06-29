#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

using namespace std;
using namespace genv;

class Widget {
protected:
    bool _focused;
    int _x, _y, _size_x, _size_y;
    int _intervallum_tol;
     int _intervallum_ig;
public:
    struct elem
    {
        std::string s;
        int fagyi_ertek;
    };
    Widget(int x, int y, int sx, int sy);
    Widget(int x, int y, int sx, int sy,int intervallum_tol, int intervallum_ig);
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool focusable() const;
    virtual void focus();
    virtual void unfocus();
    virtual int _mouse_over3(int mouse_x, int mouse_y, int db) const;
    virtual bool _mouse_over2(int mouse_x, int mouse_y) const;
    virtual int _select(int mouse_x,int mouse_y,int db) const;

};


#endif // WIDGETS_HPP_INCLUDED
