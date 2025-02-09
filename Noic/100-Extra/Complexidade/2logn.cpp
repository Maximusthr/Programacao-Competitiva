//busca nos dígitos binários do número
//não é uma busca binária
//imprime a parte inteira da raiz de n

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    long long n, sq = 0, test;
    cin >> n;

    for(int pot = 31; pot >= 0; --pot){
        test = sq + (1 << test);
        if(test*test <= n)  sq = test;
    }
    cout << sq << "\n";

}
