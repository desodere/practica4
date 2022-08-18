#include <iostream>
#include "enrutador.h"
#include "red.h"

using namespace std;

void conectar(Enrutador &a, Enrutador &b, int costo);

int main()
{



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



    Red r1;
    r1.agregar(e1);
    r1.print();

    r1.agregar(e3);
    r1.print();

    r1.remover(e1);
    r1.print();

    return 0;
}


void conectar(Enrutador &a, Enrutador &b, int costo){
    a.conectar(b,costo);
    b.conectar(a,costo);
}
