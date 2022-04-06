    /******************************************************************************************
    Name:         Tavolo.h                                                                       
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,2 2012 
    Author site:  newbufferedwriter.blogspot.org                                               
    License:      GNU  General Public License (GPL)                                                 
    Description:  Classe che descrive il tavolo di gioco del Klondike
    ********************************************************************************************/
#pragma once
#include "costanti.h"
#include "Mazzo.h"
#include "GruppoOrdinato.h"
#include "Pila.h"
#include "MazzoMaster.h"
#include <iostream>
using namespace std;
class Tavolo {
friend ostream& operator<<(ostream&,Tavolo&);
public:
	Tavolo(Mazzo*);
	void info();
	void checkGruppiOrdinati();
	void scopriCarta(); //per scoprire la carta di sotto quando un gruppo ordinato è esaurito
	unsigned int contaCarte();
	MazzoMaster* getMaster(){return master;}
	GruppoDiCarte* getTerra(){return terra;}
	GruppoOrdinato* getg1(){return g1;}
	GruppoOrdinato* getg2(){return g2;}
	GruppoOrdinato* getg3(){return g3;}
	GruppoOrdinato* getg4(){return g4;}
	GruppoOrdinato* getg5(){return g5;}
	GruppoOrdinato* getg6(){return g6;}
	GruppoOrdinato* getg7(){return g7;}
	GruppoDiCarte* gets2(){return s2;}
	GruppoDiCarte* gets3(){return s3;}
	GruppoDiCarte* gets4(){return s4;}
	GruppoDiCarte* gets5(){return s5;}
	GruppoDiCarte* gets6(){return s6;}
	GruppoDiCarte* gets7(){return s7;}
	Pila* getp1(){return p1;}
	Pila* getp2(){return p2;}
	Pila* getp3(){return p3;}
	Pila* getp4(){return p4;}

private:
	MazzoMaster* master;
	GruppoDiCarte* terra;

	GruppoOrdinato* g1;
	GruppoOrdinato* g2;
	GruppoOrdinato* g3;
	GruppoOrdinato* g4;
	GruppoOrdinato* g5;
	GruppoOrdinato* g6;
	GruppoOrdinato* g7;
	

	GruppoDiCarte* s2;
	GruppoDiCarte* s3;
	GruppoDiCarte* s4;
	GruppoDiCarte* s5;
	GruppoDiCarte* s6;
	GruppoDiCarte* s7;

	Pila* p1;
	Pila* p2;
	Pila* p3;
	Pila* p4;
};
