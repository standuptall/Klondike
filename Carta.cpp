    /******************************************************************************************
    Name:         Carta.cpp
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,2 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Classe che descrive una carta da gioco
    ********************************************************************************************/
#include "include/Carta.h"
#include <iostream>
using namespace std;

Carta::Carta(unsigned int v, Seme s,int r,int x,int y){
	seme = s;
	if ((v<=13)&&(v!=0))
		valore = v;
	else valore = 1;
	risorsa = r;
	this->x = x;
	this->y = y;
	grabbed = false;
}

Carta::Carta(Carta& c) {
	seme = c.getSeme();
	valore = c.getValore();
}

Seme Carta::getSeme() const{
	return seme;
}

Colore Carta::getColore() const {
	if ((seme==QUADRI)||(seme==CUORI))
		return ROSSO;
	else return NERO;
}

unsigned int Carta::getValore() const{
	return valore;
}

void Carta::stampa() const {
	cout << valore << " di " << getStringaSeme() << " " ;
}

string Carta::getStringaSeme() const {
	switch(seme) {
		case 0: return "Cuori";
		case 1: return "Quadri";
		case 2: return "Picche";
		case 3: return "Fiori";
	}
}

ostream& operator<<(ostream& o,Carta& c){
	o << c.valore << " di " << c.getStringaSeme() << " " ;
	return o;
}

int Carta::getResource() const {
	return risorsa;
}

void Carta::setXY(int xx, int yy) {
     x = xx;
     y = yy;
}
