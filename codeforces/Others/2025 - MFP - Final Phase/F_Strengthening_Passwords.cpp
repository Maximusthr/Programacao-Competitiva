#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = (int)s.size();

    if (n <= 10){
        cout << "N" << "\n";
        return;
    }

    int l = 0;
    int qtd = 0;
    for (int i = 0; i < n; i++){
        if (s[i] >= 'a' && s[i] <= 'z') l++;
        if (s[i] >= '0' && s[i] <= '9') qtd++;
    }
    if (l < 1 || qtd < 1) {
        cout << "N" << "\n";
        return;
    }

    bool num = false;
    bool letra = false;
    for (int i = 0; i < n; i++){
        if (letra && s[i] >= '0' && s[i] <= '9'){
            cout << "N" << "\n";
            return;
        }
        else if (!letra && s[i] >= 'a' && s[i] <= 'z') letra = true;
    }

    string numeros;
    string palavras;
    for (int i = 0; i < n; i++){
        if (s[i] >= '0' && s[i] <= '9') numeros += s[i];
        else palavras += s[i];
    }

    string temp = numeros;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < numeros.size(); i++){
        if (temp[i] != numeros[i]) {
            cout << "N" << "\n";
            return;
        }
    }

    temp = palavras;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++){
        if (temp[i] != palavras[i]){
            cout << "N" << "\n";
            return;
        }
    }

    cout << "S" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}