#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;
    while(qtd--){

        int a, b, c; cin >> a >> b >> c;
        
        if (b > a && b > c) cout << "PEAK";
        else if (b > a && b < c) cout << "STAIR";
        else cout << "NONE";
        
        cout << "\n";
    }
}
