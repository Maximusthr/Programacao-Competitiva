#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string s; cin >> s;

    int n = s.size();

    bool ok = false;
    vector<pair<int, int>> pares;
    for (int i = 0; i < n; i++){
        int v = s[i] - '0';
        if (v % 2 == 0){
            ok = true;
            pares.push_back({v, i});
        }
    }

    if (!ok) {
        cout << -1 << "\n";
        return 0;
    }

    int last = s[n-1] - '0';

    bool eh = (last) % 2 == 0;
    if (eh){
        for (int i = 0; i < n-1; i++){
            int v = s[i] - '0';
            if (v % 2 == 0 && last > v){
                swap(s[i], s[n-1]);
                break;
            }
        }

        cout << s << "\n";
        return 0;
    }

    for (int i = 0; i < pares.size(); i++){
        if (last > pares[i].first) {
            swap(s[n-1], s[pares[i].second]);
            break;
        }
    }
    
    // se ainda for impar
    if ((s[n-1] - '0') % 2){
        swap(s[n-1], s[pares[pares.size()-1].second]);
    }

    cout << s << "\n";
}
