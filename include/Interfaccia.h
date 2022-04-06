    /******************************************************************************************
    Name:         Interfaccia.h                                                                       
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,11 2012 
    Author site:  newbufferedwriter.blogspot.org                                               
    License:      GNU  General Public License (GPL)                                                 
    Description:  Classe che implementa una interfaccia grafica
    ********************************************************************************************/
#pragma once
#include "costanti.h"
#include "Tavolo.h"
#include "Risolutore.h"
class Risolutore;

#ifdef WINDOWS_APP
#include <windows.h>
class InterfacciaWin {
public:
	InterfacciaWin(unsigned int,Tavolo*);
	void aggiungiRisolutore();
	bool mossa();
	char** clickOnMaster();
	void transizione(int,int);
	void aggiungiFinestra(HWND);
private:
	Tavolo* tavolo;
	Risolutore* risolutore;
	bool setRisolutore;
	unsigned int weight;
	
    HWND hwnd;
};
#define Interfaccia InterfacciaWin
#endif

#ifdef LINUX_APP
class InterfacciaLinux {
public:
	InterfacciaLinux(unsigned int,Tavolo*);
	void aggiungiRisolutore();
	bool mossa();
	char** clickOnMaster();
	void transizione(int,int);
private:
	Tavolo* tavolo;
	Risolutore* risolutore;
	bool setRisolutore;
	unsigned int weight;
};
#define Interfaccia InterfacciaLinux
#endif
