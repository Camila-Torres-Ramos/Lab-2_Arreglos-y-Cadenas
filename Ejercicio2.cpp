#include <iostream>
#include <ctime>
using namespace std;

void aleatorio(int *&arreglo, int tam){
    srand(time(NULL));
    for(int i=0; i<tam; i++){
        arreglo[i]=rand()%100;
    }
}

bool comprobar(int *arreglo, int *arreglo_cop, int tam){
    for(int i=0; i<tam/2; i++){
        if(arreglo[i]!=arreglo_cop[tam-1-i]){
            return false;
        }
    }return true;
}

void iterativa(int *arreglo, int tam){
    int aux;
    for(int i=0; i<tam/2; i++){
        aux=arreglo[i];
        arreglo[i]=arreglo[tam-1-i];
        arreglo[tam-1-i]=aux;
    }
}

void recursiva(int *&arreglo, int tam, int count, int max){
    int aux;
    if(count>=max/2){
        return;
    }
    aux = arreglo[count];
    arreglo[count] = arreglo[tam-1-count];
    arreglo[tam-1-count] = aux ;
    count++;

    recursiva(arreglo, tam, count, max);
}

void recursiva_general(int *&arreglo, int tam, int count){
    long long int a = 0, resultado=0, b=10;
    if(tam>10){
        for(int i=0; i<tam/10; i++, a+= 10/2, b+= 10){
            recursiva(arreglo, tam, a, b);
        }if(tam%10==0){
            return;
        }else{
            recursiva(arreglo, tam, a , tam );
        }
    }else{
        recursiva(arreglo, tam, count, tam);
    }
}

int main(){
    int tam, count=0, suma=0;;
    cout<<" el tamano del vector es: "; cin>>tam;
    int *arreglo = new int [tam];
    int *arreglo_cop = new int [tam];

    aleatorio(arreglo, tam);
    for(int i=0; i<tam; i++){
        arreglo_cop[i]=arreglo[i];
    }
    iterativa(arreglo, tam);
    
    if(comprobar(arreglo, arreglo_cop, tam)){
        cout<<"Invertido "<<endl;
    }
    iterativa(arreglo, tam);

    recursiva_general(arreglo, tam, count);
    if(comprobar(arreglo, arreglo_cop, tam)){
        cout<<"Invertido "<<endl;
    }    
    delete [] arreglo;
    delete [] arreglo_cop;

    return 0;
}