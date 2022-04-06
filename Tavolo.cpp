    /******************************************************************************************
    Name:         Tavolo.cpp
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,2 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Classe che descrive il tavolo di gioco del Klondike
    ********************************************************************************************/
#include "include/Tavolo.h"
#include <iostream>
using namespace std;

Tavolo::Tavolo(Mazzo* m) {
    master = new MazzoMaster(masterx,mastery);
    terra = new GruppoDiCarte(terrax,terray);



    s2 = new GruppoDiCarte(g2x,g2y);
    s3 = new GruppoDiCarte(g3x,g3y);
    s4 = new GruppoDiCarte(g4x,g4y);
    s5 = new GruppoDiCarte(g5x,g5y);
    s6 = new GruppoDiCarte(g6x,g6y);
    s7 = new GruppoDiCarte(g7x,g7y);

    g1 = new GruppoOrdinato(NULL,g1x,g1y);
    g2 = new GruppoOrdinato(s2,g2x,g2y);
    g3 = new GruppoOrdinato(s3,g3x,g3y);
    g4 = new GruppoOrdinato(s4,g4x,g4y);
    g5 = new GruppoOrdinato(s5,g5x,g5y);
    g6 = new GruppoOrdinato(s6,g6x,g6y);
    g7 = new GruppoOrdinato(s7,g7x,g7y);

    p1 = new Pila(p1x,p1y);
    p2 = new Pila(p2x,p2y);
    p3 = new Pila(p3x,p3y);
    p4 = new Pila(p4x,p4y);

	master->setTerra(terra);
	int i;
	for (i=0;i<24;i++){
		master->push(m->pop());
		master->vediCarta()->setXY(masterx,mastery);
    }
	for ( ; i<25;i++){
		g1->attacca(m->pop());
		g1->vediCarta()->setXY(g1x,g1y);
    }
	for (;i<26;i++){
		s2->push(m->pop());
		s2->vediCarta()->setXY(g2x,g2y);
    }
	for (;i<27;i++){
		g2->attacca(m->pop());
		g2->vediCarta()->setXY(g2x,g2y);
    }
	for(;i<29;i++){
		s3->push(m->pop());
		s3->vediCarta()->setXY(g3x,g3y);
    }
	for(;i<30;i++){
		g3->attacca(m->pop());
		g3->vediCarta()->setXY(g3x,g3y);
    }
	for(;i<33;i++){
		s4->push(m->pop());
		s4->vediCarta()->setXY(g4x,g4y);
    }
	for(;i<34;i++){
		g4->attacca(m->pop());
		g4->vediCarta()->setXY(g4x,g4y);
    }
	for(;i<38;i++){
		s5->push(m->pop());
		s5->vediCarta()->setXY(g5x,g5y);
    }
	for (;i<39;i++){
		g5->attacca(m->pop());
		g5->vediCarta()->setXY(g5x,g5y);
    }
	for (;i<44;i++){
		s6->push(m->pop());
		s6->vediCarta()->setXY(g6x,g6y);
    }
	for (;i<45;i++){
		g6->attacca(m->pop());
		g6->vediCarta()->setXY(g6x,g6y);
    }
	for (;i<51;i++){
		s7->push(m->pop());
		s7->vediCarta()->setXY(g7x,g7y);
    }
	for (;i<52;i++){
		g7->attacca(m->pop());
		g7->vediCarta()->setXY(g7x,g7y);
    }
}

void Tavolo::info() {
	cout << "master: " ; master->stampa();cout << endl;
	cout << "terra: " ; terra->stampa(); cout << endl;
	cout << "Pila 1: "; p1->stampa();cout << endl;
	cout << "Pila 2: "; p2->stampa();cout << endl;
	cout << "Pila 3: "; p3->stampa();cout << endl;
	cout << "Pila 4: "; p4->stampa();cout << endl;

	//cout << "s1: " ; s1.stampa();cout << endl;
	//cout << "s2: " ; s2.stampa();cout << endl;
	//cout << "s3: " ; s3.stampa();cout << endl;
	//cout << "s4: " ; s4.stampa();cout << endl;
	//cout << "s5: " ; s5.stampa();cout << endl;
	//cout << "s6: " ; s6.stampa();cout << endl;
	//cout << "s7: " ; s7.stampa();cout << endl;
	cout << "g1: " ; g1->stampa();cout << endl;
	cout << "g2: " ; g2->stampa();cout << endl;
	cout << "g3: " ; g3->stampa();cout << endl;
	cout << "g4: " ; g4->stampa();cout << endl;
	cout << "g5: " ; g5->stampa();cout << endl;
	cout << "g6: " ; g6->stampa();cout << endl;
	cout << "g7: " ; g7->stampa();cout << endl;
}

void Tavolo::checkGruppiOrdinati() {
	if (g2->getNCarte()==0)
	   if (s2->vediCarta()!=NULL){
	      g2->setAttaccaPrimaVolta();
          g2->attacca(s2->pop());
       }
    if (g3->getNCarte()==0)
	   if (s3->vediCarta()!=NULL){
          g3->setAttaccaPrimaVolta();
	      g3->attacca(s3->pop());
        }
    if (g4->getNCarte()==0)
	   if (s4->vediCarta()!=NULL){
          g4->setAttaccaPrimaVolta();
	      g4->attacca(s4->pop());
       }
    if (g5->getNCarte()==0)
	   if (s5->vediCarta()!=NULL){
          g5->setAttaccaPrimaVolta();
	      g5->attacca(s5->pop());
       }
    if (g6->getNCarte()==0)
	   if (s6->vediCarta()!=NULL){
          g6->setAttaccaPrimaVolta();
	      g6->attacca(s6->pop());
       }
    if (g7->getNCarte()==0)
	   if (s7->vediCarta()!=NULL){
          g7->setAttaccaPrimaVolta();
	      g7->attacca(s7->pop());
       }
}

void Tavolo::scopriCarta() {
	if (g2->getNCarte()==0){
		g2->setAttaccaPrimaVolta();
		g2->attacca(s2->pop());
	}
	if (g3->getNCarte()==0){
		g3->setAttaccaPrimaVolta();
		g3->attacca(s3->pop());
	}
	if (g4->getNCarte()==0){
		g4->setAttaccaPrimaVolta();
		g4->attacca(s4->pop());
	}
	if (g5->getNCarte()==0){
		g5->setAttaccaPrimaVolta();
		g5->attacca(s5->pop());
	}
	if (g6->getNCarte()==0){
		g6->setAttaccaPrimaVolta();
		g6->attacca(s6->pop());
	}
	if (g7->getNCarte()==0){
		g7->setAttaccaPrimaVolta();
		g7->attacca(s7->pop());
	}
}

unsigned int Tavolo::contaCarte() {
	int c = 0;
	c += master->getNCarte();
	c += terra->getNCarte();
	c += p1->getNCarte();
	c += p2->getNCarte();
	c += p3->getNCarte();
	c += p4->getNCarte();
	c += s2->getNCarte();
	c += s3->getNCarte();
	c += s4->getNCarte();
	c += s5->getNCarte();
	c += s6->getNCarte();
	c += s7->getNCarte();
	c += g1->getNCarte();
	c += g2->getNCarte();
	c += g3->getNCarte();
	c += g4->getNCarte();
	c += g5->getNCarte();
	c += g6->getNCarte();
	c += g7->getNCarte();
	return c;
}

ostream& operator<<(ostream& o, Tavolo& t){
    /*
	o << "<HTML><BODY>";
	o << "<img src=\"" << ((t.master->vediCarta()!=NULL) ? t.master->vediCarta()->getResource() : "carte\\v.bmp") << "\" style=\"margin:10px;\">";
	o << "<img src=\"" << ((t.terra->vediCarta()!=NULL) ? t.terra->vediCarta()->getResource() : "carte\\v.bmp") << "\" style=\"margin:10px;\">";

	o << t.p1;
	o << t.p2;
	o << t.p3;
	o << t.p4;
	/*
	o << "<img src=\"" << ((t.p1.vediCarta()!=NULL) ? t.p1.vediCarta()->getResource() : "carte\\v.bmp") << "\" style=\"margin:10px;margin-left:200px;\">";
	o << "<img src=\"" << ((t.p2.vediCarta()!=NULL) ? t.p2.vediCarta()->getResource() : "carte\\v.bmp")  << "\" style=\"margin:10px;\">";
	o << "<img src=\"" << ((t.p3.vediCarta()!=NULL) ? t.p3.vediCarta()->getResource() : "carte\\v.bmp")  << "\" style=\"margin:10px;\">";
	o << "<img src=\"" << ((t.p4.vediCarta()!=NULL) ? t.p4.vediCarta()->getResource() : "carte\\v.bmp")  << "\" style=\"margin:10px;\">";

	o << "<br><br>";

	o << t.g1;
	o << t.g2;
	o << t.g3;
	o << t.g4;
	o << t.g5;
	o << t.g6;
	//o << t.s7;
	o << t.g7;

	/*
	o << "<img src=\"" << ((t.g1.vediCarta()!=NULL) ? t.g1.vediCarta()->getResource() : "carte\\v.bmp")  << "\" style=\"margin:10px;\">";
	o << "<img src=\"" << ((t.g2.vediCarta()!=NULL) ? t.g2.vediCarta()->getResource() : "carte\\v.bmp")  << "\" style=\"margin:10px;\">";
	o << "<img src=\"" << ((t.g3.vediCarta()!=NULL) ? t.g3.vediCarta()->getResource() : "carte\\v.bmp")  << "\" style=\"margin:10px;\">";
	o << "<img src=\"" << ((t.g4.vediCarta()!=NULL) ? t.g4.vediCarta()->getResource() : "carte\\v.bmp")  << "\" style=\"margin:10px;\">";
	o << "<img src=\"" << ((t.g5.vediCarta()!=NULL) ? t.g5.vediCarta()->getResource() : "carte\\v.bmp")  << "\" style=\"margin:10px;\">";
	o << "<img src=\"" << ((t.g6.vediCarta()!=NULL) ? t.g6.vediCarta()->getResource() : "carte\\v.bmp")  << "\" style=\"margin:10px;\">";
	o << "<img src=\"" << ((t.g7.vediCarta()!=NULL) ? t.g7.vediCarta()->getResource() : "carte\\v.bmp")  << "\" style=\"margin:10px;\">";

	o << "</BODY></HTML>";
	*/
	return o;
}
