    /******************************************************************************************
    Name:         Mazzo.cpp
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,2 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Classe che descrive un generico mazzo di carte di 52 elementi
    ********************************************************************************************/
#include "include/Mazzo.h"
#include <ctime>
#include <cstdlib>

Mazzo::Mazzo():GruppoDiCarte(0,0) {
	nCarte = 52;
	for (int i=0;i<13;i++){
		carte[i] = new Carta(i+1,CUORI,i+1,0,0);   //"carte\\"+toString(i+1)+"c.bmp"
		carte[i+13] = new Carta(i+1,QUADRI,i+14,0,0); //"carte\\"+toString(i+1)+"q.bmp"
		carte[i+26] = new Carta(i+1,PICCHE,i+27,0,0); //"carte\\"+toString(i+1)+"p.bmp"
		carte[i+39] = new Carta(i+1,FIORI,i+40,0,0);  //"carte\\"+toString(i+1)+"f.bmp"
	}
	srand(time(NULL));
	int c;
	int d;
	Carta* app;
	for (int i=0;i<208;i++){
		c = rand() % 52;
		d = rand() % 52;
		app = carte[c];
		carte [c] = carte[d];
		carte [d] = app;
	}
}

void Mazzo::ordina() {
}

string Mazzo::toString(int i){
	switch(i){
	case 1:return "01";
	case 2:return "02";
	case 3:return "03";
	case 4:return "04";
	case 5:return "05";
	case 6:return "06";
	case 7:return "07";
	case 8:return "08";
	case 9:return "09";
	case 10:return "10";
	case 11:return "11";
	case 12:return "12";
	case 13:return "13";
	}
	return "";
}
