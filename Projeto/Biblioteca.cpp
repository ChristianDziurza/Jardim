#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
int dia = 0;

typedef struct{
    char nome[30];
    double agua;
    unsigned int vida;
    string desenvolvimento;
    char reino[30];
    int indicativo;
    bool flag;
    int idade;
}Planta;

typedef struct{
    Planta planta;
    int flag;
}Pote;


void tempo();
void acao(int qTempo);
void mudPlanta();
void CriarPlanta(int i);
void nulificaPlanta(int i);
void Merge(int inicio, int fim);
void Intercala(int inicio, int meio, int fim);
void Ordenacao(char escolha);
void impPlanta(int l);
void gotoxy(int x, int y);
int qualPlanta();
bool terminaDia();
Planta* biblioteca();
string nomePlanta();
string definirReino();
char Escolha();
void Regar();

int main(){
    srand(time(NULL));
    Planta *planta = biblioteca();
    for(int i=0; i<5;i++){
        CriarPlanta(i);
    }
    tempo();
    return 0;
}

void tempo(){
    char es = 'h';
    while(es != 's'){
        for(int i=0;i<5;i++)
            impPlanta(i);
        es = Escolha();
        if(es == 'r')
            Regar();
        if(es == 'a' || es == 'v' || es == 'i')
            Ordenacao(es);
        system("cls");
    }

}

void acao(int adTempo){
    static int qTempo=0;
    qTempo += adTempo;
    if(qTempo >=24){
        if(terminaDia()){
            mudPlanta();
            qTempo=0;
        }
        else{
            qTempo -= adTempo;
        }
    }

}

void mudPlanta(){
    Planta *mudanca=biblioteca();
    int atacada = rand()%10;
    dia++;
    for(int i=0;i<5;i++){
        if(mudanca[i].desenvolvimento != "morta"){
            mudanca[i].idade++;
            mudanca[i].agua-=rand() %45;
            if(mudanca[i].idade>3 && mudanca[i].idade<=7){
                mudanca[i].desenvolvimento="muda";
            }
            if(mudanca[i].idade>7){
                mudanca[i].desenvolvimento="adulto";
            }
            if(atacada >= 6)
                mudanca[i].vida -= rand()%3;
            if(mudanca[i].vida <= 0 || mudanca[i].agua <= 0)
                mudanca[i].desenvolvimento = "morta";
        }
    }
}

bool terminaDia(){
    char td='l';
    cout << "Quer terminar o dia?"<< endl << "(s)= sim    (n)=nao"<< endl;
    while (td!='s'&& td!='n'){
       cin >> td; 
    }
    if(td == 's'){
        return true;
    }else return false;
}

Planta* biblioteca(){
    static Planta inventario[5];
    return &inventario[5];
}

Pote* jardim(){
    static Pote potes[10];
    return &potes[10];
}

char Escolha(){
    char escolha;
    cin >> escolha;
    return escolha;
}



int qualPlanta(){
    int indice_planta;
    cout << "Qual planta?" << endl;
    do{
        cin >> indice_planta;
    }while(indice_planta < 0 || indice_planta >= 5);
    return indice_planta;
}

void nulificaPlanta(int i){
    Planta *plantas = biblioteca();
    plantas[i].flag = 1;
}

void Regar(){
    int const tempo_regar = 2;
    int indice_planta = qualPlanta();
    Planta *planta = biblioteca();
    planta[indice_planta].agua += 25;
}

void CriarPlanta(int i){
    string nomeP = nomePlanta();
    string nomeR = definirReino();
    Planta *ponteiro_planta = biblioteca();
    for(int j=0;j < sizeof(nomeP)/sizeof(nomeP[0]);j++)
        ponteiro_planta[i].nome[j] = nomeP[j];
    for(int j=0;j < sizeof(nomeR)/sizeof(nomeR[0]);j++)
        ponteiro_planta[i].reino[j] = nomeR[j];
    ponteiro_planta[i].desenvolvimento = "Semente";
    ponteiro_planta[i].agua = 100;
    ponteiro_planta[i].idade = 0;
    ponteiro_planta[i].vida = 10;
    ponteiro_planta[i].indicativo = i+1;
    ponteiro_planta[i].flag = false;
}

string nomePlanta(){
    string nomeP[4] = {"coisas","aleatorias","so","paratestar"};
    return nomeP[rand()%4];
}

string definirReino(){
    string nomeR[4] = {"fungus","mamidors","vegetal","suamae"};
    return nomeR[rand()%4];
}


void IntercalaAgua(int inicio, int meio, int fim){
    int i = inicio, j = meio, k = 0;
    Planta *w;
    Planta *planta = biblioteca();
    w = new(nothrow) Planta[fim];
    while(i < meio && j < fim){
        if(planta[i].agua < planta[j].agua){
            w[k].agua = planta[i].agua;
            i++;
        }
        else{
            w[k].agua = planta[j].agua;
            j++;
        }
        k++;
    }
    while(i < meio){
        w[k].agua = planta[i].agua;
        i++;
        k++;
    }
    while(j < fim){
        w[k].agua = planta[j].agua;
        j++;
        k++;
    }
    for(k = 0; k < fim - inicio; k++)
        planta[inicio + k].agua = w[k].agua;
    delete[] w;
    w = NULL;
}
void MergeAgua(int inicio, int fim){
    if(inicio < (fim-1)){
        int meio = (inicio + fim)/2;
        MergeAgua(inicio, meio);
        MergeAgua(meio,fim);
        IntercalaAgua(inicio,meio,fim);
    }
}


void IntercalaVida(int inicio, int meio, int fim){
    int i = inicio, j = meio, k = 0;
    Planta *w;
    Planta *planta = biblioteca();
    w = new(nothrow) Planta[fim];
    while(i < meio && j < fim){
        if(planta[i].vida < planta[j].vida){
            w[k].vida = planta[i].vida;
            i++;
        }
        else{
            w[k].vida = planta[j].vida;
            j++;
        }
        k++;
    }
    while(i < meio){
        w[k].vida = planta[i].vida;
        i++;
        k++;
    }
    while(j < fim){
        w[k].vida = planta[j].vida;
        j++;
        k++;
    }
    for(k = 0; k < fim - inicio; k++)
        planta[inicio + k].vida = w[k].vida;
    delete[] w;
    w = NULL;
}

void MergeVida(int inicio, int fim){
    if(inicio < (fim-1)){
        int meio = (inicio + fim)/2;
        MergeVida(inicio, meio);
        MergeVida(meio,fim);
        IntercalaVida(inicio,meio,fim);
    }
}


void IntercalIndicativo(int inicio, int meio, int fim){
    int i = inicio, j = meio, k = 0;
    Planta *w;
    Planta *planta = biblioteca();
    w = new(nothrow) Planta[fim];
    while(i < meio && j < fim){
        if(planta[i].indicativo < planta[j].indicativo){
            w[k].indicativo = planta[i].indicativo;
            i++;
        }
        else{
            w[k].indicativo = planta[j].indicativo;
            j++;
        }
        k++;
    }
    while(i < meio){
        w[k].indicativo = planta[i].indicativo;
        i++;
        k++;
    }
    while(j < fim){
        w[k].indicativo = planta[j].indicativo;
        j++;
        k++;
    }
    for(k = 0; k < fim - inicio; k++)
        planta[inicio + k].indicativo = w[k].indicativo;
    delete[] w;
    w = NULL;
}

void MergeIndicativo(int inicio, int fim){
    if(inicio < (fim-1)){
        int meio = (inicio + fim)/2;
        MergeIndicativo(inicio, meio);
        MergeIndicativo(meio,fim);
        IntercalIndicativo(inicio,meio,fim);
    }
}

void Ordenacao(char escolha){
    if(escolha == 'a')
        MergeAgua(0,5);
    if(escolha == 'v')
        MergeVida(0,5);
    if(escolha == 'i')
        MergeIndicativo(0,5);
}



void gotoxy(int x, int y){
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
void impPlanta(int l){
    Planta *planta=biblioteca();
    gotoxy(0 + (15*l), 1);
    cout << "|" << planta[l].nome;
    gotoxy(13 + (15*l), 1);
    cout << "|";
    gotoxy(0 + (15*l), 2);
    cout << "|" << planta[l].desenvolvimento << endl;
    gotoxy(13 + (15*l), 2);
    cout << "|";
    gotoxy(0 + (15*l), 3);
    cout << "|" << planta[l].idade << endl;
    gotoxy(13 + (15*l), 3);
    cout << "|" << endl;
}