    /******************************************************************************************
    Name:         Risolutore.h                                                                       
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,3 2012 
    Author site:  newbufferedwriter.blogspot.org                                               
    License:      GNU  General Public License (GPL)                                                 
    Description:  Classe che simula il comportamento di un giocatore di Klondike
    ********************************************************************************************/
#pragma once
#include "costanti.h"
#include "Tavolo.h"
#include "Interfaccia.h"
class InterfacciaWin;


class Risolutore {
public:
	Risolutore(Tavolo* t,InterfacciaWin*);
	bool mossa();
	bool getVincita(){return vincita;}
private:
	Tavolo* tavolo;
	int chiamateMaster; //tiene conto del numero di volte che io prendo una carta dal master
	int chiamateCiclo; //tiene conto del numero di volte che io chiamo mossa()
	GruppoDiCarte* gruppi[11];

	bool gruppi_pile();
	bool terra_gruppi();
	bool gruppi_gruppi();
	bool vincita;
	InterfacciaWin* interfaccia;
};

