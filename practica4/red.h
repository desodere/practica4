#ifndef RED_H
#define RED_H

#include "enrutador.h"
#include <list>
#include <vector>

class Red
{
private:
    list<Enrutador> enrutadores;
public:
    Red();
    const list<Enrutador> &getEnrutadores() const;
    void setEnrutadores(const list<Enrutador> &newEnrutadores);

    void agregar(Enrutador enrutador);
    void remover(Enrutador enrutador);
    void actualizar(Enrutador enrutadores);
    void actualizar_todo();
    int comparar(string it, string n,string fin, int acum1, int acum2 );
    void print();
    void detalle_print();

};

#endif // RED_H
