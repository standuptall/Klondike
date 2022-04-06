    /******************************************************************************************
    Name:         MazzoMaster.cpp
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,3 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Classe che descrive un particolare mazzo del gioco Klondike
    ********************************************************************************************/
#include "include/MazzoMaster.h"

Carta* MazzoMaster::daiCarta() {
	Carta* c = this->pop();
	if (c==NULL){
        unsigned int c = terra->getNCarte();
		for (unsigned int i=0;i<c;i++){
			this->push(terra->pop());
			this->vediCarta()->setXY(this->x,this->y);
        }

		terra->push(this->pop());
		terra->vediCarta()->setXY(terrax,terray);
		return terra->vediCarta();
	}
	terra->push(c);
	terra->vediCarta()->setXY(terrax,terray);
	return c;
}

void MazzoMaster::setTerra(GruppoDiCarte * g){
	terra = g;
}
