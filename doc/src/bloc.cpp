#include <iostream>
#include <string>
#include <vector>


using namespace std;
#include "bloc.h"
#include "visitorbloc.h"
#include "parameter.h"
#include "templateparameter.h"
#include "op.h"
#include "names.h"

Bloc::~Bloc() {

    int i;
    
    for(i=0;i< listTemplateParameter.size();i++) {
        delete listTemplateParameter[i];
    }
//     for(i=0;i< listTypedef.size();i++) {
//         delete listTypedef[i];
//     }
//     for(i=0;i< listMember.size();i++) {
//         delete listMember[i];
//     }

    for(i=0;i< list_subType_function.size();i++) {
        delete list_subType_function[i];
    }
}

void Bloc::display( std::ostream &os ) {


    int i,n,m,j;
    
    os << "### BLOC ### "<< endl;
    os << " namespace = " << _namespace << endl;
    os << " name = " << name.name << endl;
    os << " name principal = " << name.principalName << endl;
    os << " portee = " << portee << endl;

    n = listTemplateParameter.size();
    if (n>0) {
        os << "* liste des paramètres template" << endl;
        for(i=0;i<n;i++) {
            os << "    paramètre no " << i << endl;
            os << "    - type = " << listTemplateParameter[i]->type << endl;
            os << "    - name = " << listTemplateParameter[i]->name << endl;
            os << "    - defa = " << listTemplateParameter[i]->defaultType << endl;
        }
    }
    n = listTypedef.size();
    if (n>0) {
        os << "* liste des typedef" << endl;
        for(i=0;i<n;i++) {
            os << "    typedef no " << i << endl;
            os << "    - type           = " << listTypedef[i].type.name << endl;
            os << "    - type principal = " << listTypedef[i].type.principalName << endl;
            os << "    - synonyme       = " << listTypedef[i].nameVariable << endl;
        }
    }
    n = listMember.size();
    if (n>0) {
        os << "* liste des membres" << endl;
        for(i=0;i<n;i++) {
            os << "    membre no " << i << endl;
            os << "    - attribut       = " << listMember[i].listAttribut << endl;
            os << "    - type           = " << listMember[i].type.name << endl;
            os << "    - type principal = " << listMember[i].type.principalName << endl;
            os << "    - name           = " << listMember[i].nameVariable << endl;
            os << "    - defaultType    = " << listMember[i].defaultType << endl;
            m = listMember[i].listTag.size();
            if (m>0) {
                for(j=0;j<m;j++) {
                    os << " tag n° " << listMember[i].listTag[j] << endl;
                }
            }
        }
    }
    n = list_subType_function.size();
    if (n>0) {
        os << "* liste des structures ou des fonctions membres" << endl;
        for(i=0;i<n;i++) {
            os << "    n° " << i << endl;
            os << *list_subType_function[i] << endl;
        }
    }


}

/*inline*/ std::ostream &operator<<( std::ostream &os, Bloc &b ) { 
    b.display( os );
    return os;
};


