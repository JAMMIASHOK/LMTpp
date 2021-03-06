#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>

#include<cmath>
#include"time.h"


using namespace std ;

#include "visitorcommentitem.h"
#include "visitorcommentitem_setpath_html.h"
#include "commentitemkeyword.h"
#include "commentitemtxt.h"
#include "commentitemtable.h"
#include "commentitemsection.h"
#include "commentitemcode.h"
#include "commentitemlist.h"
#include "commentitemwebpage.h"
#include "commentitemgenericcomment.h"
#include "commentitemexample.h"
#include "commentitemtutorial.h"
#include "commentitemwebpage.h"
#include "commentitemlatex.h"
#include "commentitem.h"
#include "listtarget.h"
#include "comment.h"
#include "util2html.h"

void VisitorCommentItem_setPath_HTML :: setRepertory_example( const string& s ) {

    repertory_example = s ;
}


void VisitorCommentItem_setPath_HTML :: setRepertory_genericComment( const string& s ) {

    repertory_genericComment = s ;
}


void VisitorCommentItem_setPath_HTML :: setRepertory_tutorial( const string& s ) {

    repertory_tutorial = s ;
}

void VisitorCommentItem_setPath_HTML :: setRepertory_webpage( const string& s ) {

    repertory_webpage = s ;
}

void VisitorCommentItem_setPath_HTML :: setRepertory_image( const string& s ) {

    repertory_image = s ;
}

void VisitorCommentItem_setPath_HTML :: function_at_CommentItemGenericComment( CommentItemGenericComment* c ) {

    c->path = repertory_genericComment ;
}

void VisitorCommentItem_setPath_HTML :: function_at_CommentItemExample( CommentItemExample* c ) {

    int i,n;
    VisitorCommentItem_setPath_HTML visi;

    c->path = repertory_example ;
    visi.setRepertory_image( repertory_image ) ;
    n = c->items.size();
    for(i=0;i<n;i++)
        c->items[i]->execute_function( &visi );
}

void VisitorCommentItem_setPath_HTML :: function_at_CommentItemTutorial( CommentItemTutorial* c ) {

    int i,n;
    VisitorCommentItem_setPath_HTML visi;

    c->path = repertory_tutorial ;
    visi.setRepertory_image( repertory_image ) ;
    n = c->items.size();
    for(i=0;i<n;i++)
        c->items[i]->execute_function( &visi );
}

void VisitorCommentItem_setPath_HTML :: function_at_CommentItemWebPage( CommentItemWebPage* c ) {

    int i,n;
    VisitorCommentItem_setPath_HTML visi;

    c->path = repertory_webpage ;
    visi.setRepertory_image( repertory_image ) ;
    n = c->items.size();
    for(i=0;i<n;i++)
        c->items[i]->execute_function( &visi );
}



void VisitorCommentItem_setPath_HTML :: function_at_CommentItemLaTex( CommentItemLaTex* c ) {

    c->path = repertory_image ;
}



