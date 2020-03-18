#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int inte = 0;
int count = 0;

int bs(int v[], int valor, int inicio, int fim){
    inte++;
    if(inicio > fim){
        count = 1;
        return false;
    }
    int meio = (inicio + fim)/2;
    if(valor==v[meio]){
        count = 2;
        return true;
    }
    else if(v[meio] > valor)
        return bs(v, valor, inicio, meio-1);
    else
        return bs(v, valor, meio+1, fim);
}

int main(){
    int v[10]={};
    int inicio = 0;
    int fim = 10;
    int k = 1000000;
    int menor,aux;
    for(int i=0;i<fim-1;i++){
        menor = i;
        for (int j=(i+1);j<fim;j++){
            if (v[j]> v[menor]){
                menor = i;
            }
        }
        if(i != menor){
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
    }
    clock_t Ticks[2];
    Ticks[0] = clock();
    bs(v, k, inicio, fim);
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    if(count == 2) cout << "1 <-> Tempo: " << Tempo << " <-> Interações: "<< inte <<  endl;
    else if(count == 1) cout << "-1 <-> Tempo: " << Tempo << " <-> Interações: "<< inte <<  endl;
    return 0;
}
