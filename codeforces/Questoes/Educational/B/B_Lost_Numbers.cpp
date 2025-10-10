#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void queries(int a, int b){
    cout << "? " << a << " " << b << endl;
}

void solve(){
    int ask;
    vector<int> v;

    queries(1, 2);
    cin >> ask;
    
    v.push_back(ask);

    queries(2, 3);
    cin >> ask;

    v.push_back(ask);

    queries(3, 4);
    cin >> ask;

    v.push_back(ask);

    queries(4, 5);
    cin >> ask;

    v.push_back(ask);

    vector<int> lista = {4, 8, 15, 16, 23, 42};
    
    vector<int> num1;
    for (int i = 0; i < lista.size(); i++){
        if (v[0] % lista[i] == 0) num1.push_back(lista[i]);
    }
    vector<int> num2;
    for (int i = 0; i < lista.size(); i++){
        if (v[1] % lista[i] == 0) num2.push_back(lista[i]);
    }
    
    vector<int> funciona;
    for (int i = 0; i < num1.size(); i++){
        for (int j = i + 1; j < num1.size(); j++){
            if (num1[i] * num1[j] == v[0]) {
                funciona.push_back(num1[i]);
                funciona.push_back(num1[j]);
                break;
            }
        }
    }
    vector<int> funciona2;
    for (int i = 0; i < num2.size(); i++){
        for (int j = i + 1; j < num2.size(); j++){
            if (num2[i] * num2[j] == v[1]) {
                funciona2.push_back(num2[i]);
                funciona2.push_back(num2[j]);
                break;
            }
        }
    }

    array<int, 7> ans;

    for (int i = 0; i < funciona.size(); i++){
        for (int j = 0; j < funciona2.size(); j++){
            if (funciona[i] == funciona2[j]){
                ans[2] = funciona[i];
                break;
            }
        }
    }

    for (int i = 0; i < funciona2.size(); i++){
        if (funciona2[i] != ans[2]){
            ans[3] = funciona2[i];
            break;
        }
    }
    for (int i = 0; i < funciona.size(); i++){
        if (funciona[i] != ans[2]){
            ans[1] = funciona[i];
            break;
        }
    }

    ans[4] = v[2]/ans[3];
    ans[5] = v[3]/ans[4];

    for (int i = 0; i < lista.size(); i++){
        bool ok = false;
        for (int j = 1; j <= 6; j++){
            if (lista[i] == ans[j]){
                ok = true;
                break;
            }
        }
        if (!ok){
            ans[6] = lista[i];
        }
    }

    cout << "! ";
    for (int i = 1; i <= 6; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}