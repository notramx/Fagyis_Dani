#ifndef SZAMBEALLITO_HPP_INCLUDED
#define SZAMBEALLITO_HPP_INCLUDE

#include <string>

#include "graphics.hpp"
#include "widgets.hpp"
using namespace std;

class Szambeallito : public Widget {
protected:
    bool _selected;
  // string new_string_from_int;
    int egyszam;

public:
    Szambeallito(int x, int y, int sx, int sy,int intervallum_tol, int intervallum_ig);
    virtual void draw()  ;
    virtual void handle(genv::event ev);
    inline int value() {return egyszam;}
   // virtual bool is_checked() const ;
};


#endif

