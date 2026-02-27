#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    vector<int> idx;
    int j = n-1;

    string ans;

    while (j >= 0){
        while(j >= 0 && s[j] == '1'){
            ans.push_back(s[j]);
            j--;
        }
        
        while(j >= 0 && s[j] == '0'){
            idx.push_back(0);
            j--;
        }

        while (s[j] == '1' && idx.size() > 1){
            idx.pop_back();
        }

        while(j >= 0 && s[j] == '1' && idx.size() == 1){
            j--;
        }
    }

    for (int i = 0; i <= idx.size(); i++){
        if (i == idx.size()){
            cout << ans << "\n";
            break;
        }
        cout << '0';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}