# include <iostream>
using namespace std;
int main (){
    float b=1,h=1,A,soma = 0;
    int i = 1;
    cout<<"Parar se inserir dimensoes negativas."<<endl;
    while(b>0 && h>0){
        cout<<"Insira a base e a altura do retangulo "<<i<<" :";
        cin>>b>>h;
        if(i == 1 && (b<=0 || h<=0)){
            cout << "Nenhum retangulo inserido." << endl;
            return 0;
        
        A = b*h;
        soma = soma + A;
        i++;
    }
    cout<<"Somatorio das areas: "<< soma <<". Area e a do ultimo retangulo: "<<A;
    return 0;
}
 
 
