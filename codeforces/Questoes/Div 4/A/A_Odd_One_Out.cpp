#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        int a, b, c; cin >> a >> b >> c;

        int aux;

        if (a == b && a != c) aux = c;
        else if (a == c && a != b) aux = b;
        else aux = a;

        cout << aux << "\n";
    }
}