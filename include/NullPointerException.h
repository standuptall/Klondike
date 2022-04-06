    /******************************************************************************************
    Name:         NullPointerException.h                                                                       
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,11 2012 
    Author site:  newbufferedwriter.blogspot.org                                               
    License:      GNU  General Public License (GPL)                                                 
    Description:  Eccezione 
    ********************************************************************************************/
#pragma once
#include "costanti.h"
#include <string>
using namespace std;
class NullPointerException {
public:
    NullPointerException(const char* s){message = s;}
    const char* getMessage(){return message;}
private:
    const char* message;    
};
