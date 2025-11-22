#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, a, b; cin >> n >> a >> b;

    vector<int> valores(n);
    iota(valores.begin(), valores.end(), 1);

    set<int> v = {valores.begin(), valores.end()};

    if (a <= b){
        // maior começa no inicio
        vector<int> ini;
        for (int i = 0; i < a; i++){
            int valor = n - a + i + 1;
            ini.push_back(valor);
            v.erase(valor);
        }
        
        vector<int> resto = {v.begin(), v.end()};

        b--;

        int form = resto.size() - b;
        if (form < 0){
            cout << "no" << "\n";
            return 0;
        }
        reverse(resto.begin() + form, resto.end());

        for (int i = 0; i < resto.size(); i++){
            ini.push_back(resto[i]);
        }

        // for (auto &i : ini) cout << i << " ";
        // cout << "\n";

        // adicionar a funcao de verificação
        int start = 0;
        int maior = 0;
        for (int i = 0; i < n; i++){
            if (maior < ini[i]){
                start++;
                maior = ini[i];
            }
        }

        maior = 0;
        int end = 0;
        for (int i = n-1; i >= 0; i--){
            if (maior < ini[i]){
                end++;
                maior = ini[i];
            }
        }

        if (start == a && end == b+1){
            cout << "yes" << "\n";
            for (auto &i : ini){
                cout << i << " ";
            }
            cout << "\n";
        }
        else {
            cout << "no" << "\n";
        }
    }
    else {
        // maior começa no inicio
        // b < a
        vector<int> ini;
        for (int i = 0; i < b; i++){
            int valor = n - b + i + 1;
            ini.push_back(valor);
            v.erase(valor);
        }
        
        vector<int> resto = {v.begin(), v.end()};

        a--;

        int form = resto.size() - a;
        if (form < 0){
            cout << "no" << "\n";
            return 0;
        }
        reverse(resto.begin() + form, resto.end());

        for (int i = 0; i < resto.size(); i++){
            ini.push_back(resto[i]);
        }

        reverse(ini.begin(), ini.end());

        // for (auto &i : ini) cout << i << " ";
        // cout << "\n";

        // adicionar a funcao de verificação
        int start = 0;
        int maior = 0;
        for (int i = 0; i < n; i++){
            if (maior < ini[i]){
                start++;
                maior = ini[i];
            }
        }

        maior = 0;
        int end = 0;
        for (int i = n-1; i >= 0; i--){
            if (maior < ini[i]){
                end++;
                maior = ini[i];
            }
        }

        if (start == a+1 && end == b){
            cout << "yes" << "\n";
            for (auto &i : ini){
                cout << i << " ";
            }
            cout << "\n";
        }
        else {
            cout << "no" << "\n";
        }
    }
}