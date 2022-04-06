    /******************************************************************************************
    Name:         GruppoDiCarte.h                                                                       
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,2 2012 
    Author site:  newbufferedwriter.blogspot.org                                               
    License:      GNU  General Public License (GPL)                                                 
    Description:  Classe che descrive un gruppo generico di carte
    ********************************************************************************************/
#pragma once
#include "costanti.h"
#include "Carta.h"
#include <iostream>
using namespace std;
class GruppoOrdinato;
#define MAX_CARTE 52

class GruppoDiCarte{
friend ostream& operator<<(ostream&,GruppoDiCarte&);
public:
	GruppoDiCarte(int,int);
	GruppoDiCarte(unsigned int,int,int);
	unsigned int getNCarte(){return nCarte;}
	void setCarta(unsigned int);
	void mescola();
	virtual void ordina();
	virtual Carta* getPrimo(){return NULL;}
	virtual bool attaccaGruppo(GruppoOrdinato*){return false;}
	void stampa();
    Carta* pop();
	void push(Carta*);
	Carta* vediCarta();
	virtual bool attacca(Carta*);
	void reverse();
protected:
	unsigned int nCarte;
	Carta* carte[MAX_CARTE];
	int x;
	int y;
};
