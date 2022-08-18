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
    void actualizar();
    void print();

};

#endif // RED_H
