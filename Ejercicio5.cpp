#include <iostream>
using namespace std;

long long int tam(char *cadena){
    long long int i=0;
    while(cadena[i]!='\0'){
        i++;
    }return i++;
}

void concatenar(char *a, char *b){
    int tam_b = tam(b);
    int tam_a = tam(a);

    int ind_a=0;
    for(int i=tam_b; i<tam_a+tam_b; i++){
        b[i] = a[ind_a];
        ind_a++;
    }b[tam_a+tam_b] = '\0';
}

int main(){
    char *a = new char[20];
    char *b = new char[40];

    cout<<"ingresa la cadena a: " ;cin>>a;
    cout<<"ingresa la cadena b: ";cin>>b;

    concatenar(a, b);

    cout<<endl<<" Cadena 'b' concatenada a 'a'"<<b;

    delete [] a;
    delete [] b;
    return 0;
}