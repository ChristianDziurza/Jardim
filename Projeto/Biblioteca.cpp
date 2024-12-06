#include <iostream>
using namespace std;

typedef struct{
    char nome[5];
    double agua;
    int vida = 10;
    string desenvolvimento[3] = {"Semente", "Broto", "Adulto"};
    string reino;
    char indicativo;
}Planta;

void CriarMatriz(int *Matriz[], int n);
Planta* bibloteca();

int main(){
    Planta *planta = bibloteca();
    int n;
    cin >> n;
    int *jardimM;
    if(!(jardimM = new(nothrow) int[n][100]))
    CriarMatriz(pM,n);
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

void CriarMatriz(int *Matriz[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            Matriz[i][j] = 0;
            cout << Matriz[i][j];
        }
        cout << endl;
    }
}