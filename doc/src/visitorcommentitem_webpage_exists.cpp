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
#include "visitorcommentitem_webpage_exists.h"
#include "visitorcommentitem_tohtml.h"
#include "commentitemkeyword.h"
#include "commentitemtxt.h"
#include "commentitemtable.h"
#include "commentitemsection.h"
#include "commentitemcode.h"
#include "commentitemlist.h"
#include "commentitemwebpage.h"
#include "commentitemgenericcomment.h"
#include "commentitemtutorial.h"
#include "commentitemtutorial.h"
#include "commentitem.h"
#include "listtarget.h"
#include "comment.h"
#include "util2html.h"



void VisitorCommentItem_webpage_exists :: function_at_CommentItemWebPage( CommentItemWebPage* c ) {

    if (c->name.name == name)
        exists = true ;
}









