#include <iostream>
#include "enrutador.h"
#include "red.h"

#include "enrutador.h"
#include <list>
#include <vector>
#include <string>

#include <iostream>
//#include <vector>
#include <string>
#include <map>
#include <list>

using namespace std;

void conectar(Enrutador &a, Enrutador &b, int costo);
void c(Red r1);

int main()
{

/*
//PRIMERA PARTE DE LA SUSTENTACION ***************************
    //creo los enrutadores

    Enrutador e1("A");
    Enrutador e2("B");
    Enrutador e3("D");
    Enrutador e4("C");
    Enrutador e5("E");

    //Conecto los enrutadores
    e2.conectar(e1,4);
    e2.conectar(e3,1);
    e3.conectar(e4,2);
    e1.conectar(e4,10);
    e1.conectar(e5,1);
    e5.conectar(e4,1);

    //Creo la red
    Red r1;

    //Agrego los enrutadores a la red
    r1.agregar(e1);
    r1.agregar(e2);
    r1.agregar(e3);
    r1.agregar(e4);
    r1.agregar(e5);

//    r1.recorrer(e1);

    r1.detalle_print();
    cout<<"===================="<<endl;

//    r1.recorrer(e4);

    //r1.detalle_print();

    cout<<"=========Agregar enrutador a la red==========="<<endl;
    Enrutador e6("Z");
    //e1.print();
    e6.conectar(e2,20);

    e6.conectar(e3,10);

    r1.agregar(e2);
    r1.agregar(e3);
    r1.agregar(e6);


    r1.detalle_print();
    cout<<"===================="<<endl;

    r1.recorrer(e1);
    r1.recorrer(e2);
    r1.recorrer(e3);
    r1.recorrer(e4);
    r1.recorrer(e5);
    r1.recorrer(e6);

    r1.detalle_print();
    cout<<"===================="<<endl;
*/
/*
//SEGUNDA PARTE DE LA SUSTENTACION ***************************
    //Declaracion de variables
    int opcion = 0, coste = 0 ;
    bool salir = false;
    string nombre_enrutador, nombre_destino;
    //creo los enrutadores

    Enrutador e1("A");
    Enrutador e2("B");
    Enrutador e3("D");
    Enrutador e4("C");
    Enrutador e5("E");

    //e5.setEstado(false);
    //Conecto los enrutadores
    e1.conectar(e2,4);
    e2.conectar(e3,1);
    e3.conectar(e4,2);
    e1.conectar(e4,10);
    e1.conectar(e5,1);
    e5.conectar(e4,1);

    //Creo la red
    Red r1;

    //Agrego los enrutadores a la red
    r1.agregar(e1);
    r1.agregar(e2);
    r1.agregar(e3);
    r1.agregar(e4);
    r1.agregar(e5);



    while(!salir){
        cout<<"========Inicio de la practica 4========="<<endl;

        cout<<"Menu"<<endl;
        cout<<"1. Crear enrutador"<<endl;
        cout<<"2. Remover enrutador"<<endl;
        cout<<"3. Listar Enrutadores"<<endl;
        cout<<"4. Costo por enviar un paquete desde un enrutador origen a uno destino."<<endl;
        cout<<"5. Actualizar red"<<endl;
        cout <<"0. Salir"<<endl;

        while (true) {
            cout << "Ingresa la opcion: ";
            if (cin >> opcion) {
                break;
            } else {
                cout << "Ingrese un opcion valida!\n";
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        if(opcion==1){
            //Enrutador aux("AUX"); //Enrutador auxiliar
            cout << "Ingrese el nombre del enrutador" << endl;
            cin >> nombre_enrutador ;

            cout << "Ingrese el nombre del enrutador destino" << endl;
            cin >> nombre_destino ;

            cout << "Ingrese coste: " << endl;
            cin >> coste ;

            r1.agregar(nombre_enrutador, nombre_destino, coste);
            //r1.agregar(nombre_destino, nombre_enrutador, coste);
            r1.actualizar_todo();
//            r1.actualizar_enrutador(e1);
//            r1.actualizar_enrutador(e2);
//            r1.actualizar_enrutador(e3);
//            r1.actualizar_enrutador(e4);
//            r1.actualizar_enrutador(e5);

            //aux = r1.buscar(nombre_enrutador);

            //r1.actualizar_enrutador(aux);

//            cout << aux.getNombre() << endl;
//            cout << aux.getEstado()<< endl;


        }else if(opcion==2){

            cout << "Ingrese el nombre del enrutador" << endl;
            cin >> nombre_enrutador;
            Enrutador aux(nombre_enrutador); //Enrutador auxiliar;
            //aux = r1.buscar(nombre_enrutador);
            r1.remover(nombre_enrutador);
            aux = r1.buscar(nombre_enrutador);
            if(!aux.getEstado())
                cout <<"borrado"<< endl;
            else
                cout <<"no borrado"<< endl;
        }else if(opcion==3){
            r1.detalle_print();
        }else if(opcion==5){
            int size = r1.getEnrutadores().size() ;
            r1.actualizar_todo();
           // c( r1);
//            for (int var = 0; var < size; ++var) {
//                r1.actualizar_todo();
//            }

            //r1.detalle_print();
            cout <<"Todo actualizado! " << endl;
        }else{
            cout<<"construccion"<<endl;
        }

    }
*/
    cout<<"========FIN========="<<endl;

    return 0;
}

/*
void conectar(Enrutador &a, Enrutador &b, int costo){
    a.conectar(b,costo);
    b.conectar(a,costo);
}
*/

void c(Red r1){
    vector<Enrutador>::iterator ite;
    for (auto edad = r1.getEnrutadores().begin(); edad != r1.getEnrutadores().end(); edad++){
        cout << edad->getNombre() << endl;
        cout << "Enrutador: "<<edad->getNombre()<<" ";
        //actualizar(ite->actualizar());
        if(edad->getEstado()){
            r1.recorrer(*edad.base());
        }
    }

}
