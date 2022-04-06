    /******************************************************************************************
    Name:         Windows.h                                                                       
    Info:         Created by Alberto Zichittella (a.zichittella@gmail.com) on February,11 2012 
    Author site:  newbufferedwriter.blogspot.org                                               
    License:      GNU  General Public License (GPL)                                                 
    Description:  Classi per alcune API Win32
    ********************************************************************************************/
#pragma once
#include "costanti.h"
#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);


class WinClass
{
public:
    WinClass (WNDPROC wndProc, char const * className, HINSTANCE hInst);
    void Register ()
    {
        ::RegisterClass (&_class);
    }
private:
    WNDCLASS _class;
};

class WinMaker
{
public:
    WinMaker (): _hwnd (0) {}
    WinMaker (char const * caption, char const * className, HINSTANCE hInstance);
    void Show (int cmdShow)
    {
        ::ShowWindow (_hwnd, cmdShow);
        ::UpdateWindow (_hwnd);
    }
    HWND getHWND(){return _hwnd;}
protected:
    HWND _hwnd;
};

WinClass::WinClass (WNDPROC wndProc, char const * className, HINSTANCE hInst)
{
    _class.style = 0;
    _class.lpfnWndProc = wndProc;  // Window Procedure: mandatory
    _class.cbClsExtra = 0;
    _class.cbWndExtra = 0;
    _class.hInstance = hInst;           // owner of the class: mandatory
    _class.hIcon = 0;
    _class.hCursor = ::LoadCursor (0, IDC_ARROW); // optional
    _class.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1); // optional
    _class.lpszMenuName = 0;
    _class.lpszClassName = className;   // mandatory
}

WinMaker::WinMaker
    (char const * caption, char const * className, HINSTANCE hInstance)
{
    _hwnd = ::CreateWindow (
        className,              // name of a registered window class
        caption,                // window caption
        WS_OVERLAPPEDWINDOW,    // window style
        CW_USEDEFAULT,          // x position
        CW_USEDEFAULT,          // y position
        CW_USEDEFAULT,          // witdh
        CW_USEDEFAULT,          // height
        0,                      // handle to parent window
        0,                      // handle to menu
        hInstance,              // application instance
        0 );                    // window creation data
}

