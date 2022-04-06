    /******************************************************************************************
    Name:         GruppoDiCarte.cpp
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,2 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Classe che descrive un gruppo generico di carte
    ********************************************************************************************/
#include "include/GruppoDiCarte.h"
using namespace std;
#include <sstream>
#include "include/NullPointerException.h"


GruppoDiCarte::GruppoDiCarte(int xx,int yy):x(xx),y(yy) {
	for (int i=0;i<MAX_CARTE;i++)
		carte[i] = NULL;
	nCarte = 0;
}

GruppoDiCarte::GruppoDiCarte(unsigned int n,int xx,int yy):x(xx),y(yy) {
	for (int i=0;i<MAX_CARTE;i++)
		carte[i] = NULL;
    if (n<MAX_CARTE)
		nCarte = n;
	else nCarte = MAX_CARTE;

}

void GruppoDiCarte::mescola() {
}

void GruppoDiCarte::ordina() {
}

void GruppoDiCarte::stampa() {
	for (unsigned int i=0;i<nCarte;i++)
		carte[i]->stampa();
}

Carta* GruppoDiCarte::pop(){
	if (nCarte>0)
		nCarte--;
	else return NULL;
	Carta* c = carte[nCarte];
	carte[nCarte] = NULL;
	return c;
}

void GruppoDiCarte::push(Carta* c){
	carte[nCarte] = c;
	nCarte++;
}

Carta* GruppoDiCarte::vediCarta() {
	if (nCarte==0){
        //throw (new NullPointerException("Il gruppo non contiene carte"));
		return NULL;
    }
	return carte[nCarte-1];
}

bool GruppoDiCarte::attacca(Carta *){
	return false;
}

void GruppoDiCarte::reverse() {
	/*
	if (nCarte<2)
		return;
	Carta* cartecopie[MAX_CARTE];
	for (unsigned int i=0;i<nCarte;i++)
		cartecopie[i] = carte[nCarte-1-i];
	carte = cartecopie;
	*/
}

ostream& operator<<(ostream& o, GruppoDiCarte& g) {
	o << "<div>";
	int n = g.getNCarte();
	if (n==0)
		return o;
	std::stringstream ss;
	if (n==1)
		o << "<img src=\"carte\\b.bmp\" style=\"margin:10px;\">";
	else
		o << "<img src=\"carte\\b.bmp\" style=\"position:absolute;margin:10px;\">";
	for (int i=1;i<n;i++){
		ss.str("");
		ss << i*20;
		//if (i==n-1){
		//	o << "<img src=\"carte\\b.bmp\" style=\"margin:10px;margin-top:"+ss.str()+"px;\">";
		//	break;
		//}
		o << "<img src=\"carte\\b.bmp\" style=\"position:absolute;margin:10px;margin-top:"+ss.str()+"px;\">";
	}
	return o;
}
