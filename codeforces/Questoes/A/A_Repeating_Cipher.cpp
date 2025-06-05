#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    string s; cin >> s;

    string decry; 

    int cont = 0;
    int first = 1;
    for (int i = 0; i < n; i++){
        cont++;
        if (cont == first){
            decry += s[i];
            cont = 0;
            first++;
        }
    }

    cout << decry << "\n";
}