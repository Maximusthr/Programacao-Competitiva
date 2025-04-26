#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, x; cin >> n >> x;

        vector<int> ans(n, x);

        int sum = 0;
        for (int i = 0; i < n; i++){
            if ((i & x) != i){
                sum = x;
                break;
            }
            ans[i] = i;
            sum |= i;
        }

        if (sum != x) ans.back() = x;

        for (auto &i : ans) cout << i << " ";
        cout << "\n";
    }
}
