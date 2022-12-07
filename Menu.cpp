#include "Menu.h"
 
Menu::Menu()
{
    distA = 1.5;
    tamBracoFixo = 9; 
    tamBracoMovel = 0; 
    anguloBraco = 0;
    massaBloco = 0;
    momentoA = 0; 
    momentoB = 0;
}

Menu::~Menu()
{

}

void Menu::exibeMenu()
{
    cout << "Digite a operacao que deseja realizar:" << endl;
    cout << "\t [1] Selecionar valor para massa do bloco (em kg)" << endl
         << "\t [2] Selecionar valor para tamanho do braco movel (em m)" << endl
         << "\t [3] Selecionar valor para angulo do braco (em graus)" << endl
         << "\t [4] Selecionar valor para o momento em A (em N*m)" << endl
         << "\t [5] Calcular momento no ponto A" << endl
         << "\t [6] Calcular a massa do bloco, dados momento em A, tamanho movel do braco e angulo do braco" << endl
         << "\t [7] Calcular o tamanho movel do braco, dados momento em A, massa do bloco e angulo do braco" << endl
         << "\t [8] Calcular o angulo do braco, dados momento em A, tamanho movel do braco e massa do bloco" << endl
         << "\t [0] Sair";
}

void Menu::escolherOpcaoMenu()
{
    int opcao;
    do
    {   
        exibeMenu();

        cout << endl << "Selecione uma opcao: ";
        cin >> opcao;
        cin.ignore();
        system(CLEAR);
        
        switch (opcao)
        {
        case 1:
            setMassa();
            break;
        case 2:
            setBracoMovel();
            break;
        case 3:
            setAngulo();
            break;
        case 4:
            setMomentoA();
            break;
        case 5:
            calculaMomentoA();
            break;        
        case 6:
            calculaMassa();
            break;
        case 7:
            calculaBracoMovel();
            break;
        case 8:
            calculaAngulo();
            break;
        case 0:
            cout << "Saindo...";
            break;
        }
    }
    while (opcao);
}

void Menu::setMassa()
{
    cout << "Digite o valor da massa: ";
    cin >> massaBloco;
}

void Menu::setBracoMovel()
{
    cout << "Digite o valor do tamanho do braco movel: ";
    cin >> tamBracoMovel;
}

void Menu::setAngulo()
{
    cout << "Digite o valor do angulo do braco: ";
    cin >> anguloBraco;
}

void Menu::setMomentoA()
{
    cout << "Digite o valor do momento em A: ";
    cin >> momentoA;
}

void Menu::calculaAngulo()
{
    cout << "Considerando os seguintes valores:" << endl
         << "Massa: " << massaBloco  << " kg" << endl
         << "Tamanho do braco movel: " << tamBracoMovel << " m" << endl
         //<< "Angulo: " << anguloBraco << " graus" << endl
         << "Momento em A: " << momentoA << " N*m" << endl << endl;
         
    anguloBraco = acos(momentoA/((tamBracoFixo-distA+tamBracoMovel)*(massaBloco*GRAVIDADE))) * 180/PI;

    cout << endl;
    cout << "o valor do angulo do braco em relacao a horizontal eh: " << anguloBraco << " graus" <<endl;
}

void Menu::calculaMomentoA()
{
    cout << "Considerando os seguintes valores:" << endl
         << "Massa: " << massaBloco  << " kg" << endl
         << "Tamanho do braco movel: " << tamBracoMovel << " m" << endl
         << "Angulo: " << anguloBraco << " graus" << endl;
         //<< "Momento em A: " << massaBloco << " N*m" << endl << endl;

    momentoA = (tamBracoFixo-distA+tamBracoMovel)*(massaBloco*GRAVIDADE)*cos(anguloBraco*PI/180);
    
    cout << endl;
    cout << "o valor do momento em A eh: " << momentoA << " N*m" <<endl;
}

void Menu::calculaBracoMovel()
{
    cout << "Considerando os seguintes valores:" << endl
         << "Massa: " << massaBloco  << " kg" << endl
         //<< "Tamanho do braco movel: " << tamBracoMovel << " m" << endl
         << "Angulo: " << anguloBraco << " graus" << endl
         << "Momento em A: " << momentoA << " N*m" << endl << endl;

    tamBracoMovel = momentoA/((massaBloco*GRAVIDADE)*cos(anguloBraco*PI/180)) - (tamBracoFixo-distA);

    cout << endl;
    cout << "o valor do tamanho do braco eh: " << tamBracoMovel << " m" <<endl;
}

void Menu::calculaMassa()
{
    cout << "Considerando os seguintes valores:" << endl
         //<< "Massa: " << massaBloco  << " kg" << endl
         << "Tamanho do braco movel: " << tamBracoMovel << " m" << endl
         << "Angulo: " << anguloBraco << " graus" << endl
         << "Momento em A: " << momentoA << " N*m" << endl << endl;

    massaBloco = momentoA/((tamBracoFixo-distA+tamBracoMovel)*cos(anguloBraco*PI/180)*GRAVIDADE);
    
    cout << endl;
    cout << "o valor do massa do bloco eh: " << massaBloco << " kg" <<endl;
}
