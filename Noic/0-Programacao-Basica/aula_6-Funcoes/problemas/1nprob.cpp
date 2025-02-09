#include <bits/stdc++.h>

using namespace std;

int aux;

int solve(int x){
    aux++;
    if (x == 1) return x;
    if (x % 2 == 1) x = (3*x) + 1;
    else x /= 2;
    return solve(x);
}

int main(){
    int x, y;
    while(cin >> x >> y){
        int var1 = x, var2 = y;
        if (x > y){
            int temp = x;
            x = y;
            y = temp;
        }
        int maior = 0;
        for (int i = x; i <= y; i++){
            aux = 0;
            int prob = solve(i);
            if (aux > maior) maior = aux;
        }
        cout << var1 << " " << var2 << " " << maior << '\n';
    }
}
