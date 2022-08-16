#include <iostream>
#include "enrutador.h"

using namespace std;

void conectar(Enrutador &a, Enrutador &b, int costo);

int main()
{

//    Enrutador e1("E1");

//    e1.print();

//    e1.setTabla_enrutamiento("A",12);

//    e1.print();

//    Enrutador e2("E2");
//    //e2.setTabla_enrutamiento(e1.getTabla_enrutamiento());

//    e2.print();

//    e2.setTabla_enrutamiento("A",12);
//    e2.setTabla_enrutamiento("C",4);
//    e2.setTabla_enrutamiento("D",7);

//    e2.print();

//    e2.setTabla_enrutamiento(e1,100);

//    e2.print();

//    e1.setTabla_enrutamiento(e2,100);

//    e1.print();

    Enrutador e1("A");
    Enrutador e2("B");
    Enrutador e3("D");
    Enrutador e4("C");

//    e1.setTabla_enrutamiento(e2,4);
//    e2.setTabla_enrutamiento(e3,1);
//    e3.setTabla_enrutamiento(e4,2);
//    e1.setTabla_enrutamiento(e4,10);

    conectar(e2,e1,4);
    conectar(e2,e3,1);
    conectar(e3,e4,2);
    conectar(e4,e1,10);
//    e2.conectar(e1,4);
//    e2.conectar(e3,1);
//    e3.conectar(e4,2);
//    e1.conectar(e4,10);

    e1.print();
    e2.print();
    e3.print();
    e4.print();



    return 0;
}


void conectar(Enrutador &a, Enrutador &b, int costo){
    a.conectar(b,costo);
    b.conectar(a,costo);
}
