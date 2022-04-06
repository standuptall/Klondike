
    /******************************************************************************************
    Name:         GruppoVolatile.h
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on March,2 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Classe che manipola un gruppo ordinato che non appartiene al tavolo
    ********************************************************************************************/
#include "GruppoOrdinato.h"
#include "costanti.h"
#include <windows.h>

class GruppoVolatile : public GruppoOrdinato {
public:
    GruppoVolatile(GruppoOrdinato*,int,HWND);
    void setX(UINT);
    void setY(UINT);
    UINT getOldX();
    UINT getOldY();
    HDC getHdc();
    ~GruppoVolatile();
private:
    GruppoOrdinato* origine;
    int indice;
    UINT oldX,oldY;
    HDC hdc;
    HWND hwnd;
    PAINTSTRUCT ps;
};
