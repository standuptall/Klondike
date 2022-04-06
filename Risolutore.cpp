    /******************************************************************************************
    Name:         Risolutore.cpp
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,3 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Classe che simula il comportamento di un giocatore di Klondike
    ********************************************************************************************/
#include "include/Risolutore.h"
#include "include/NullPointerException.h"

Risolutore::Risolutore(Tavolo* t,Interfaccia* inter):tavolo(t),interfaccia(inter) {
	chiamateMaster = 0;
	chiamateCiclo = 0;
	gruppi[0] = tavolo->getp1();
	gruppi[1] = tavolo->getp2();
	gruppi[2] = tavolo->getp3();
	gruppi[3] = tavolo->getp4();

	gruppi[4] = tavolo->getg1();
	gruppi[5] = tavolo->getg2();
	gruppi[6] = tavolo->getg3();
	gruppi[7] = tavolo->getg4();
	gruppi[8] = tavolo->getg5();
	gruppi[9] = tavolo->getg6();
	gruppi[10] = tavolo->getg7();
	vincita = false;
}
bool Risolutore::mossa(){
     if ((tavolo->getp1()->getNCarte()==13)&&
         (tavolo->getp2()->getNCarte()==13)&&
         (tavolo->getp3()->getNCarte()==13)&&
         (tavolo->getp4()->getNCarte()==13)){
         vincita = true;
         return true;
     }
	tavolo->checkGruppiOrdinati();
	bool result = false;
    chiamateCiclo++;
	/*
	if (chiamateCiclo>104) {
		if (tavolo->getMaster()->daiCarta()!=NULL){
			chiamateMaster++;
			if (chiamateMaster>tavolo->getMaster()->getNCarte()*2)
				return false;
		}
	}
    */
    //Controlla se ce ne sono da mettere nelle pile

	result = this->gruppi_pile();
	if (result)
		return true;
    //    Controlla se c'è da fare qualche operazione nei gruppi ordinati

	result = gruppi_gruppi();
	if (result)
		return true;


	//Controllo carta di terra

	result = terra_gruppi();
	if (result)
		return true;


	result = this->gruppi_pile();
	if (result)
		return true;

	result = terra_gruppi();
	if (result)
		return true;

	//prova a scoprire la carta dal master, visto che non è stata possibile alcuna mossa
	if (tavolo->getMaster()->daiCarta()!=NULL){
		chiamateMaster++;
		if (chiamateMaster>tavolo->getMaster()->getNCarte()*2)
			return false;
		return true;
	}
	return false;
}

bool Risolutore::gruppi_pile(){
    try{
    	bool result = false;
    	for (int i=4;i<11;i++){
    		Carta* c = gruppi[i]->vediCarta();
    		//if (c==NULL) break;
    		result = gruppi[0]->attacca(c);
    		if (result) {
    			gruppi[i]->pop();
    			chiamateMaster = 0;
    			return true;
    		}
    		result = gruppi[1]->attacca(c);
    		if (result) {
    			gruppi[i]->pop();
    			chiamateMaster = 0;
    			return true;
    		}
    		result = gruppi[2]->attacca(c);
    		if (result) {
    			gruppi[i]->pop();
    			chiamateMaster = 0;
    			return true;
    		}
    		result = gruppi[3]->attacca(c);
    		if (result) {
    			gruppi[i]->pop();
    			chiamateMaster = 0;
    			return true;
    		}
    	}
     }
     catch (NullPointerException* e){
           return false;
     }
	return false;
}
bool Risolutore::terra_gruppi(){
     try{
    	bool result = false;
    	Carta* cartaTerra = tavolo->getTerra()->vediCarta();

    	for (int i=0;i<11;i++){
    		result = gruppi[i]->attacca(cartaTerra); //PRIMA CONTROLLA LA CARTA DI TERRA
    		if (result) {
    			tavolo->getTerra()->pop();
    			chiamateMaster = 0;
    			return true;
    		}
    	}
     }
     catch(NullPointerException* e){
     }

	return false;
}
bool Risolutore::gruppi_gruppi(){
    try{
    	bool result = false;
    	for (int i=4;i<11;i++){
    		Carta* c = gruppi[i]->getPrimo();
    		if (i!=4){
    			result = gruppi[4]->attaccaGruppo((GruppoOrdinato*)gruppi[i]);
    			if (result){
    				chiamateMaster = 0;
    				return true;
    			}
    		}
    		if (i!=5){
    			result = gruppi[5]->attaccaGruppo((GruppoOrdinato*)gruppi[i]);
    			if (result){
    				chiamateMaster = 0;
    				return true;
    			}
    		}
    		if (i!=6){
    			result = gruppi[6]->attaccaGruppo((GruppoOrdinato*)gruppi[i]);
    			if (result){
    				chiamateMaster = 0;
    				return true;
    			}
    		}
    		if (i!=7){
    			result = gruppi[7]->attaccaGruppo((GruppoOrdinato*)gruppi[i]);
    			if (result){
    				chiamateMaster = 0;
    				return true;
    			}
    		}
    		if (i!=8){
    			result = gruppi[8]->attaccaGruppo((GruppoOrdinato*)gruppi[i]);
    			if (result){
    				chiamateMaster = 0;
    				return true;
    			}
    		}
    		if (i!=9){
    			result = gruppi[9]->attaccaGruppo((GruppoOrdinato*)gruppi[i]);
    			if (result){
    				chiamateMaster = 0;
    				return true;
    			}
    		}
    		if (i!=10){
    			result = gruppi[10]->attaccaGruppo((GruppoOrdinato*)gruppi[i]);
    			if (result){
    				chiamateMaster = 0;
    				return true;
    			}
    		}
    	}
     }
     catch(NullPointerException* e){

     }

	return false;
}
