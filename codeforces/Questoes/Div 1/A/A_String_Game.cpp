#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string s, t; 
vector<int> seq;

bool ok(int m){
    int tam = (int)seq.size();
    vector<bool> vis(tam);

    for (int i = 0; i < m; i++) {
        vis[seq[i]] = 1;
    }

    int cont = 0;
    for (int i = 0, j = 0; i < s.size(); i++){
        if (vis[i]) continue;
        if (s[i] == t[j]){
            cont++;
            j++;
            if (cont == (int)t.size()) return true;
        }
    }
    return false;
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> s >> t;

    for (int i = 0; i < (int)s.size(); i++){
        int n; cin >> n;
        n--;
        seq.push_back(n);
    }

    int l = 0, r = seq.size()-1;
    int ans = 0;
    while (l <= r){
        int mid = l + (r-l)/2;

        if (ok(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans << "\n";
}
