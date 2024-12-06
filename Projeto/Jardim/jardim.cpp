#include <iostream>
#include <ctime>
using namespace std;

#define N 4

typedef struct{
    string nome;
    double agua;
    int vida = 10;
    string desenvolvimento[3] = {"Semente", "Broto", "Adulto"};
    string reino;
    char indicativo;
}Planta;

void InserirNaMatriz(int *mapa);
int CriarPlanta();
int Bible(Planta planta);

int main(){
    srand(time(NULL));
    int jardim[N][N];

    return 0;
}

int CriarPlanta(){
    Planta planta;
    cin >> planta.nome >> planta.agua >> planta.reino >> planta.indicativo;
    int i = rand()%3;
    planta.desenvolvimento[i];
    return 1;
}

void InserirNaMatriz(int mapa[N][N]){
    int x, y;
    cin >> x >> y; 
    bool cond = x>0 && y>0 && x<N+1 && y<N+1;
    while(!cond){
        cin >> x >> y;
    }
    mapa[x][y] = CriarPlanta();
}

int Bible(Planta planta){
    Planta vP[N];
    static int cont = 0;
    static int i;
}