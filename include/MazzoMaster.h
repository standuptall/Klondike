    /******************************************************************************************
    Name:         MazzoMaster.h                                                                       
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,3 2012 
    Author site:  newbufferedwriter.blogspot.org                                               
    License:      GNU  General Public License (GPL)                                                 
    Description:  Classe che descrive un particolare mazzo del gioco Klondike
    ********************************************************************************************/
#pragma once
#include "costanti.h"
#include "GruppoDiCarte.h"

class MazzoMaster : public GruppoDiCarte {
public:
    MazzoMaster(int x,int y):GruppoDiCarte(x,y){;}   
	Carta* daiCarta();
	void setTerra(GruppoDiCarte*);
private:
	GruppoDiCarte* terra;
};
