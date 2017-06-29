
#include "szambeallito.hpp"
#include "graphics.hpp"
#include <string>
#include <sstream>


using namespace genv;
using namespace std;

Szambeallito::Szambeallito(int x, int y, int sx, int sy,int intervallum_tol, int intervallum_ig)
    : Widget(x,y,sx,sy,intervallum_tol,intervallum_ig)
{
    _selected=false;
    egyszam=intervallum_tol;
}

void Szambeallito::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

    gout << color(255,255,255);

        ostringstream convert;
        convert << egyszam;
        string  new_string_from_int = convert.str();
        gout << move_to(_x+5, _y+5+gout.cascent()) << text(new_string_from_int);

        //nyil fel
    gout << move_to(_x+_size_x+3, _y-2) << color(255,255,255) << box(_size_x/2, _size_y/2);
    gout << color(0,0,255);
    gout << move_to(_x+_size_x+(_size_x/4)+3, _y+2) << line(_size_x/4, _size_y/4);
    gout << move_to(_x+_size_x+(_size_x/4)+3, _y+2) << line(-_size_x/4, _size_y/4);

        //nyil le
    gout << move_to(_x+_size_x+3, _y+_size_y/2+2) << color(255,255,255) << box(_size_x/2, _size_y/2);
    gout << color(0,0,255);
    gout << move_to(_x+_size_x+(_size_x/4)+3, _y+_size_y-2) << line(-_size_x/4,- _size_y/4);
    gout << move_to(_x+_size_x+(_size_x/4)+3, _y+_size_y-2) << line(_size_x/4,- _size_y/4);


    if (_selected  ) {

        gout << color(0,255,0);
       ostringstream convert;
        convert << egyszam;
        string  new_string_from_int = convert.str();
        gout << move_to(_x+5, _y+5+gout.cascent()) << text(new_string_from_int);

    }
}

void Szambeallito::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left ) {

        _selected = true;
    }
    if (ev.type == ev_mouse && !is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left){
        _selected = false;
    }
    if (_selected == true && ev.keycode == key_up && egyszam > _intervallum_tol && egyszam < _intervallum_ig||
        _selected == true && ev.keycode == key_up && egyszam == _intervallum_tol)
    {
        egyszam++;
    }
    if (_selected == true && ev.keycode == key_down && egyszam > _intervallum_tol && egyszam < _intervallum_ig||
        _selected == true && ev.keycode == key_down && egyszam == _intervallum_ig )
    {
        egyszam--;
    }
    if (_selected == true && ev.keycode == key_pgup && egyszam > _intervallum_tol && egyszam < _intervallum_ig ||
        _selected == true && ev.keycode == key_pgup && egyszam == _intervallum_tol )
    {
        egyszam=egyszam+10;
       if(egyszam>_intervallum_ig){egyszam=egyszam-10;}
    }
    if (_selected == true && ev.keycode == key_pgdn && egyszam > _intervallum_tol && egyszam < _intervallum_ig ||
        _selected == true && ev.keycode == key_pgdn && egyszam == _intervallum_ig )
    {
        egyszam=egyszam-10;
        if(egyszam<_intervallum_tol){egyszam=egyszam+10;}
    }
}
//bool KijelzoBox::is_checked() const
//{
//    return _selected;
//}
