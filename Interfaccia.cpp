    /******************************************************************************************
    Name:         Interfaccia.cpp
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,11 2012
    Author site:  newbufferedwriter.blogspot.org
    License:      GNU  General Public License (GPL)
    Description:  Classe che implementa una interfaccia grafica
    ********************************************************************************************/
#include "include/costanti.h"
#include "include/Interfaccia.h"

#ifdef WINDOWS_APP
InterfacciaWin::InterfacciaWin(unsigned int size, Tavolo* t):weight(size),tavolo(t){
	risolutore = NULL;
	setRisolutore = false;
}


bool InterfacciaWin::mossa(){
	if (setRisolutore){
        if (risolutore->getVincita()){
           MessageBox(hwnd,"Il computer ha vinto.","Fine",MB_OK);
           PostQuitMessage(0);
        }
		return risolutore->mossa();
	}
	else return false;
}

void InterfacciaWin::aggiungiRisolutore(){
	setRisolutore = true;
	risolutore = new Risolutore(tavolo,this);
}

char** InterfacciaWin::clickOnMaster(){
       //tavolo->getMaster().daiCarta();
       return NULL;
}

void InterfacciaWin::transizione(int from,int to){
     /*
     PAINTSTRUCT ps;
     HDC hdc = BeginPaint(hwnd,&ps);
     if ((from==0)&&(to==1)){
               Carta* carta;
               carta = tavolo->getTerra()->vediCarta();
               Carta* sotto;
               sotto = tavolo->getMaster()->vediCarta();
               HBITMAP HBcarta,HBsotto;
               HDC Memcarta,Memsotto;
               HDC sfondo;
               HBcarta = (HBITMAP)LoadImage(NULL, carta->getResource().c_str(),IMAGE_BITMAP, 0, 0,LR_LOADFROMFILE);
               HBsotto = (HBITMAP)LoadImage(NULL, sotto->getResource().c_str(),IMAGE_BITMAP, 0, 0,LR_LOADFROMFILE);
               Memcarta = CreateCompatibleDC(hdc);
               Memsotto = CreateCompatibleDC(hdc);
               SelectObject(Memcarta,carta);
               SelectObject(Memsotto,sotto);
               BitBlt(hdc, 0, 0, CARD_WIDTH, CARD_HEIGHT, Memsotto, masterx, mastery, SRCCOPY); //disegno la carta di sotto
               int distanza = terrax - masterx;
               int step = distanza / 10;
               for (int i=0;i<10;i++){
                   if (i>0) BitBlt(hdc, 0, 0, CARD_WIDTH, CARD_HEIGHT, sfondo, masterx+(step*(i)), mastery, SRCCOPY); //ripristina sfondo
                   BitBlt(sfondo, 0, 0, CARD_WIDTH, CARD_HEIGHT, hdc, masterx+(step*(i+1)), mastery, SRCCOPY); //salva lo sfondo
                   BitBlt(hdc, 0, 0, CARD_WIDTH, CARD_HEIGHT, Memcarta, masterx+(step*(i+1)), mastery, SRCCOPY); //ci mette su la carta
                   Sleep(10);
               }
     }
     EndPaint(hwnd,&ps);
     */
}


void InterfacciaWin::aggiungiFinestra(HWND hw){
     hwnd = hw;
}
#endif

#ifdef LINUX_APP
InterfacciaLinux::InterfacciaLinux(unsigned int size, Tavolo* t):weight(size),tavolo(t){
	risolutore = NULL;
	setRisolutore = false;
}


bool InterfacciaLinux::mossa(){
	if (setRisolutore){
		return risolutore->mossa();
	}
	else return false;
}

void InterfacciaLinux::aggiungiRisolutore(){
	setRisolutore = true;
	risolutore = new Risolutore(tavolo);
}

char** InterfacciaLinux::clickOnMaster(){
       //tavolo->getMaster().daiCarta();
       return NULL;
}

void InterfacciaLinux::transizione(int from,int to){
}


#endif
