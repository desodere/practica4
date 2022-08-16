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

void Enrutador::conectar(Enrutador enrutador, int costo){

    tabla_enrutamiento[enrutador.nombre] = costo;  // insert a new value


}
