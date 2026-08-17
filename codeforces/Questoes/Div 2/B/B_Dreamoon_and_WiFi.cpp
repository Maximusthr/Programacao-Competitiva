#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string a, b; cin >> a >> b;

    int s = 0;
    int t = 0;
    int qtd = 0;
    for (int i = 0; i < a.size(); i++){
        s += (a[i] == '+');
        s -= (a[i] == '-');
        t += (b[i] == '+');
        t -= (b[i] == '-');
        qtd += (b[i] == '?');
    }

    double ans = 1.0;

    vector<int> conj(1 << qtd);
    for (int i = 0; i < (1 << qtd); i++){
        int x = 0;
        for (int j = 0; j < qtd; j++){
            if (i & (1 << j)) x++;
            else x--;
        }
        conj[i] = x;
    }

    double bad = 0, good = 0;
    for (int i = 0; i < (1 << qtd); i++){
        int aux = t + conj[i];

        if (aux != s) bad++;
        else good++;
    }
    
    cout << fixed << setprecision(10);

    cout << good / (good + bad) << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
