#include <iostream>
using namespace std;

long long int iterativa4(char *cadena){
    long long int i=0;
    while(cadena[i]!='\0'){
        i++;
    }return i++;
}

long long int recursiva4(char *cadena, int i){
    if(cadena[i]=='\0'){
        return i++;
    }i++;
    return recursiva4(cadena, i);
}

int main(){
    char *cadena = new char[100];
    cout<<"ingresa la cadena: ";cin>>cadena;
    cout<<"la longitud con iteracion es: "<<iterativa4(cadena)<<endl;
    cout<<"la longitud con recursividad es: "<<recursiva4(cadena, 0)<<endl;

    return 0;
}