#include <iostream>
                
using namespace std;            
                
int main(){             
        float n = 0,soma=0,media;             
        int p,pesoTotal = 0;                       
        while(n>=0){             
                cout<<"Insira o numero: ";              
                cin>>n;         
                if(n>=0){               
                        cout<<"Insira o peso: ";                
                        cin>>p;         
                        soma = soma + n*p;              
                        pesoTotal = pesoTotal + p               
                }               
        }           
        media = soma/pesoTotal;         
        cout<<"A media ponderada: "<<media;             
        return 0;               
}
 
