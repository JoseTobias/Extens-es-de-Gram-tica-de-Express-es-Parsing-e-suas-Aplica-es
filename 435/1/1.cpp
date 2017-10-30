#include <iostream>
using namespace std;
int main (){
    float media,n = 1,soma = 0;
    int i = 0;
    cout<<"Insira um numero negativo para parar."<<endl;
    
    while(n>=0){
        cout<<"Insira o numero: "<<endl;
        cin>>n;
        if(n=>0){
            soma = soma + n;
            i++;
        }
    }
    media = soma/i;
    cout<<"A soma dos "<<i<<" numeros digitados e: "<<soma<<endl;
    cout<<"A media dos "<<i<<" numeros digitados e: "<<media<<endl;
    return 0;
}
 
