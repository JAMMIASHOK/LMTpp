#ifndef VISITOR_COMMENT_ITEM_IS_INTERNAL_H
#define VISITOR_COMMENT_ITEM_IS_INTERNAL_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

//using namespace std ;

//struct CommentItem ;
//struct LangRef ;

#include "visitorcommentitem.h"

struct CommentItem ;
struct CommentItemCode ;
struct CommentItemKeyword ;
struct CommentItemList ;
struct CommentItemSection ;
struct CommentItemTable ;
struct CommentItemTxt ;
struct CommentItemWebPage ;
struct CommentItemTutorial ;
struct CommentItemExample ;
struct CommentItemLaTex ;
struct CommentItemVerbatim ;
struct Target;

struct VisitorCommentItem_isInternal : public VisitorCommentItem  {
    VisitorCommentItem_isInternal( ) { parent = NULL; }
    virtual ~VisitorCommentItem_isInternal() {}
    virtual void function_at_CommentItem( CommentItem* c ) {  }
    virtual void function_at_CommentItemCode( CommentItemCode* c ) {  }
    virtual void function_at_CommentItemKeyword( CommentItemKeyword* c ) ;
    virtual void function_at_CommentItemList( CommentItemList* c ) {  }
    virtual void function_at_CommentItemSection( CommentItemSection* c ) {  }
    virtual void function_at_CommentItemTable( CommentItemTable* c ) {  }
    virtual void function_at_CommentItemTxt( CommentItemTxt* c ) {  }
    virtual void function_at_CommentItemWebPage( CommentItemWebPage* c ) {  }
    virtual void function_at_CommentItemGenericComment( CommentItemGenericComment* c ) { }
    virtual void function_at_CommentItemExample( CommentItemExample* c ) {  }
    virtual void function_at_CommentItemTutorial( CommentItemTutorial* c ) { }
    virtual void function_at_CommentItemLaTex( CommentItemLaTex* c ) {  }
    virtual void function_at_CommentItemVerbatim( CommentItemVerbatim* c ) {  }
    //void apply_on_related_to( const std::string &s, Op *op ) ;
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c ) ;
    void setParent(Target* _parent) { parent = _parent; }

    Target* parent ;
} ;


#endif

