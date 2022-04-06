    /******************************************************************************************
    Name:         Mazzo.h                                                                       
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,2 2012 
    Author site:  newbufferedwriter.blogspot.org                                               
    License:      GNU  General Public License (GPL)                                                 
    Description:  Classe che descrive un generico mazzo di carte di 52 elementi
    ********************************************************************************************/
#pragma once
#include "costanti.h"
#include "GruppoDiCarte.h"
#include <string>
using namespace std;

class Mazzo : public GruppoDiCarte {
public:
	Mazzo();
	void ordina();
private:
	string toString(int);
};
