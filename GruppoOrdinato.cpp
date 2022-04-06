    /******************************************************************************************
    Name:         GruppoOrdinato.cpp
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,3 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Classe che descrive un gruppo di carte ordinato in maniera decrescente e a colori alterni
    ********************************************************************************************/
#include "include/GruppoOrdinato.h"
using namespace std;
#include <sstream>

GruppoOrdinato::GruppoOrdinato(GruppoDiCarte* ss,int x,int y):GruppoDiCarte(x,y),s(ss){
	attaccaPrimaVolta = false;
}

bool GruppoOrdinato::attacca(Carta* c) {
	if (c==NULL)
		return false;
	if (nCarte==0){
		if (attaccaPrimaVolta){
			if (c->getValore()!=13)
				return false;
		}
		carte[0] = c;
		nCarte++;
		attaccaPrimaVolta = true;
		return true;
	}
	if (c->getValore()==this->vediCarta()->getValore()-1)
		if (c->getColore()!=this->vediCarta()->getColore()){
			carte[nCarte] = c;
			nCarte++;
			attaccaPrimaVolta = true;
			c->setXY(this->vediCarta()->getX(),this->vediCarta()->getY());
			return true;
		}
		if ((c->getValore()==13)&&(nCarte==0)){
			carte[nCarte] = c;
			nCarte++;
			attaccaPrimaVolta = true;
			c->setXY(this->x,this->y);
			return true;
		}
	attaccaPrimaVolta = true;
	return false;
}

void GruppoOrdinato::push(Carta*) {
}



Carta* GruppoOrdinato::getPrimo() {
	if (nCarte==0)
		return NULL;
	return carte[0];
}

void GruppoOrdinato::setAttaccaPrimaVolta() {
	attaccaPrimaVolta = false;
}

bool GruppoOrdinato::attaccaGruppo(GruppoOrdinato *g) {
	if (g==NULL){
		return false;
	}
	if (g->getNCarte()==0)
		return false;
	if (this->vediCarta()==NULL){
		if 	(g->getPrimo()->getValore()==13){
            if (g->getS()!=NULL)
               if  (g->getS()->getNCarte()>0){
        			int n = g->getNCarte();
                    for (int i=0;i<g->getNCarte();i++){
        				this->attacca(g->getCarte()[i]);
        				g->getCarte()[i]->setXY(this->x,this->y+(SPACING*i*4));
                    }
        			for (int i=0;i<n;i++)
        				g->pop();
        			return true;
	            }
	            return false;
        }
        else return false;
	}

	if (g->getPrimo()->getValore()+1==this->vediCarta()->getValore())
		if (g->getPrimo()->getColore()!=this->vediCarta()->getColore()){
			int n = g->getNCarte();
			int posy = this->vediCarta()->getY()+(SPACING*4);
            for (int i=0;i<g->getNCarte();i++){
				this->attacca(g->getCarte()[i]);
				g->getCarte()[i]->setXY(this->x,posy+(i*SPACING*4));
            }

			for (int i=0;i<n;i++)
				g->pop();
			return true;
		}
	return false;
}

ostream& operator<<(ostream& o, GruppoOrdinato& g) {
     /*
	int n = g.getNCarte();
	o << "<div>";
	if (n==0){
		o << "<img style=\"margin:10px;\" src=\"carte\\v.bmp\">";
		o << "</div>";
		return o;
	}
	std::stringstream ss;
	if (n==1)
		o << "<img src=\""+g.carte[0]->getResource()+"\" style=\"margin:10px;\">";
	else
		o << "<img src=\""+g.carte[0]->getResource()+"\" style=\"position:absolute;margin:10px;\">";
	for (int i=1;i<n;i++){
		ss.str("");
		ss << i*40;
		if (i==n-1){
			o << "<img src=\""+g.carte[i]->getResource()+"\" style=\"margin:10px;margin-top:"+ss.str()+"px;\">";
			o << "</div>";
			break;
		}
		o << "<img src=\""+g.carte[i]->getResource()+"\" style=\"position:absolute;margin:10px;margin-top:"+ss.str()+"px;\">";
	}
	o << "</div>";
	*/
	return o;
}

