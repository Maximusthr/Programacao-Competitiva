#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    vector<int> dq;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '+') {
            int v = -1;
            if (dq.size() > 0){
                if (dq.back() == 0) v = 0;
            }
            dq.push_back(v);
        }
        else if (s[i] == '-') {
            int v = dq.back();
            dq.pop_back();
            if (dq.size() > 0 && dq.back() != v && v == 1) {
                dq.pop_back();
                dq.push_back(v);
            }
        }
        else {
            if (s[i] == '0'){
                if (dq.size() < 2 || dq.back() == 1) {
                    cout << "NO" << "\n";
                    return;
                }

                dq.pop_back();
                dq.push_back(0);
            }
            else {
                if (dq.size() == 0) continue;
                if (dq.back() == 0){
                    cout << "NO" << "\n";
                    return;
                }
                dq.pop_back();
                dq.push_back(1);
            }
        }
    }
    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}