    /******************************************************************************************
    Name:         main.cpp
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,2 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Punto di ingresse del programma su Linux
    ********************************************************************************************/

#include "include/Mazzo.h"
#include "include/Tavolo.h"
#include "include/Interfaccia.h"
#include <iostream>
#include <fstream>
using namespace std;

#ifdef LINUX_APP
int main() {
	ofstream out;
	out.open("log.html",(_Ios_Openmode)0);
	Mazzo mazzo;
	Tavolo tavolo(&mazzo);
	Interfaccia inter(300,&tavolo);
	inter.aggiungiRisolutore();
	inter.mossa();
	out << tavolo;
	out.close();
	int i;
	cin >> i;
}
#endif
