#include <iostream>
using namespace std;

typedef struct{
    char nome[5];
    double agua;
    int vida = 10;
    string desenvolvimento[3] = {"Semente", "Broto", "Adulto"};
    string reino;
    char indicativo;
    int x, y;
}Planta;

void CriarMatriz( int n);
Planta* bibloteca();
void CriarPlanta(int n);

int main(){
    Planta *planta = bibloteca();
    int n, np;
    cout << "Qual Tamanho" << endl;
    cin >> n;
    cout << "Quantas plantas voce quer criar?" << endl;
    cin >> np;
    for(int i=0;i < np;i++){
        CriarPlanta(n);
        CriarMatriz(n);
    }
    //TESTE
    /*
    string nome2;
    for(int i=0;i<4;i++){
        cin >> nome2;
        for(int j=0;j<5;j++){
            (planta+i)->nome[j] = nome2[j];
        }
    }
    cout << "||||||" << endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            cout << (planta+i)->nome[j];
        }
        cout << endl;
    }
    */
    return 0;
}

Planta* bibloteca(){
    static Planta inventario[4];
    return &inventario[4];
}
void CriarPlanta(int n){
    string nome1;
    Planta *planta = bibloteca();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            planta[i].x = -20;
            planta[i].y = -20;
        }
    }
    int posicao=-1;
    cout << "Qual posicao da planta" << endl;
    while(posicao<0 || posicao > 4){
        cin >> posicao;
    }
    cout << "Nome: " << endl;
    cin >> nome1;
    for(int i =0; i<5; i++){
        planta[posicao].nome[i] = nome1[i];
    }
    cout << "Qual posicao no mapa" << endl;
    int x=-1, y=-1; 
    while(x<=0 || y<=0 || x > n || y>n){
        cin >> x >> y;
        x--;
        y--;
    }
    planta[posicao].x = x;
    planta[posicao].y = y;
}
void CriarMatriz(int n){
    char Matriz[n][n] = {'-'};
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            Matriz[i][j] = '-';
        }
    }
    Planta *plantas = bibloteca();
    
    for(int i = 0; i<4; i++){
        int x = plantas[i].x, y = plantas[i].y;
        if(x != -20)
            Matriz[x][y] = plantas[i].nome[0];
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << Matriz[i][j] << " ";
        }
        cout << endl;
    }
}