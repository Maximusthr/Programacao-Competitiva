#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, dur, B, S; cin >> n >> dur >> B >> S;

    B--, S--;

    vector<int> perm(n);
    for (int i = 0; i < n; i++){
        cin >> perm[i];
        perm[i]--;
    }

    vector<ll> v(n);
    for (auto &i : v) cin >> i;

    auto ans = [&](int QUAL) -> ll {
        vector<ll> path, prefix;

        int pos = perm[QUAL];
        int ant = QUAL;

        path.push_back(QUAL);
        prefix.push_back(v[ant]);

        int aux = 0, temp = dur;
        while(temp > 1 && n > aux){
            path.push_back(pos);
            
            ant = pos;
            pos = perm[pos];

            prefix.push_back(v[ant]);

            temp--;
            aux++;
        }

        reverse(path.begin(), path.end());

        for (int i = 1; i < prefix.size(); i++){
            prefix[i] += prefix[i-1];
        }

        reverse(prefix.begin(), prefix.end());

        ll sum = 0;
        
        int i = 0;
        while(temp <= dur){
            sum = max(sum, v[path[i]] * (temp - 1) + prefix[i]);
            temp++;
            i++;
        }

        return sum;
    };

    if (ans(B) > ans(S)) cout << "Bodya" << "\n";
    else if (ans(B) < ans(S)) cout << "Sasha" << "\n";
    else cout << "Draw" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}