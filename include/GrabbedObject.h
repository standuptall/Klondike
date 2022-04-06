#ifndef GRABBEDOBJECT_H_INCLUDED
#define GRABBEDOBJECT_H_INCLUDED
#include "GruppoVolatile.h"
#include <windows.h>
    /******************************************************************************************
    Name:         GrabbedObject.h
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on March,6 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Classe che aiuta a identificare le carte che il mouse sta muovendo
    ********************************************************************************************/
class GrabbedObject {
    public:
        GrabbedObject(UINT,UINT,GruppoVolatile*);
        void setX(UINT);
        void setY(UINT);
        UINT getOldX();
        UINT getOldY();
    private:
        UINT oldX,oldY;
        HDC hdc;
        GruppoVolatile* gruppoVolatile;
};

#endif // GRABBEDOBJECT_H_INCLUDED
