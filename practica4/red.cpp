#include "red.h"

const list<Enrutador> &Red::getEnrutadores() const
{
    return enrutadores;
}

void Red::setEnrutadores(const list<Enrutador> &newEnrutadores)
{
    enrutadores = newEnrutadores;
}

Red::Red()
{

}

void Red::agregar(Enrutador enrutador){
    enrutadores.push_back(enrutador) ;
}

void Red::remover(Enrutador enrutador){

    list<Enrutador>::iterator it;
        for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
            cout << it->getNombre() << endl;
            if(it->getNombre()==enrutador.getNombre()){
                enrutadores.erase(it);
                cout << "Borrado" << endl;
                break;
            }
        }
}

void Red::actualizar(){

}

void Red::print(){

    list<Enrutador>::iterator it;
        for (it = enrutadores.begin(); it != enrutadores.end(); ++it)
            cout << it->getNombre() << endl;
}

