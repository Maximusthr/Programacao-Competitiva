#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> even, odd;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }

    sort(even.begin(), even.end(), greater<int>());
    sort(odd.begin(), odd.end(), greater<int>());

    ll alice = 0, bob = 0;
    for (int i = 0, j = 0, k = 0; i < n; i++){
        if (i % 2 == 0){
            // alice joga
            if (k >= odd.size() || (j < even.size() && even[j] > odd[k])){
                alice += even[j++];
            }
            else k++;
        }
        else {
            if ((j >= even.size()) || (k < odd.size() && odd[k] > even[j])){
                bob += odd[k++];
            }
            else j++;
        }
    }

    if (alice == bob){
        cout << "Tie" << "\n";
    }
    else if (alice > bob){
        cout << "Alice" << "\n";
    }
    else cout << "Bob" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}