#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy)
{
    _x=x;
    _y=y;
    _size_x = sx;
    _size_y=sy;
    _focused=false;
}
Widget::Widget(int x, int y, int sx, int sy,int intervallum_tol, int intervallum_ig)
{
    _x=x;
    _y=y;
    _size_x = sx;
    _size_y=sy;
    _focused=false;
    _intervallum_tol = intervallum_tol;
    _intervallum_ig = intervallum_ig;
}

bool Widget::is_selected(int mouse_x, int mouse_y) const
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}


void Widget::handle(event ev) {
}
void Widget::draw() {
}
bool Widget::focusable() const {return true;}

void Widget::focus() {
    _focused = true;
}

void Widget::unfocus() {
    _focused = false;
}

bool Widget::_mouse_over2(int mouse_x, int mouse_y) const ///reduced by a square on right side
{
    return mouse_x>_x && mouse_x<_x+_size_x-_size_y && mouse_y>_y && mouse_y<_y+_size_y;
}

int Widget::_mouse_over3(int mouse_x, int mouse_y, int db) const ///reduced to a square on right side
{
    if(mouse_x>_x+_size_x-_size_y && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y)
        return 1;
    if(mouse_x>_x+_size_x-_size_y && mouse_x<_x+_size_x && mouse_y>_y+3*_size_y && mouse_y<_y+4*_size_y)
        return 2;
}

int Widget::_select(int mouse_x,int mouse_y,int db) const ///returns which item has been selected
{
    int i=0;
    bool select=false;
    while(i<db&&!select)
    {
        if(_mouse_over2(mouse_x, mouse_y-(i+1)*_size_y))
        {
            select=true;
        }
        i++;
    }
    i--;

    if(select)
        return i;
    else return -1;
}


