#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    int v[10]={}/* = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}*/;
    int k = 10000000;/*(rand() % 10000)+1;*/
    int inicio = 0;
    int fim = 10;
    int count = 0;
    int meio;
    srand(time(NULL));
//     for(int i=0;i<fim;i++){
//         v[i]=rand()%100+1;
//     }
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
    int inte=0;
    while(inicio <= fim){
        inte++;
        meio = (inicio+fim)/2;
        if(v[meio] == k){
            Ticks[1] = clock();
            double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
            cout << meio << " <-> Tempo: " << Tempo << " <-> Interações: " << inte << endl;
            count++;
            break;
//             getchar();
        }
        else if(v[meio] < k)
            inicio = meio+1;
        else
            fim = meio-1;
    }
    if(count == 0){
        Ticks[1] = clock();
        double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        cout << "-1 <-> Tempo: " << Tempo << " <-> Interações: " << inte << endl;
    }
    return 0; 
}
        
