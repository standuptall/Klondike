#include <windows.h>
#include "include/Tavolo.h"
#include "include/Interfaccia.h"
#include "include/Mazzo.h"
#include "include/NullPointerException.h"
#include "include/Windows.h"
#define WINDOWS_APP
#include <sstream>
#include <stdio.h>
using namespace std;

typedef struct {
    int x;
    int y;
    HDC hdc;
}Sprite;

Sprite sprite;
/** Trasforma un numero in una sequenza di caratteri stile C
 * WARNING:alloca memoria e non la libera. TODO
 *
 * \param int c: il numero da trasformare in stringa
 * \return puntatore alla stringa
 *
 */

char* intToString(int c){
      std::stringstream ss;
      ss << c;
      size_t length = (size_t)ss.str().length();
      char* buf = new char[length+1];
      for (int i=0;i<length;i++)
          buf[i] = ss.str()[i];
      buf[length]='\0';
      return  buf;
}


/** Disegna tutte le carte del tavolo interrogando appunto "tavolo"
 *
 * \param HDC& hdc, l'handle per device context
 * \param HWND& hwnd, l'handle della finestra
 * \param Tavolo* tavolo, puntatore al tavolo con le carte
 * \return NULL
 *
 */
void disegna(HDC&,HWND&,Tavolo*);





/** Disegna una carta
 *
 * \param HWND& hwnd, l'handle della finestra
 * \param HDC& hdc, l'handle del Device Context
 * \param int x, int y, posizione della carta in pixel sullo schermo
 * \param int res, il numero della risorsa che individua la carta
 * \return
 *
 */
void disegnaCarta(HWND&,HDC&,int,int,int);





/***************************************** WinMain *******************************************/
Interfaccia* inter;
Tavolo* tavolo;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {
    //INIZIALIZZO SPRITE
    sprite.hdc=0;
    sprite.x = -1;
    sprite.y = -1;
    Mazzo* mazzo = new Mazzo();
    Tavolo* tavol = new Tavolo(mazzo);
    Interfaccia* interfaccia = new Interfaccia(300,tavol);
    interfaccia->aggiungiRisolutore();  //risolutore automatico
    tavolo = tavol;
    inter = interfaccia;
    WinClass wclass(WndProc,"Solitario",hInstance);
    wclass.Register();
    WinMaker win("Solitario","Solitario",hInstance);
    win.Show(SW_MAXIMIZE);
    /********************************************/
    /*           loop dei messaggi              */
    /********************************************/
    unsigned int status;
    MSG msg;
    while ((status = GetMessage(&msg, 0, 0, 0)) != 0)
    {
        if (status == -1)
            return -1;
        ::DispatchMessage (&msg);

    }

    return msg.wParam;
}



LRESULT CALLBACK WndProc
    (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_DESTROY:
            ::PostQuitMessage (0);
            return 0;

        case WM_LBUTTONDOWN:{
             inter->mossa();
             RECT rect;
             GetWindowRect(hwnd,&rect);
             InvalidateRect(hwnd,&rect,false);
             UpdateWindow(hwnd);
             return 0;
        }

        case WM_RBUTTONDOWN:{
             int xm = LOWORD(lParam);
             int ym = HIWORD(lParam);
             if((xm>g1x)&&
                (xm<g1x+CARD_WIDTH)&&
                (ym>g1y)&&
                (ym<g1y+CARD_HEIGHT)){
                    Carta* c = tavolo->getg1()->vediCarta();
                    if (!c)
                        return 0;
                    c->setGrabbed(true);
                    HDC hdc = GetDC(hwnd);
                    sprite.hdc = CreateCompatibleDC(NULL);
                    BitBlt(sprite.hdc,0,0,1024,768,hdc,0,0,SRCCOPY);
            }
            else if((xm>masterx)&&
                    (xm<masterx+CARD_WIDTH)&&
                    (ym>mastery)&&
                    (ym<mastery+CARD_HEIGHT)){
                 }
            else if((xm>p1x)&&
                    (xm<p1x+CARD_WIDTH)&&
                    (ym>p1y)&&
                    (ym<p1y+CARD_HEIGHT)){
                 }
            else if((xm>p2x)&&
                    (xm<p2x+CARD_WIDTH)&&
                    (ym>p2y)&&
                    (ym<p2y+CARD_HEIGHT)){
                 }
            else if((xm>p3x)&&
                    (xm<p3x+CARD_WIDTH)&&
                    (ym>p3y)&&
                    (ym<p3y+CARD_HEIGHT)){
                 }
            else if((xm>p4x)&&
                    (xm<p4x+CARD_WIDTH)&&
                    (ym>p4y)&&
                    (ym<p4y+CARD_HEIGHT)){
                 }
            else if((xm>g1x)&&
                    (xm<g1x+CARD_WIDTH)&&
                    (ym>g1y)&&
                    (ym<g1y+CARD_HEIGHT)){
                 }
            else if((xm>g2x)&&
                    (xm<g2x+CARD_WIDTH)&&
                    (ym>g2y)&&
                    (ym<g2y+CARD_HEIGHT)){
                 }
            else if((xm>g3x)&&
                    (xm<g3x+CARD_WIDTH)&&
                    (ym>g3y)&&
                    (ym<g3y+CARD_HEIGHT)){
                 }
            else if((xm>g4x)&&
                    (xm<g4x+CARD_WIDTH)&&
                    (ym>g4y)&&
                    (ym<g4y+CARD_HEIGHT)){
                 }
            else if((xm>g5x)&&
                    (xm<g5x+CARD_WIDTH)&&
                    (ym>g5y)&&
                    (ym<g5y+CARD_HEIGHT)){
                 }
            else if((xm>g6x)&&
                    (xm<g6x+CARD_WIDTH)&&
                    (ym>g6y)&&
                    (ym<g6y+CARD_HEIGHT)){
                 }
            else if((xm>g7x)&&
                    (xm<g7x+CARD_WIDTH)&&
                    (ym>g7y)&&
                    (ym<g7y+CARD_HEIGHT)){
                 }

                return 0;
        }
        case WM_RBUTTONUP:{
            Carta* c = tavolo->getg1()->vediCarta();
            if (!c)
                return 0;
            c->setGrabbed(false);
        }
        case WM_MOUSEMOVE:{
             int xm = LOWORD(lParam);
             int ym = HIWORD(lParam);

            Carta* c = tavolo->getg1()->vediCarta();
            if (c)
                if (c->isGrabbed())
                {
                    RECT rect;
                    GetWindowRect(hwnd,&rect);
                    InvalidateRect(hwnd,&rect,false);
                    PAINTSTRUCT ps;
                    HDC hdc;
                    HDC dcposizione;
                    /*CANCELLO ULTIMA POSIZIONE (cioè ci  stampo la parte memorizzata prima)*/
                    if ((sprite.x>=0)&&(sprite.y>=0)){
                        hdc = GetDC(hwnd);
                        dcposizione = sprite.hdc;
                        BitBlt(hdc,0,0,1024, 768,sprite.hdc,0,0,SRCCOPY);
                        //DeleteDC(dcposizione);
                    }
                    /*MEMORIZZO INFORMAZIONI SULLO SPRITE
                    hdc = GetDC(hwnd);
                    DeleteDC(sprite.hdc);
                    dcposizione=CreateCompatibleDC(hdc);
                    BitBlt(dcposizione,0,0,CARD_WIDTH, CARD_HEIGHT,hdc,xm,ym,SRCCOPY);
                    sprite.hdc = dcposizione;*/
                    sprite.x=xm;
                    sprite.y=ym;
                    /*FINE*/
                    disegnaCarta(hwnd,hdc, xm, ym,c->getResource());

                }
                return 0;
        }

        case WM_PAINT:

             PAINTSTRUCT ps;
             HDC hdc = BeginPaint(hwnd,&ps);
             Carta* c = tavolo->getg1()->vediCarta();
             if (!c->isGrabbed())
                disegna(hdc,hwnd,tavolo);
             EndPaint(hwnd,&ps);
             return 0;

    }
	// All the unprocessed messages go there, to be dealt in some default way

    return ::DefWindowProc (hwnd, message, wParam, lParam );
}




void disegna(HDC& hdc,HWND& hwnd,Tavolo* tavolo){
     HBRUSH sfondo = CreateSolidBrush(RGB(0,255,0));
     SelectObject(hdc,sfondo);
     RECT window;
     RECT rect;
     GetWindowRect(hwnd,&window);
     Rectangle(hdc,0,0,window.right,window.bottom);
     try{
         if (tavolo->getMaster()->vediCarta()!=NULL)
            disegnaCarta(hwnd,hdc,masterx,mastery,0);
         if (tavolo->getTerra()->vediCarta()!=NULL) disegnaCarta(hwnd,hdc,terrax,terray,tavolo->getTerra()->vediCarta()->getResource());

         if (tavolo->getp1()->vediCarta()!=NULL) disegnaCarta(hwnd,hdc,p1x,p1y,tavolo->getp1()->vediCarta()->getResource());
         if (tavolo->getp2()->vediCarta()!=NULL) disegnaCarta(hwnd,hdc,p2x,p2y,tavolo->getp2()->vediCarta()->getResource());
         if (tavolo->getp3()->vediCarta()!=NULL) disegnaCarta(hwnd,hdc,p3x,p3y,tavolo->getp3()->vediCarta()->getResource());
         if (tavolo->getp4()->vediCarta()!=NULL) disegnaCarta(hwnd,hdc,p4x,p4y,tavolo->getp4()->vediCarta()->getResource());

         if (tavolo->gets2()->vediCarta()!=NULL){
             disegnaCarta(hwnd,hdc,g2x,g2y,0);
             char* nc = intToString(tavolo->gets2()->getNCarte());
             TextOut(hdc,g2x,g2y-15,nc,1);
             delete[] nc;
         }
         if (tavolo->gets3()->vediCarta()!=NULL){
             disegnaCarta(hwnd,hdc,g3x,g3y,0);
             char* nc = intToString(tavolo->gets3()->getNCarte());
             TextOut(hdc,g3x,g3y-15,nc,1);
             delete[] nc;
         }
         if (tavolo->gets4()->vediCarta()!=NULL){
             disegnaCarta(hwnd,hdc,g4x,g4y,0);
             char* nc = intToString(tavolo->gets4()->getNCarte());
             TextOut(hdc,g4x,g4y-15,nc,1);
             delete[] nc;
         }
         if (tavolo->gets5()->vediCarta()!=NULL){
             disegnaCarta(hwnd,hdc,g5x,g5y,0);
             char* nc = intToString(tavolo->gets5()->getNCarte());
             TextOut(hdc,g5x,g5y-15,nc,1);
             delete[] nc;
         }
         if (tavolo->gets6()->vediCarta()!=NULL){
             disegnaCarta(hwnd,hdc,g6x,g6y,0);
             char* nc = intToString(tavolo->gets6()->getNCarte());
             TextOut(hdc,g6x,g6y-15,nc,1);
             delete[] nc;
         }
         if (tavolo->gets7()->vediCarta()!=NULL){
             disegnaCarta(hwnd,hdc,g7x,g7y,0);
             char* nc = intToString(tavolo->gets7()->getNCarte());
             TextOut(hdc,g7x,g7y-15,nc,1);
             delete[] nc;
         }

         if (tavolo->getg1()->vediCarta()!=NULL)
             for (int i=0;i<tavolo->getg1()->getNCarte();i++)
                 disegnaCarta(hwnd,hdc,g1x,g1y+(i*SPACING*4),tavolo->getg1()->getCarte()[i]->getResource());
         if (tavolo->getg2()->vediCarta()!=NULL)
            for (int i=0;i<tavolo->getg2()->getNCarte();i++)
                disegnaCarta(hwnd,hdc,g2x,g2y+(i*SPACING*4),tavolo->getg2()->getCarte()[i]->getResource());
         if (tavolo->getg3()->vediCarta()!=NULL)
            for (int i=0;i<tavolo->getg3()->getNCarte();i++)
                disegnaCarta(hwnd,hdc,g3x,g3y+(i*SPACING*4),tavolo->getg3()->getCarte()[i]->getResource());
         if (tavolo->getg4()->vediCarta()!=NULL)
            for (int i=0;i<tavolo->getg4()->getNCarte();i++)
                disegnaCarta(hwnd,hdc,g4x,g4y+(i*SPACING*4),tavolo->getg4()->getCarte()[i]->getResource());
         if (tavolo->getg5()->vediCarta()!=NULL)
            for (int i=0;i<tavolo->getg5()->getNCarte();i++)
                disegnaCarta(hwnd,hdc,g5x,g5y+(i*SPACING*4),tavolo->getg5()->getCarte()[i]->getResource());
         if (tavolo->getg6()->vediCarta()!=NULL)
            for (int i=0;i<tavolo->getg6()->getNCarte();i++)
                disegnaCarta(hwnd,hdc,g6x,g6y+(i*SPACING*4),tavolo->getg6()->getCarte()[i]->getResource());
         if (tavolo->getg7()->vediCarta()!=NULL)
            for (int i=0;i<tavolo->getg7()->getNCarte();i++)
                disegnaCarta(hwnd,hdc,g7x,g7y+(i*SPACING*4),tavolo->getg7()->getCarte()[i]->getResource());
         char* numeroCarte = intToString(tavolo->contaCarte());
         TextOut(hdc,1000,700,numeroCarte,2);
         delete[] numeroCarte;
     }
     catch(NullPointerException* e){
         MessageBox(hwnd,e->getMessage(),"ok",MB_OK);
     }

     DeleteObject(sfondo);
}

void disegnaCarta(HWND& hwnd,HDC& hdc,int x, int y,int res){
     HBITMAP carta;
     HDC MemDCcarta;
     char* resc = new char[2];
     /*
     resc[0]=res+48;
     resc[1]=0;
     /*/
     sprintf(resc,"%d",res);
     HRSRC hrsrc = FindResource(NULL,resc,MAKEINTRESOURCE(2));
     carta = (HBITMAP)LoadResource(NULL,hrsrc);
     HINSTANCE ghAppInst = (HINSTANCE)GetWindowLong(hwnd,GWL_HINSTANCE);
     carta =(HBITMAP) LoadImage(ghAppInst, MAKEINTRESOURCE(res) ,IMAGE_BITMAP, 0, 0,NULL );
     if (!carta)
        MessageBox(hwnd,"qualcosa è andato male","merda",MB_OK);
     MemDCcarta = CreateCompatibleDC(hdc);
     SelectObject(MemDCcarta,carta);
     //Rectangle(hdc,x,y,x+CARD_WIDTH, y+CARD_HEIGHT);
     BitBlt(hdc, x, y, x+CARD_WIDTH, y+CARD_HEIGHT, MemDCcarta, 0, 0, SRCCOPY);
     DeleteDC(MemDCcarta);
     DeleteObject(carta);
}
