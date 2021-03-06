#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<vector>
#include<string>

using namespace std ;

//#include "visitorcommentitem_is_extuge.h"

#include "pagecomment.h"
#include "opgettype_for_principalname.h"


//#include "visitorcommentitem_getbrief_of_extuge.h"
#include "visitorcommentitem_is_extuge.h"
#include "visitorbloc_what_type.h"
//#include "visitorcommentitem_setpath_html.h"

#include "util2html.h"
#include "target.h"
#include "token.h"


/*
 cette fonction a pour objet de créer une "liste" des objets ayant le nom principal principal_name avec leurs briefs,
 un objet étant soit une classe, soit une structure, soit une fonction, soit un exemple, un tutorial ou un generic_comment.
*/

OpGetType_for_principalName :: ~OpGetType_for_principalName() {

}

void OpGetType_for_principalName :: operator()( PageComment* page ) {

    VisitorBloc_what_type what_type  ;

    VisitorCommentItem_isExTuGe is_estuge ;
    int i,n,j,m,N,k ;

    // on parcourt le bloc de la page page à la recherche d'objet ayant le nom principal principal_name et on cherche si cela corresppond à une fonction struct ou classe.
    n = page->code.list_subType_function.size() ;
    for(i=0;i<n;i++) {
        if (page->code.list_subType_function[i]->name.principalName == principal_name ) {
            page->code.list_subType_function[i]->execute_function( &what_type ) ;
            type = what_type.type ;
            return ;
        }
    }
    // ensuite on parcourt les exemples, tutoriaux et generic_comment.

    n = page->listComment.size() ;
    for(i=0;i<n;i++) {
        m = page->listComment[i]->items.size() ;
        for(j=0;j<m;j++) {
            page->listComment[i]->items[j]->execute_function( &is_estuge ) ;
            //cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAh" << is_estuge.extuge << endl ; 
            if (( is_estuge.extuge >= 0) && (is_estuge.extuge < 2) && (page->listComment[i]->items[j]->name.principalName == principal_name)) {
                // c'est donc un item du type exemple, tutoriel ou generic_comment
                if (is_estuge.extuge == 0)
                    type = "example" ;
                else
                    type = "tutorial" ;
                return ;
            }
        }
    }

}













