#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    string s; cin >> s;

    string dois;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '2') dois.push_back('2');
    }

    string v;
    v.assign(n, '+');

    int ini = 0, end = n-1;
    for (int i = 0; i < k; i++){
        if (s[i] == '2') continue;
        if (s[i] == '0'){
            v[ini] = '-';
            ini++;
        }
        else if (s[i] == '1'){
            v[end] = '-';
            end--;
        }
    }

    if (dois.size() == end-ini+1){
        v.assign(n, '-');
    }
    else {
        for (int i = 0; i < dois.size() && ini <= end; i++){
            v[ini++] = '?';
            v[end--] = '?';
        }
    }

    cout << v << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}