    /******************************************************************************************
    Name:         Pila.h                                                                       
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,3 2012 
    Author site:  newbufferedwriter.blogspot.org                                               
    License:      GNU  General Public License (GPL)                                                 
    Description:  Classe che descrive un particolare mazzo del gioco Klondike
    ********************************************************************************************/
#pragma once
#include "costanti.h"
#include "GruppoDiCarte.h"
#include <iostream>
#include <string>

class Pila : public GruppoDiCarte {
friend ostream& operator<<(ostream&, Pila&);
public:
	Pila(int x,int y):GruppoDiCarte(x,y){;}
	bool attacca(Carta* c);
	Seme getSeme();
	Carta* getPrimo(){return NULL;}
	bool attaccaGruppo(GruppoOrdinato*){return false;}
private:
	Seme seme;
};
