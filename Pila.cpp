    /******************************************************************************************
    Name:         Pila.cpp
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,3 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Classe che descrive un particolare mazzo del gioco Klondike
    ********************************************************************************************/
#include "include/Pila.h"



bool Pila::attacca(Carta* c) {
	if (c==NULL)
		return false;
	if ((nCarte==0)&&(c->getValore()==1)){
		carte[nCarte] = c;
		nCarte++;
		seme =c->getSeme();
		c->setXY(this->x,this->y);
		return true;
	}
	else if(nCarte>=1)
		if ((c->getValore()==this->vediCarta()->getValore()+1)&&(c->getSeme()==seme)){
			carte[nCarte] = c;
			nCarte++;
		    c->setXY(this->x,this->y);
			return true;
		}
	return false;
}

Seme Pila::getSeme() {
	return seme;
}

ostream& operator<<(ostream& o,Pila& p){
	/*
	if (p.vediCarta()==NULL)
		return o;
	o << *p.vediCarta();
	*/
	if (p.vediCarta()==NULL){
		o << "<img style=\"margin:10px;\" src=\"carte\\v.bmp\">";
		return o;
	}
	o << "<img style=\"margin:10px;\" src=\"" << p.vediCarta()->getResource() << "\">";
	return o;
}
