    /******************************************************************************************
    Name:         GruppoVolatile.cpp
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on March,2 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Classe che manipola un gruppo ordinato che non appartiene al tavolo
    ********************************************************************************************/
#include "include/GruppoVolatile.h"

GruppoVolatile::GruppoVolatile(GruppoOrdinato* g,int indice,HWND hw):GruppoOrdinato(NULL,0,0){
    hwnd = hw;
    hdc = BeginPaint(hwnd,&ps);
    origine = g;
    for (int i=0;i<indice;i++)
        this->getCarte()[i] = origine->getCarte()[i];
    this->indice = indice;
    for (int i=0;i<this->getNCarte();i++){
        //HBITMAP  = (HBITMAP)LoadImage()
        //HDC Memhdc = this->getCarte()[i]->
    }
}

GruppoVolatile::~GruppoVolatile(){
    EndPaint(hwnd,&ps);
    for (int i=0;i<indice;i++)
        origine->pop();
}
void GruppoVolatile::setX(UINT x){
    oldX = x;
}
void GruppoVolatile::setY(UINT y){
    oldY = y;
}
UINT GruppoVolatile::getOldX(){
    return oldX;
}
UINT GruppoVolatile::getOldY(){
    return oldY;
}
HDC GruppoVolatile::getHdc(){
    return hdc;
}
