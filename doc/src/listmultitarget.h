#ifndef LIST_MULTI_TARGET_H
#define LIST_MULTI_TARGET_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

#include "names.h"
#include "target.h"

typedef std::vector<Target*> VectorTarget ;

/*  
Cette structure permet de stocker les adresses d'objets Target.
Pour distinguer les adresses d'objets déjà existants (cad déjà référencé) de ceux qui
sont seulement référencé par list[i] (i indice ), je supose que ceux du dernier cas sont stockés
à la fin dans la liste list et l'entier nb_only_ref contient leur nombre.

*/
template<class T> struct ListMultiTarget {
    ListMultiTarget( ) { }
    ~ListMultiTarget() {}
    friend std::ostream &operator<<( std::ostream &os, ListMultiTarget& l ) {

        int i,n ;

        n = l.list.size() ;
        os << " attribut = " << l.attribut << std::endl ;
        for(i=0;i<n;i++) {
            os << "+++++++++ TARGET ++++++++++++" << endl ;
            os << " name = " << l.list[i]->name.name << std::endl ;
            os << " name principal = |" << l.list[i]->name.principalName << "|" << std::endl ;
        }
        return os ;
    }

    VectorTarget list ;
    T attribut ;
} ;


#endif

