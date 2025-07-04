#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    string s; cin >> s;

    map<pair<char, char>, int> m;
    for (int i = 0; i < n-1; i++){
        m[{s[i], s[i+1]}]++;
    }

    int maior = 0;
    pair<char, char> ans;
    for (auto [x, y] : m){
        maior = max(maior, y);
        if (maior == y){
            ans = x;
        }
    }

    cout << ans.first << "" << ans.second << '\n';
}