#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

#include "commentitemtxt.h"


CommentItemTxt :: CommentItemTxt( ) {
   //std::cout << "**toto**"<< std::endl;
}

    
void CommentItemTxt :: addString( string& s ) {
 txt.push_back( s ) ;
}


void CommentItemTxt :: display( std::ostream &os ) {

 int i ;
 os << "CommentItemTxt : txt =" << endl ;
 for(i=0;i<txt.size();i++)  os  << txt[i] << endl ;
 os << "fin CommentItemTxt" << endl ;
}


