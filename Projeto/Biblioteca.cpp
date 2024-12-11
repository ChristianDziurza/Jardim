#include <iostream>
#include <ctime>
using namespace std;
int dia = 0;

typedef struct{
    char nome[30];
    double agua;
    int vida;
    string desenvolvimento;
    char reino[30];
    int indicativo;
    int x,y;
    int idade;
}Planta;

typedef struct{
    Planta planta;
    int flag;
}Pote;

void impPlanta();
void tempo();
void acao(int qTempo);
void mudPlanta();
void CriarPlanta(int n, int i);
void alterarPote();
void nulificaPlanta(int i);
bool terminaDia();
Planta* biblioteca();
string nomePlanta();
string definirReino();

int main(){
    srand(time(NULL));
    Planta *planta = biblioteca();
    int n;
    cin >> n;
    for(int i=0; i<5;i++){
        CriarPlanta(n,i);
        }
    tempo();
     return 0;
}

void impPlanta(){
    Planta *planta=biblioteca();
    for(int i=0; i<5;i++){
        cout << planta[i].nome << endl;
        cout << planta[i].reino << endl;
        cout << planta[i].desenvolvimento << endl;
        cout << planta[i].agua << endl;
        cout << planta[i].vida << endl;
        cout << planta[i].idade << endl;
        cout << planta[i].indicativo << endl;
        cout << endl << endl;
    }
}

void tempo(){
    int masitempo =0;
    while (cin>> masitempo){
        acao(masitempo);
    }

    }

void acao(int adTempo){
    static int qTempo=0;
    qTempo += adTempo;
    if(qTempo >=24){
        if(terminaDia()){
            cout << "planta antes"<< endl;
            impPlanta();
            mudPlanta();
            cout << "planta hoje"<< endl;
            impPlanta();
            qTempo=0;
        }
        else{
            qTempo -= adTempo;
        }
    }

}

void mudPlanta(){
    Planta *mudanca=biblioteca();
    dia++;
    for(int i=0;i<5;i++){
        mudanca[i].idade++;
        mudanca[i].agua-=rand() %98+1;
        if(mudanca[i].idade>3 && mudanca[i].idade<=7){
            mudanca[i].desenvolvimento="muda";
        }
        if(mudanca[i].idade>7){
            mudanca[i].desenvolvimento="adulto";
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

void alterarPote(){
    int indice_pote, indicativo_planta;
    bool pote = true;
    do{
        cout << "Escolhe o pote" << endl;
        do{
            cin >> indice_pote;
        }while(indice_pote <= 10 && indice_pote > 0 );
        indice_pote--;
        Pote *ponteiro_potes = jardim();
        cout << "Qual das cinco plantas voce deseja colocar nesse pote?" << endl;
        do{
            cin >> indicativo_planta;
        }while(indicativo_planta > 0 && indicativo_planta <= 5);
        Planta *ponteiro_planta = biblioteca();
        for(int i = 0; i<5; i++){
            if(ponteiro_planta[i].indicativo == indicativo_planta){
                if(ponteiro_potes[indice_pote].flag != 0){
                    ponteiro_potes[indice_pote].planta = ponteiro_planta[i];
                    nulificaPlanta(i);
                    pote = false;
                }
                else{
                    cout << "Pote cheio pae" << endl;
                }
            }
        }
    }while(pote);
}
void nulificaPlanta(int i){
    Planta *plantas = biblioteca();
    plantas[i].agua = NULL;
    plantas[i].desenvolvimento = "";
    plantas[i].idade = NULL;
    plantas[i].indicativo = NULL;
    plantas[i].vida = NULL;
    for(int j = 0; j<30; j++){
        plantas[i].nome[j] = NULL;
        plantas[i].reino[j] = NULL;
    }
}

void CriarPlanta(int n, int i){
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
}

string nomePlanta(){
    string nomeP[4] = {"coisas","aleatorias","so","paratestar"};
    return nomeP[rand()%4];
}

string definirReino(){
    string nomeR[4] = {"fungus","mamidors","vegetal","suamae"};
    return nomeR[rand()%4];
}