#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    if (n % 2){
        cout << "Alice" << "\n";
        return;
    }

    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 0);

    for (int i = 0, j = n-1; i < j; i++, j--){        
        if ((arr[i] + arr[j]) % 4 != 3){
            cout << "Alice" << "\n";
            return;
        }
    }

    cout << "Bob" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}