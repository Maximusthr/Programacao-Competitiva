#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    map<char, int> freq;
    for (int i = 0; i < s.size(); i++){
        freq[s[i]]++;
    }

    int maior = 0;
    for (auto [x, y] : freq){
        maior = max(maior, y);
    }

    for (int i = 0; i < s.size(); i++){
        if (freq[s[i]] == maior) continue;
        cout << s[i];
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}