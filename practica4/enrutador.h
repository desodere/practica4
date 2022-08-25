#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <iostream>
//#include <vector>
#include <string>
#include <map>
#include <list>

using namespace std;


class Enrutador
{
private:
    //vector<Enrutador> tabla_enrutamiento;
    map<string, int> tabla_enrutamiento { };
    string nombre;
    bool estado;



public:
//    Enrutador();
    Enrutador(string nom);

     Enrutador actualizar();

    const map<string, int> &getTabla_enrutamiento() const;
    const string &getNombre() const;

    void setTabla_enrutamiento(const map<string, int> &newTabla_enrutamiento);
    void setTabla_enrutamiento(string llave, int valor);
    void setTabla_enrutamiento(Enrutador enrutador, int costo);
    void setNombre(const string &newNombre);

    void print(void);
    void conectar(Enrutador &enrutador, int costo);
    void conectar(string enrutador, int costo);
    void desconectar(Enrutador &enrutador);
    void desconectar(string enrutador);

    void actualizar(Enrutador enrutador);




    bool getEstado() const;
    void setEstado(bool newEstado);
};

#endif // ENRUTADOR_H
