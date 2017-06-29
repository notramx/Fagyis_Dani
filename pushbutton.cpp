#include "pushbutton.hpp"

using namespace std;
using namespace genv;


PushButton::PushButton(int x, int y, int sx, int sy, std::string s)
    : Widget(x,y,sx,sy), _felirat(s)

{

}


void PushButton::draw(){
    if (_focused) gout << color(180,180,180);
        else gout << color(130,130,130);
    gout << move_to(_x, _y) << box(_size_x, _size_y)
         << color(255,255,255);
    gout << move_to(_x+_size_x/2-gout.twidth(_felirat)/2, _y+20)
         << text(_felirat);
}
void PushButton::handle(genv::event ev) {
    if (ev.keycode==' ' || (is_selected(ev.pos_x, ev.pos_y) && ev.type == ev_mouse && ev.button == btn_left)) {
        action();
    }
}






