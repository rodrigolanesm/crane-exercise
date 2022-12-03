#pragma once

#define GRAVIDADE 9.81
#define PI 3.14159265

#include <string> 
#include <iostream>
#include <math.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

class Menu
{
public:
    float massaBloco, tamBracoFixo, tamBracoMovel, anguloBraco;
    float distA;
    float momentoA, momentoB;

    Menu();
    ~Menu();

    void exibeMenu();
    void escolherOpcaoMenu();

    void setMassa();
    void setBracoMovel();
    void setAngulo();
    void setMomentoA();

    void calculaMassa();
    void calculaBracoMovel();
    void calculaAngulo();
    void calculaMomentoA();

};