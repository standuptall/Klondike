    /******************************************************************************************
    Name:         Carta.h
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,2 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Classe che descrive una carta da gioco
    ********************************************************************************************/
#pragma once
#include "costanti.h"
#include <string>
#include <iostream>
using namespace std;
enum Seme {
	CUORI,QUADRI,PICCHE,FIORI,
};
enum Colore {
	ROSSO,NERO,
};
class Carta {
friend ostream& operator<<(ostream&,Carta&);
public:
	Carta(unsigned int,Seme,int,int,int);
	Carta(Carta&);
	unsigned int getValore() const;
	Seme getSeme() const;
	Colore getColore() const;
	void stampa() const;
	int getResource() const;
	void setXY(int,int);
	int getX(){return x;}
	int getY(){return y;}
	bool isGrabbed(){return grabbed;}
	void setGrabbed(bool b){grabbed = b;}
private:
	unsigned int valore;
	Seme seme;
	int risorsa;
	int x,y;
	bool grabbed;
	std::string getStringaSeme() const;
};
