    /******************************************************************************************
    Name:         GruppoOrdinato.h                                                                
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,3 2012 
    Author site:  newbufferedwriter.blogspot.org                                               
    License:      GNU  General Public License (GPL)                                                 
    Description:  Classe che descrive un gruppo di carte ordinato in maniera decrescente e a colori alterni
    ********************************************************************************************/
#pragma once
#include "costanti.h"
#include "GruppoDiCarte.h"
#include <iostream>
using namespace std;

class GruppoOrdinato : public GruppoDiCarte {
friend ostream& operator<<(ostream&, GruppoOrdinato&);
public:
	GruppoOrdinato(GruppoDiCarte*,int,int);
	bool attacca(Carta*);
	bool attaccaGruppo(GruppoOrdinato*);
	void push(Carta*);
	Carta* getPrimo();
	Carta* staccaPrimo();
	void setAttaccaPrimaVolta(); //uso riservato solamente a tavolo.h
	Carta** getCarte(){return carte;}
	GruppoDiCarte* getS(){return s;}
private:
	bool attaccaPrimaVolta;
	GruppoDiCarte* s;
};
