#include "Menu.h"

using namespace std;

int main(void)
{
    Menu menu;

    printf("Bem vindo ao Calculatron\n");
    printf("O simulador em questao consiste em fornecer dados, baseados em um\n"
          " problema envolvendo um guindaste ao qual você nos ira fornecer tres\n"
          " das quatro variaveis necessarias.\n\n");

    menu.escolherOpcaoMenu();

    return 0;
}