#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    //map<string, int> mapa;

    vector<pair<string, int>> mapa;

    for (int i = 0; i < n; i++){
        string s; cin >> s;
        // mapa[s] = i+1;
        mapa.push_back({s, i+1});
    }

    int x; string s; cin >> x >> s;

    for (int i = 0; i < mapa.size(); i++){
        if (mapa[i].second == x){
            if (mapa[i].first == s){
                cout << "Yes" << "\n";
                return 0;
            } 
        }
    }

    cout << "No" << "\n";

    // if (mapa[s] == x) {
    //     cout << "Yes" << "\n";
    // }
    // else cout << "No" << "\n";
}