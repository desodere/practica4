#include "enrutador.h"

const map<string, int> &Enrutador::getTabla_enrutamiento() const
{
    return tabla_enrutamiento;
}

void Enrutador::setTabla_enrutamiento(const map<string, int> &newTabla_enrutamiento)
{
    tabla_enrutamiento = newTabla_enrutamiento;
}

void Enrutador::setTabla_enrutamiento(string llave, int valor)
{
    tabla_enrutamiento[llave] = valor;  // insert a new value

}

void Enrutador::setTabla_enrutamiento(Enrutador enrutador, int costo)
{
    tabla_enrutamiento[enrutador.nombre] = costo;      // insert a new value

}

void Enrutador::print(void){

    cout << "Costos de: "<< nombre << endl;
    for (const auto& [key, value] : tabla_enrutamiento) {
            cout << '[' << key << "] = " << value << "; ";
        }
    cout <<  endl;
}

const string &Enrutador::getNombre() const
{
    return nombre;
}

void Enrutador::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

//Enrutador::Enrutador()
//{

//}

Enrutador::Enrutador(string nom)
{
    nombre = nom;
}

void Enrutador::conectar(Enrutador &enrutador, int costo){

    tabla_enrutamiento[enrutador.nombre] = costo;  // conecto enrutador origen a destino

    enrutador.tabla_enrutamiento[nombre] = costo;  // conecto enrutador destino a origen

}

void Enrutador::conectar(string enrutador, int costo){

    tabla_enrutamiento[enrutador] = costo;  // conecto enrutador origen a destino

//    enrutador.tabla_enrutamiento[nombre] = costo;  // conecto enrutador destino a origen

}

void Enrutador::desconectar(Enrutador &enrutador){

     map<string, int>::iterator it; // creo un iterador
     try {
         it = tabla_enrutamiento.find(enrutador.nombre);
         tabla_enrutamiento.erase (it);                   // elimino la coneccion del enrutador origen

         it = enrutador.tabla_enrutamiento.find(nombre);
         enrutador.tabla_enrutamiento.erase (it);        // elimino la coneccion del enrutador destino


     } catch (exception& e) {
         cout<<e.what()<<endl;
     }

}

void Enrutador::desconectar(string enrutador){

     map<string, int>::iterator it; // creo un iterador

    it = tabla_enrutamiento.find(enrutador);
    tabla_enrutamiento.erase (it);                   // elimino la coneccion del enrutador origen

//    it = enrutador.tabla_enrutamiento.find(nombre);
//    enrutador.tabla_enrutamiento.erase (it);        // elimino la coneccion del enrutador destino


}

Enrutador Enrutador::actualizar(){

    return *this;
}
