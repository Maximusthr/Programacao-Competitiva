#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;

    vector<int> arr(n+1);
    vector<int> pos(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    string x = "#";
    string s; cin >> s;

    s = x + s;
    
    vector<int> diff(n+2);
    for (int i = 1; i <= n; i++){
        diff[min(i, pos[i])]++;
        diff[max(i, pos[i])]--;
    }
    
    for (int i = 1; i <= n; i++){
        diff[i] += diff[i-1];
    }
    
    set<int> bad;
    for (int i = 1; i < n; i++){
        if (s[i] == 'L' && s[i+1] == 'R') {
            if (diff[i] > 0) bad.insert(i);
        }
    }

    while(q--){
        int x; cin >> x;

        if (s[x] == 'L') s[x] = 'R';
        else s[x] = 'L';

        if (s[x] == 'L' && s[x+1] == 'R'){
            if (diff[x] > 0) bad.insert(x);
        }
        else if (s[x] == 'R' && s[x-1] == 'L'){
            if (diff[x-1] > 0) bad.insert(x-1);
        }

        if (s[x] == 'R'){
            if (bad.count(x)){
                bad.erase(x);
            }
        }
        else if (s[x] == 'L' && s[x-1] == 'L'){
            if (bad.count(x-1)) bad.erase(x-1);
        }

        cout << (bad.size() > 0 ? "NO" : "YES") << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}