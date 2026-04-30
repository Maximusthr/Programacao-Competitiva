#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;
    s.push_back('#');
    s.push_back('#');
    s.push_back('#');
    
    int n = s.size();

    map<string, int> mapa;
    for (int i = 0; i < 1000; i += 8){
        string x = to_string(i);
        mapa[x]++;
    }

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                string u;
                u.push_back(s[i]);
                string d2;
                d2.push_back(s[i]);
                d2.push_back(s[j]);
                string d3;
                d3.push_back(s[i]);
                d3.push_back(s[j]);
                d3.push_back(s[k]);

                if (mapa.count(u)){
                    cout << "YES" << "\n";
                    cout << u << "\n";
                    return;
                }
                if (mapa.count(d2)){
                    cout << "YES" << "\n";
                    cout << d2 << "\n";
                    return;
                }
                if (mapa.count(d3)){
                    cout << "YES" << "\n";
                    cout << d3 << "\n";
                    return;
                }
            }
        }
    }

    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}