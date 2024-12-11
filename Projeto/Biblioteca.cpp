#include <iostream>
#include <ctime>
#include <windows.h>
#include <cassert>
using namespace std;
int dia = 0;

typedef struct{
    char nome[30];
    double agua;
    unsigned int vida;
    string desenvolvimento;
    char reino[30];
    int indicativo;
    int idade;
}Planta;


void tempo();
void acao(int qTempo);
void mudPlanta();
void CriarPlanta(int i);
void IntercalaAgua(int inicio, int meio, int fim);
void MergeAgua(int inicio, int fim);
void IntercalaVida(int inicio, int meio, int fim);
void MergeVida(int inicio, int fim);
void IntercalIndicativo(int inicio, int meio, int fim);
void MergeIndicativo(int inicio, int fim);
void Ordenacao(char escolha);
void impPlanta(int l);
void impPlantaDetalhado(int l);
void impComandos();
void gotoxy(int x, int y);
void Detalhes();
int qualPlanta();
void Podar();
void Cuidar();
void TrocarPlanta();
void Teste_Busca_Bi();
int BuscaBi(int x, int ini, int fim);
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
            impComandos();
        es = Escolha();
        if(es == 'r')
            Regar();
        if(es == 'c')
            Cuidar();
        if(es == 'x')
            Podar();
        if(es == 'a' || es == 'v' || es == 'i')
            Ordenacao(es);
        if(es == 'd')
            Detalhes();
        if(es == 'p')
            acao(25);
        if(es == 't')
            TrocarPlanta();
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
    int atacada = rand()%15;
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
            if(atacada <= 4)
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
    }while(indice_planta <= 0 || indice_planta > 5);
    return indice_planta-1;
}

void Regar(){
    int const tempo_regar = 2;
    int indice_planta = qualPlanta();
    Planta *planta = biblioteca();
    planta[indice_planta].agua += 25;
    acao(tempo_regar);
}

void Podar(){
    int const tempo_podar = 7;
    int indice_planta = qualPlanta();
    Planta *planta = biblioteca();
    planta[indice_planta].vida -= 5;
    acao(tempo_podar);
}

void Cuidar(){
    int const tempo_cuidar = 12;
    int indice_planta = qualPlanta();
    Planta *planta = biblioteca();
    planta[indice_planta].vida += 5;
    acao(tempo_cuidar);
}

void TrocarPlanta(){
    int const tempo_troca = 4;
    int indice_planta = qualPlanta();
    CriarPlanta(indice_planta);
    acao(tempo_troca);
}

void Detalhes(){
    MergeIndicativo(0,5);
    int x = qualPlanta();
    int indice = BuscaBi(x+1,0,5);
    impPlantaDetalhado(indice);
    system("pause");
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
}

string nomePlanta(){
    string nomeP[6] = {"Musgo","Orquidea","Araucaria","Amanita","Cyathus","Polyporus"};
    return nomeP[rand()%6];
}

string definirReino(){
    string nomeR[2] = {"Plantae","Fungi"};
    return nomeR[rand()%2];
}

int BuscaBi(int x, int ini, int fim){
    Planta *p = biblioteca();
    if(ini > fim)
        return -1;
    else{
        int meio = (ini+fim)/2;
        if(p[meio].indicativo == x)
            return meio;
        else
            if(x < p[meio].indicativo)
                return BuscaBi(x,ini,meio-1);
            else
                return BuscaBi(x,meio+1,fim);
    }
}


void IntercalaAgua(int inicio, int meio, int fim){
    int i = inicio, j = meio, k = 0;
    Planta *w;
    Planta *planta = biblioteca();
    w = new(nothrow) Planta[fim];
    while(i < meio && j < fim){
        if(planta[i].agua < planta[j].agua){
            w[k] = planta[i];
            i++;
        }
        else{
            w[k] = planta[j];
            j++;
        }
        k++;
    }
    while(i < meio){
        w[k] = planta[i];
        i++;
        k++;
    }
    while(j < fim){
        w[k] = planta[j];
        j++;
        k++;
    }
    for(k = 0; k < fim - inicio; k++)
        planta[inicio + k] = w[k];
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
            w[k] = planta[i];
            i++;
        }
        else{
            w[k] = planta[j];
            j++;
        }
        k++;
    }
    while(i < meio){
        w[k] = planta[i];
        i++;
        k++;
    }
    while(j < fim){
        w[k] = planta[j];
        j++;
        k++;
    }
    for(k = 0; k < fim - inicio; k++)
        planta[inicio + k] = w[k];
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
            w[k] = planta[i];
            i++;
        }
        else{
            w[k] = planta[j];
            j++;
        }
        k++;
    }
    while(i < meio){
        w[k] = planta[i];
        i++;
        k++;
    }
    while(j < fim){
        w[k] = planta[j];
        j++;
        k++;
    }
    for(k = 0; k < fim - inicio; k++)
        planta[inicio + k] = w[k];
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
    cout << "|" << planta[l].indicativo;
    gotoxy(13 + (15*l), 3);
    cout << "|";
    gotoxy(0 + (15*l), 4);
    cout << "|" << planta[l].idade << endl;
    gotoxy(13 + (15*l), 4);
    cout << "|" << endl;
}

void impPlantaDetalhado(int l){
    Planta *planta=biblioteca();
    system("cls");
    gotoxy(0 , 1);
    cout << "|" << "Nome: " << planta[l].nome;
    gotoxy(18 , 1);
    cout << "|";
    gotoxy(0 , 2);
    cout << "|" << "Estagio: " << planta[l].desenvolvimento << endl;
    gotoxy(18 , 2);
    cout << "|";
    gotoxy(0 , 3);
    cout << "|" << "Idade: " << planta[l].idade << endl;
    gotoxy(18 , 3);
    cout << "|";
    gotoxy(0 , 4);
    cout << "|" << "Agua: " << planta[l].agua << endl;
    gotoxy(18 , 4);
    cout << "|";
    gotoxy(0 , 5);
    cout << "|" << "Reino: " << planta[l].reino << endl;
    gotoxy(18 , 5);
    cout << "|";
    gotoxy(0 , 6);
    cout << "|" << "Saude: " << planta[l].vida << endl;
    gotoxy(18 , 6);
    cout << "|";
    gotoxy(0 , 7);
    cout << "|" << "Indice: " << planta[l].indicativo << endl;
    gotoxy(18 , 7);
    cout << "|" << endl;
}

void impComandos(){
    cout << "| Regar uma planta(r) | " << "Podar uma planta(x) | " << "Cuidar de uma planta(c) |" << endl;
    cout << "| Ordenar baseado em: " << endl;
    cout << "| Quantidade de agua(a) || " << "Quantidade de vida(v) || " << "Indicativo da planta(i) |" << endl;
    cout << "| Detalhes de uma planta(d) |" << endl;
    cout << "| Deseja trocar uma planta por outra nova?(t) |" << endl;
    cout << "Sair(s)" << endl;
}

void Teste_Busca_Bi(){
    assert(BuscaBi(2,0,5) == 2);
    assert(BuscaBi(3,0,5) == 3);
    assert(BuscaBi(4,0,5) == 4);
    assert(BuscaBi(5,0,5) == 5);
    assert(BuscaBi(1,0,5) == 1);
    assert(BuscaBi(6,0,5) == -1);
}