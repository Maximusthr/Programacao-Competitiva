#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string a, b; cin >> a >> b;
    
    map<char, int> freq2;
    for (int i = b.size()-2; i >= 0; i--){
        if (freq2.count(b[i])) continue;
        freq2[b[i]] = i;
    }

    bool ok = false;
    for (int i = 1; i < a.size(); i++){
        if (freq2.count(a[i])) ok = true;
    }

    if (!ok){
        cout << -1 << "\n";
        return;
    }

    pair<int, int> pos;
    int total = INF;
    for (int i = 0; i < a.size()-1; i++){
        if (freq2.count(a[i+1])){
            int y = freq2[a[i+1]];

            int sum = b.size() - y + i + 1;
            if (sum < total) {
                total = sum;
                pos = {i, freq2[a[i+1]]};
            }
        }
    }
    
    string s;
    for (int i = 0; i <= pos.first; i++){
        s.push_back(a[i]);
    }
    for (int i = pos.second; i < b.size(); i++){
        s.push_back(b[i]);
    }
    cout << s << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}