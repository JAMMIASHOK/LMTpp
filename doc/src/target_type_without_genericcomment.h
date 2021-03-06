#ifndef TARGET_TYPE_WITHOUT_GENERICCOMMENT_H
#define TARGET_TYPE_WITHOUT_GENERICCOMMENT_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

#include "visitorbloc.h"
//struct VisitorBloc ;
//struct Parameter ;
//struct TemplateParameter ;
#include "parameter.h"
#include "templateparameter.h"
#include "names.h"
#include "target.h"
#include "listparameter.h"

typedef std::vector<TemplateParameter*> ListTemplateParameter ;
//typedef std::vector<Parameter*> ListParameter ;

struct Target_type_without_genericComment : public Target  {
    Target_type_without_genericComment(string& path_generic_comment) { path = path_generic_comment ; }
    virtual ~Target_type_without_genericComment() {}
    virtual void display( std::ostream &os ) ;
    friend std::ostream &operator<<( std::ostream &os, Bloc &b ) ;

    virtual bool of_type_without_generic_comment() { return true; }
} ;

#endif

