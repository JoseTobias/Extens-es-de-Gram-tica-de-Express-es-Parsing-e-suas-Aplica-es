#include <iostream>
using namespace std;
int main (){
    
    int n;
    int fatorial;
    cout<<"insira um numero inteiro: ";
    cin>>n;
    fatorial = n;
    for (int i =n, i > 1; i--) {
        fatorial = fatorial*(i-1);
    }
    cout<<n<<"! = "<<fatorial;
    return 0;
}
 
