#include <iostream>
#include <ctime>
using namespace std;

void aleatorio(int *&arreglo, int tam){
    srand(time(NULL));
    for(int i=0; i<tam; i++){
        arreglo[i]=rand()%100;
    }
}

void print_array(int *arreglo, int tam){
    for(int i=0; i<tam; i++){
        cout<<arreglo[i]<<" ";
    }cout<<endl;
}

long long int iterativa(int *arreglo, int tam){
    long long int suma=0;
    if(tam%2==0){
        for(int i=0; i<tam/2; i++){
            suma+=arreglo[i]+arreglo[tam-1-i];
        }
    }else{
        for(int i=0; i<tam/2; i++){
            suma+=arreglo[i]+arreglo[tam-1-i];
        }suma+=arreglo[tam/2];  
    }
    return suma;
}

long long int recursiva(int *arreglo, int tam, int count, int suma, int max, int tam_su){
    if(count>=max/2){
        if(tam_su%2==0){
            return suma;

        }suma+=arreglo[tam/2];
        return suma;
    }
    suma+=arreglo[count]+arreglo[tam-1-count];
    count++;

    return recursiva(arreglo, tam, count, suma, max, tam_su);
}

long long int recursiva_general(int *arreglo, int tam, int count, int suma){
    long long int a = 0, resultado=0, b=10000;
    if(tam>10000){
        for(int i=0; i<tam/10000; i++, a+= 10000/2, b+= 10000){
            resultado += recursiva(arreglo, tam, a , suma, b, b-2*a);
        }if(tam%10000==0){
            return resultado;
        }else{
            resultado += recursiva(arreglo, tam, a , suma, tam , tam-2*a);
        }
    }else{
        resultado = recursiva(arreglo, tam, count, suma, tam, tam);
    }
    return resultado;
}

int main(){
    int tam, count=0, suma=0;;
    cout<<"el tamano del vector es: "; cin>>tam;
    int *arreglo = new int [tam];


    aleatorio(arreglo, tam);
    cout<<"La suma con iteratividad es "<<iterativa(arreglo, tam)<<endl;
    cout<<"La suma con recursividad es "<<recursiva_general(arreglo, tam, count, suma)<<endl;

    return 0;
}
