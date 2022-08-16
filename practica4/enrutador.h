#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <iostream>
//#include <vector>
#include <string>
#include <map>

using namespace std;


class Enrutador
{
private:
    //vector<Enrutador> tabla_enrutamiento;
    map<string, int> tabla_enrutamiento { };
    string nombre;

public:
//    Enrutador();
    Enrutador(string nom);

    const map<string, int> &getTabla_enrutamiento() const;
    const string &getNombre() const;

    void setTabla_enrutamiento(const map<string, int> &newTabla_enrutamiento);
    void setTabla_enrutamiento(string llave, int valor);
    void setTabla_enrutamiento(Enrutador enrutador, int costo);
    void setNombre(const string &newNombre);

    void print(void);
    void conectar(Enrutador enrutador, int costo);





};

#endif // ENRUTADOR_H