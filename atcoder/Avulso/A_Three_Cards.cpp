#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    
    vector<string> s(n);

    for (int i = 0; i < n; i++){
        cin >> s[i];
    }

    sort(s.begin(), s.end(), [&](string &a, string &b){
        if (a.size() != b.size()) return a.size() > b.size();
        return a + b > b + a;
    });

    vector<string> aux;

    for (int i = 0; i < 3; i++){
        aux.push_back(s[i]);
    }

    string maior;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                if (i == j || j == k || i == k) continue;
                maior = max(aux[i] + aux[j] + aux[k], maior);
            }
        }
    }

    cout << maior << "\n";
}