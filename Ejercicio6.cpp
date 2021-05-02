#include <iostream>
using namespace std;

void print(char *arr, int tam){
    for (int i = 0; i < tam; i++)
        cout << arr[i] << " ";
}

void aleatorio_char(char *cadena, int tam){
    for(int i=0; i<tam; i++){
        cadena[i] = 97+rand()%(123-97);
    }
}

bool comprobar(char *arr, int tam){
    for(int i=0; i+1<tam ; i++){
        if(!(arr[i]<=arr[i+1])){
            return false;
        }
    }return true;
}
int mayor(char *arr, int tam){
    int mayor = arr[0];
    for (int i = 1; i < tam; i++){
        if (arr[i] > mayor){
            mayor = arr[i];
        }
    }return mayor;
}

void count_sort(char *arr, int tam, int ind){
    int *arreglo_temp = new int[tam];
    int i, count[10] = { 0 };

    for (i = 0; i < tam; i++){
        count[(arr[i] / ind) % 10]++;
    }

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = tam - 1; i >= 0; i--) {
        arreglo_temp[count[(arr[i] / ind) % 10] - 1] = arr[i];
        count[(arr[i] / ind) % 10]--;
    }

    for (i = 0; i < tam; i++){
        arr[i] = arreglo_temp[i];
    }
    delete [] arreglo_temp;
}

void radix_sort(char *arr, int tam){
    for (int i=1; mayor(arr, tam)/i>0; i*=10){
        count_sort(arr, tam, i);
    }
}

int main(){
    int tam;
    cout<<"el tamano del vector es: "; cin>>tam;
    char *cadena = new char [tam];

    aleatorio_char(cadena, tam);
    radix_sort(cadena, tam);
    if(comprobar(cadena, tam)){
        cout<<"ordenado "<<endl;
    }

    delete [] cadena;
    return 0;
}