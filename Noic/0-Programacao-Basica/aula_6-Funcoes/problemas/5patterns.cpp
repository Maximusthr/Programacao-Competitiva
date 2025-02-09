#include <bits/stdc++.h>

using namespace std;

int solve(int x){
    int soma = 0;
    if (x <= 3) return x;
    return solve(x-1) + solve(x-2);
}

int main(){
    int num;
    while(cin >> num && num){
        int qtd = solve(num);
        cout << qtd << "\n";
    }
}
