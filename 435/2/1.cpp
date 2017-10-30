#include <iostream>
using namespace std;
int main(){
    int n, i = 0, par = 0, impar = 0;
    cout<<"Para parar insira o numero 0."<<endl;
    while(true){
        cout<<"insira o numero: ";
        cin>>n;
        if ((n%2 = 0)&&(n!=0)){
            par = par+1;
            i++;
        }
        else if((n%2 != 0)&&(n !=0)){
            impar = impar+1;
            i++;
        }
        else{
            break;
        }
    }
    cout<<"Dos "<<i<<" numeros digitados "<<par<<" sao pares. E "<<impar<<" sao impares."<<endl;
    return 0;
}
 
