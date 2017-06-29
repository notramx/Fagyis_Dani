#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include "statictext.hpp"
#include "texteditor.hpp"
#include "window.hpp"
#include "pushbutton.hpp"
#include "szambeallito.hpp"
#include "selector.hpp"

#include <vector>
#include <string>
#include <sstream>

using namespace std;
using namespace genv;


///////////////////////////////////////////////////
class ValamiButton;
class MyWindow;



class MyWindow : public Window
{

public:




    TextEditor *ed1;


    Szambeallito * _szambeallito;
    Selector * Kijelolos;
    Selector * Nem_Kijelolos;

    ValamiButton * Torol;
    ValamiButton * Feltolt;
    ValamiButton * Hozzaad;
    ValamiButton * Kiadas;





    MyWindow() ;



    void esemeny(string mitortent) {

    }
    static void fv(Window *);
    void valami()
    {


        for(int i=0; i < vs.size();i++)
        {
            vs[i].fagyi_ertek = 10;
        }

        Kijelolos->setvs(vs);
        Nem_Kijelolos->setvs(vs);
    }
    void hozzaad_valami()
    {
        ls.s= ed1->value();
        ls.fagyi_ertek = _szambeallito->value();

        vs.push_back(ls);

        Kijelolos->setvs(vs);
        Nem_Kijelolos->setvs(vs);
    }
    void torol_valami()
    {
        for(int i=Kijelolos->getselected();i<vs.size()-1;i++ )
        {
            vs[i]=vs[i+1];

        }
        vs.pop_back();

        Kijelolos->setvs(vs);
        Nem_Kijelolos->setvs(vs);

    }
    void kiadas_valami()
    {
    if(vs[Kijelolos->getselected()].fagyi_ertek - _szambeallito->value()>=0)
    vs[Kijelolos->getselected()].fagyi_ertek = vs[Kijelolos->getselected()].fagyi_ertek - _szambeallito->value();

        Kijelolos->setvs(vs);
        Nem_Kijelolos->setvs(vs);
    }
};

class ValamiButton : public PushButton
{
    MyWindow * mywparent;
    string _azonosito;
public:
    ValamiButton(MyWindow * parent, int x, int y, int sx,
                 int sy, std::string s, string azonosito)
        :PushButton(x, y, sx, sy, s),_azonosito(azonosito)
    {
        mywparent = parent;

    }
    virtual void action() ;
};


MyWindow::MyWindow()
{
        ls.s = "vanilia";
        ls.fagyi_ertek = 10;
        vs.push_back(ls);
        ls.s = "tutti-frutti";
        ls.fagyi_ertek = 10;
        vs.push_back(ls);
        ls.s = "karamell";
        ls.fagyi_ertek = 10;
        vs.push_back(ls);
        ls.s = "rumosdió";
        ls.fagyi_ertek = 10;
        vs.push_back(ls);
        ls.s = "kávé";
        ls.fagyi_ertek = 10;
        vs.push_back(ls);


        ed1 = new TextEditor(10,50,100,40,"editor");

        Feltolt = new ValamiButton(this, 40,200,100,40,"Feltölt","feltolt");
        Torol = new ValamiButton(this, 40,250,100,40,"Töröl","torol");
        Hozzaad = new ValamiButton(this, 40,300,100,40,"Hozzáad","hozzaad");
        Kiadas = new ValamiButton(this, 40,350,100,40,"Kiadás","kiadas");

        _szambeallito = new Szambeallito(80,120,40,60,1,10);
        Kijelolos = new Selector(150,10,180,40,vs,true);
        Nem_Kijelolos = new Selector(150,180,180,40,vs,false);



        widgets.push_back(ed1);

        widgets.push_back(Feltolt);
        widgets.push_back(Torol);
        widgets.push_back(Hozzaad);
        widgets.push_back(Kiadas);
        widgets.push_back(_szambeallito);
        widgets.push_back(Kijelolos);
        widgets.push_back(Nem_Kijelolos);






}




void ValamiButton::action()
{
    if(_azonosito == "feltolt")

     mywparent->valami();

     if(_azonosito == "hozzaad")

     mywparent->hozzaad_valami();

     if (_azonosito == "torol")

     mywparent->torol_valami();

     if (_azonosito == "kiadas")

     mywparent->kiadas_valami();

}

int main()
{
    gout.open(800,800);
    MyWindow *mywindow = new MyWindow;
    mywindow->event_loop();
    return 0;
}
