#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    
    string alf = "abcdefghijklmnopqrstuvwxyz";

    vector<string> ans;
    string aux;
    for (int i = 0; i < 52; i++) aux.push_back('a');
    ans.push_back(aux);

    for (int i = 0; i < n; i++){
        string a, b;

        a = ans.back();
        
        for (int j = 0; j < arr[i]; j++){
            b.push_back(a[j]);
        }

        for (int j = b.size(); j < 52; j++){
            for (int k = 0; k < 26; k++){
                if (alf[k] != a[j]){
                    b.push_back(alf[k]);
                    break;
                }
            }
        }

        ans.push_back(b);
    }

    for (auto &i : ans) cout << i << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}