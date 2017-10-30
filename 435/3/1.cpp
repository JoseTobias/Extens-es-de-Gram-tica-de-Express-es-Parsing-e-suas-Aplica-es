#include <iostream>
using namespace std;
int main (){
    int n,pot,bin;
    
    cout <<"Digite o Numero: ";
    cin >> n;
    pot = 1;
    bin = 0;
    while (n > 0 {
        bin = bin + (n % 2)* pot;
        pot = pot*10;
        n = n/2;
    }
    cout <<"O numero convertido: " << bin;
    return 0;
}
 
