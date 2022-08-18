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
                cout << it->getNombre() ;
                enrutadores.erase(it);
                cout << " borrado exitosamente" << endl;
                break;
            }
        }
}

void Red::actualizar(Enrutador enrutador){
    bool val = false;
    int acum1 = 0;
    static int acum2 = 0;
    list<Enrutador>::iterator it;
        for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
            acum1 = 0;
            acum2 = 0;
//            cout <<it->getTabla_enrutamiento().size() ; // tamaño
            if(it->getNombre()==enrutador.getNombre()){
            cout << "Costos de: "<< it->getNombre() << endl;
            if(it->getNombre()==enrutador.getNombre()){
            if(val){
                break;
            }else{
            for (const auto& [key, value] : it->getTabla_enrutamiento()) {
                    cout << '[' << key << "] = " << value << "; ";
                    acum1 = value;
                    acum2 = 0;
                    if(val){
                        break;
                    }else{
                    for (const auto& [key2, value2] : it->getTabla_enrutamiento()) {
                        if(key!=key2){

                            acum2=acum2+value2;
                            if(acum1>acum2){
                                cout<<"buscando mejor camino"<<endl;

                                acum2=comparar(it->getNombre(),key2,key,acum1,acum2);
                                if(acum1>acum2){

                                    enrutador.desconectar(key);

                                    enrutador.conectar(key,acum2);
                                    remover(enrutador);
                                    agregar(enrutador);
//                                    it->desconectar(key);
//                                    it->conectar(enrutador,acum2);
                                    cout<<"cambio coneccion terminado"<<endl;

                                    //enrutador.print();
                                    val = true;
                                    break;
                                }
                            }
                            }
                    }}
            }}
                    }}

                }

//            if(it->getNombre()==enrutador.getNombre()){
//                cout << it->getNombre() ;
//                enrutadores.erase(it);
//                cout << " borrado exitosamente" << endl;
//                break;
//            }

}

int Red::comparar(string it2,string n,string fin, int acum1, int acum2){
//    int sum1 = 0;
//    sum1 = a.getTabla_enrutamiento().at("A");
//    if(sum1>0){

//    }
//    int acum1 = 0;
//    int acum2 = acum;

    list<Enrutador>::iterator it;
    for ((it) = enrutadores.begin(); it != enrutadores.end(); ++it){
        if(it->getNombre()==n and it->getNombre()!=fin){

        for (const auto& [key, value] : it->getTabla_enrutamiento()) {
            if(it2!=key){

                //acum1 = value;
                //acum2 = acum;
                for (const auto& [key2, value2] : it->getTabla_enrutamiento()) {
                    if(key!=key2){

                        acum2=acum2+value;
                        if(acum1>acum2){

                            acum2=comparar(it->getNombre(),key,fin,acum1,acum2);

                         }}}}}}}
    return acum2;
}

void Red::print(){

    list<Enrutador>::iterator it;
        for (it = enrutadores.begin(); it != enrutadores.end(); ++it)
            cout << it->getNombre() << endl;
}

void Red::detalle_print(){

    list<Enrutador>::iterator it;
        for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
            cout << it->getNombre() << endl;
            it->print();
        }
}

void Red::actualizar_todo(){

    list<Enrutador>::iterator it;
        for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
            cout << it->getNombre() << endl;
            it->print();
            actualizar(it->actualizar());
        }
}

