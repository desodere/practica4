#include "red.h"

const vector<Enrutador> &Red::getEnrutadores() const
{
    return enrutadores;
}

void Red::setEnrutadores(const vector<Enrutador> &newEnrutadores)
{
    enrutadores = newEnrutadores;
}

Red::Red()
{

}

void Red::agregar(Enrutador enrutador){
    bool val = true;

    vector<Enrutador>::iterator it;
    for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
        //cout << it->getNombre() << endl;
        if(enrutador.getNombre()==it->getNombre()){
            val = false;
            break;
        }
//        cout << "Enrutador: "<<it->getNombre()<<" ";
//        actualizar(it->actualizar());
    }
    if(val){
        enrutadores.push_back(enrutador) ;
        cout << "Agregado nuevo enrutador"<<endl;

    }else{
        remover(enrutador);
        enrutadores.push_back(enrutador) ;
        cout << "actualizado nuevo enrutador"<<endl;
        //actualizar_todo();
        //actualizar_enrutador(enrutador);

    }
    //actualizar_todo();


}

void Red::agregar(string enrutador_origen, string enrutador_destino, int costo){
    bool val = true;
    Enrutador enrutador_nuevo(enrutador_origen);
    enrutador_nuevo.conectar(enrutador_destino,  costo);

    vector<Enrutador>::iterator it;
    for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
        //cout << it->getNombre() << endl;
        if(enrutador_origen==it->getNombre()){
            val = false;

            break;
        }
//        cout << "Enrutador: "<<it->getNombre()<<" ";
//        actualizar(it->actualizar());
    }
    if(val){

        enrutadores.push_back(enrutador_nuevo) ;
        cout << "Agregado nuevo enrutador"<<endl;

    }else{
        Enrutador ee("q") ;
        //ee = buscar(enrutador_origen);
        //ee.setTabla_enrutamiento(enrutador_destino,costo);
        //enrutador_nuevo.setTabla_enrutamiento( ee.getTabla_enrutamiento());
        remover(enrutador_nuevo);
        enrutadores.push_back(enrutador_nuevo) ;
        cout << "actualizado nuevo enrutador"<<endl;
        //actualizar_todo();
        //actualizar_enrutador(enrutador);
//        for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
//            //cout << it->getNombre() << endl;
//            if(enrutador_destino==it->getNombre()){
//                it->setTabla_enrutamiento(enrutador_origen,costo);
//                break;
//            }
//    //        cout << "Enrutador: "<<it->getNombre()<<" ";
//    //        actualizar(it->actualizar());
//        }

    }
    //actualizar_todo();


}

void Red::remover(Enrutador enrutador){

    vector<Enrutador>::iterator it;
        for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
            //cout << it->getNombre() << endl;
            if(it->getNombre()==enrutador.getNombre()){
                //cout << it->getNombre() ;
                enrutadores.erase(it);
                //cout << " borrado exitosamente" << endl;
                break;
            }
        }
}

void Red::remover(string enrutador){

    vector<Enrutador>::iterator it;
        for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
            //cout << it->getNombre() << endl;
            if(it->getNombre()==enrutador){
                //cout << it->getNombre() ;
                //enrutadores.erase(it);
                it->setEstado(false);

            }else{
                for (const auto& [key1, value1] : it->getTabla_enrutamiento()) {

                    if(key1==enrutador){
                        cout << "***Costos de: " << '[' << key1 << "] " << endl;
                        it->setTabla_enrutamiento(enrutador,-1);
                    }
                }
            }


        }

        for (it = enrutadores.begin(); it != enrutadores.end(); ++it){

            for (const auto& [key1, value1] : it->getTabla_enrutamiento()) {

                if(key1!=enrutador){
                    cout << "***Costos de: " << '[' << key1 << "] " << endl;
                    //it->desconectar(enrutador);
                }
            }

        }

}

void Red::actualizar(Enrutador enrutador){
    bool val = false;
    int acum1 = 0;
    static int acum2 = 0;
    vector<Enrutador>::iterator it;
        for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
            acum1 = 0;
            acum2 = 0;

            if(it->getNombre()==enrutador.getNombre()){
            //cout << "Costos de: "<< it->getNombre() << endl;


//            if(val){
//                break;
//            }else{
                for (const auto& [key, value] : it->getTabla_enrutamiento()) {
                        //cout << '[' << key << "] = " << value << "; ";
                        acum1 = value;
                        acum2 = 0;
//                        if(val){
//                            break;
//                        }else{
                            for (const auto& [key2, value2] : it->getTabla_enrutamiento()) {
                                if(key!=key2){

                                    acum2=acum2+value2;
                                    if(acum1>acum2){
                                        //cout<<"buscando mejor camino"<<endl;

                                        acum2=comparar(it->getNombre(),key2,key,acum1,acum2);
                                        if(acum1>acum2){

                                            enrutador.desconectar(key);

                                            enrutador.conectar(key,acum2);
                                            //remover(enrutador);
                                            agregar(enrutador);
                                            //actualizar_enrutador(enrutador);
                                            //cout<<"cambio coneccion terminado"<<endl;

                                            val = true;
                                            //break;
                                          }
                                     }else{
                                        acum2=acum2-value2;
                                    }
                                }
                             }



            }
        }

    }

    cout<<endl;
    cout<<"actualizado sin inconvenientes"<<endl;
}

int Red::comparar(string cabeza,string cuerpo,string cola, int acum1, int acum2){
//    int sum1 = 0;
//    sum1 = a.getTabla_enrutamiento().at("A");
//    if(sum1>0){

//    }
//    int acum1 = 0;
//    int acum2 = acum;

    vector<Enrutador>::iterator it;
    for ((it) = enrutadores.begin(); it != enrutadores.end(); ++it){
        //cout << it->getNombre() << endl;
        if(it->getNombre()==cuerpo and it->getNombre()!=cola){

        for (const auto& [key, value] : it->getTabla_enrutamiento()) {
            if(cabeza!=key){

                //acum1 = value;
                //acum2 = acum;
                for (const auto& [key2, value2] : it->getTabla_enrutamiento()) {
                    if(key!=key2){

                        acum2=acum2+value;
                        if(acum1>acum2){

                            acum2=comparar(it->getNombre(),key,cola,acum1,acum2);

                         }/*else if(value!=value2){acum2=acum2-value;}*/}}}}}}
    return acum2;
}

void Red::print(){

    vector<Enrutador>::iterator it;
        for (it = enrutadores.begin(); it != enrutadores.end(); ++it)
            cout << it->getNombre() << endl;
}

void Red::detalle_print(){
    cout<<endl;
    cout<<"========Lista de conecciones de los enrutadores de la red========="<<endl;
    cout<<endl;
    vector<Enrutador>::iterator it;
        for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
            //cout << it->getNombre() << endl;

            if(it->getEstado() ){
                it->print();
            }
        }
}

void Red::actualizar_todo(){
/*
    vector<Enrutador>::iterator ite;
    for (ite = enrutadores.begin(); ite != enrutadores.end(); ++ite){
        cout << ite->getNombre() << endl;
        cout << "Enrutador: "<<ite->getNombre()<<" ";
        //actualizar(ite->actualizar());
        if(ite->getEstado()){
            recorrer(ite->actualizar());
        }
    }
    */

    for (auto e = enrutadores.begin(); e != enrutadores.end(); e++){
        cout << e->getNombre() << endl;
        cout << "Enrutador: "<<e->getNombre()<<" ";
        //actualizar(ite->actualizar());
        if(e->getEstado()){
            recorrer(e->actualizar());
        }
    }
}

void Red::recorrer(Enrutador enrutador){
    int aux1 = 0;
    int aux2 = 0;
    string nombre = enrutador.getNombre();
    string enrutador2 ;
    int costo = 0 ;
    bool val = false;
    //cout << "||||***COSTOS DE: "<< enrutador.getNombre()  << endl;
    for (const auto& [key1, value1] : enrutador.getTabla_enrutamiento()) {
        //cout << "***Costos de: "<< enrutador.getNombre() << '[' << key1 << "] " << endl;
            //cout << '[' << key1 << "] = " << value1 << "; ";
        if(value1>0){
            aux1 = value1;
            for (const auto& [key2, value2] : enrutador.getTabla_enrutamiento()) {
                if(value2>0){
                    if(key1!=key2){
                        //cout << '[' << key2 << "] = " << value2 << "; ";
                        aux2 = value2;

                        if(aux1>aux2){
                            //cout <<"X"<<  endl;
                            aux2=paso3(nombre, key2, key1, aux1,  aux2);
                            if(aux1>aux2){
//                                cout <<"Mejor camino encontrado"<<   endl;
//                                cout << "--Costos nuevo: " << '[' << aux2 << "] " << endl;
                                enrutador2 = key1;
                                costo = aux2;
                                val = true;

                            }else{
                                //cout <<"camino mas costoso"<<  endl;
                            }
                            //cout <<"terminado"<<  endl;
                            aux1 = aux2;
                        }else{
                            //aux2 = 0;
                        }
                    }
                }}
        }
    }
    if(val){
    enrutador.desconectar(enrutador2);

    enrutador.conectar(enrutador2,costo);
    //remover(enrutador);
    agregar(enrutador);
    //cout <<"Mejor camino encontrado"<<   endl;
    //cout << "--Costos nuevo: " << '[' << costo << "] " << endl;
    }
    //cout <<  endl;

    //return aux2;
}

int Red::paso3(string cabeza,string cuerpo,string cola, int acum1, int acum2){
    int aux1 = 0;
    int aux2 = acum2;
    string nombre = cuerpo;


    vector<Enrutador>::iterator it;
        for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
            //cout << it->getNombre() << endl;
            if(cuerpo==it->getNombre() and it->getNombre()!=cola){
                for (const auto& [key1, value1] : it->getTabla_enrutamiento()) {
                    if(cabeza!=key1 and (value1>0)){
                    //cout << " "<< it->getNombre() << '[' << key1 << "] " << endl;
                        //cout << '[' << key1 << "] = " << value1 << "; ";
                        aux1 = value1+acum2;
                        aux2 = value1;
                        if(acum1>aux1 and cola!=key1){
                            //cout <<"X"<<  endl;
                            aux2=paso3(nombre, key1, cola, acum1,  aux1);
                            aux1 = aux2;
                        }else{
                            aux2 = aux2 - value1;
                        }

                      /*  for (const auto& [key2, value2] : it->getTabla_enrutamiento()) {
                            if(cabeza!=key2){
                                if(key1!=key2){
                                    //cout << '[' << key2 << "] = " << value2 << "; ";
                                    aux2 = value2;

                                    if(aux1>aux2){
                                        cout <<"X"<<  endl;
                                        aux2+=paso3(nombre, key1, key2, aux1,  aux2);
                                    }else{

                                    }
                                }
                            }
                    }*/
                    }
                }
            }

        }


    //cout <<  endl;

    return aux1;
}

void Red::actualizar_enrutador(Enrutador &enrutador){
    vector<Enrutador>::iterator it;
    for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
        //cout << it->getNombre() << endl;
        if(enrutador.getNombre()==it->getNombre()){

            //cout << "Enrutador: "<<it->getNombre()<<" ";
            //actualizar(it->actualizar());
            enrutador.setTabla_enrutamiento(it->getTabla_enrutamiento());
            break;
        }

    }
}

Enrutador Red::buscar(string enrutador){
    Enrutador enrutador_aux(enrutador);
    vector<Enrutador>::iterator it;
    for (it = enrutadores.begin(); it != enrutadores.end(); ++it){
        //cout << it->getNombre() << endl;
        if(enrutador==it->getNombre()){
            //enrutador_aux.setTabla_enrutamiento(it->getTabla_enrutamiento());
            enrutador_aux = *it;
            //cout << "Enrutador: "<<it->getNombre()<<" ";
            //actualizar(it->actualizar());
            //enrutador.setTabla_enrutamiento(it->getTabla_enrutamiento());
            break;
        }

    }
    return enrutador_aux;
}
