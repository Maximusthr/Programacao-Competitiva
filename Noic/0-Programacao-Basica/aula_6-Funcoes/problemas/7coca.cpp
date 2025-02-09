#include <bits/stdc++.h>

using namespace std;

int qtd;

int solve(int x){
    if (x % 3 == 0 && x >= 3) {
        qtd += x/3;
        return solve(x/3);
    }
    else if (x % 3 != 0 && x >= 3) {
        qtd += x/3;
        return solve((x/3) + (x % 3));
    }
    if (x + 1 == 3) qtd++;
    return qtd;
}

int main(){
    int x;
    while(cin >> x && x){
        qtd = 0;
        cout << solve(x) << '\n';
    }
}
