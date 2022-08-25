#ifndef RED_H
#define RED_H

#include "enrutador.h"
#include <list>
#include <vector>
#include <string>
#include <map>
#include <utility>

class Red
{
private:
    vector<Enrutador> enrutadores;
public:
    Red();
    const vector<Enrutador> &getEnrutadores() const;
    void setEnrutadores(const vector<Enrutador> &newEnrutadores);

    void agregar(Enrutador enrutador);
    void agregar(string enrutador_origen, string enrutador_destino, int costo);
    void remover(Enrutador enrutador);
    void remover(string enrutador);
    void actualizar(Enrutador enrutadores);
    void actualizar_todo();
    void actualizar_enrutador(Enrutador &enrutador);
    int comparar(string it, string n,string fin, int acum1, int acum2 );
    void print();
    void detalle_print();
    void recorrer(Enrutador enrutador);
    int paso3(string cabeza,string cuerpo,string cola, int acum1, int acum2);

    Enrutador buscar(string enrutador);
};

#endif // RED_H
