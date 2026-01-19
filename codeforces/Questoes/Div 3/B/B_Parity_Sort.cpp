#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> odd, even, pos_even, pos_odd;
    vector<int> tudo;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x & 1){
            odd.push_back(x);
            pos_odd.push_back(i);
        }
        else {
            even.push_back(x);
            pos_even.push_back(i);
        } 
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    for (int i = 0, j = 0, k = 0; k < n; k++){
        if (i < odd.size() && k == pos_odd[i]){
            tudo.push_back(odd[i++]);
        }
        else if (j < even.size() && k == pos_even[j]){
            tudo.push_back(even[j++]);
        }
    }

    if (is_sorted(tudo.begin(), tudo.end())){
        cout << "YES" << "\n";
    }
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}