#include <iostream>
#include <string>
#include <vector>
#include<sstream>


using namespace std ;
#include "token.h"
#include "op.h"
#include "target.h"
#include "util2html.h"

string Target :: reference() {

    string stmp ;
    stringstream ss ;

    if ((id == INIT) || (id == NOT_ID))
        stmp = path + french2webID( name.name ) + "." + suffix_reference ;
    else {
        ss.str("") ;
        ss << id ;
        stmp = path + french2webID( name.name ) + "_" + ss.str() + "." + suffix_reference ;
    }
    return stmp ;
}

/*inline*/ std::ostream &operator<<( std::ostream &os, Target& t ) { 

    os << "+++++++++ TARGET ++++++++++++" << endl ;
    os << " name = |" << t.name.name << "|" << std::endl ;
    os << " name principal = |" << t.name.principalName << "|" << std::endl ;
    os << " path = |" << t.path << "|" << endl ;
    os << " id = " << t.id << endl ;
    os << " ancestor = " << t.ancestor << endl ;
    os << " t.reference() = " << t.reference() << endl ;
    os << " source_file = " << t.source_file << endl ;
 
    return os ;
} ;

bool Target :: operator== ( const Target& t1 ) {

    if (name.principalName == t1.name.principalName )
        return true ;
    else
        return false ;
}

bool Target :: operator< ( const Target& t1 ) {

    if (name.principalName < t1.name.principalName )
        return true ;
    else
        return false ;
}

bool inferior( Target* t1, Target* t2 ) {

    if ((t1 == 0) || (t2 == 0)) 
        return false ;

    if (*t1 < *t2)
        return true ;
    else
        return false ;
}



