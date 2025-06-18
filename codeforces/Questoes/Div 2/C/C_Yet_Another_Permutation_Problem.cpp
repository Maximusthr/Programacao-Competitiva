#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n; 

        // vector<int> arr(n+1);
        // iota(arr.begin(), arr.end(), 1);

        vector<bool> vis(n+1, false);

        vector<int> permutation;
        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                int temp = i;
                while(temp <= n){
                    permutation.push_back(temp);
                    vis[temp] = 1;
                    temp += temp;
                }
            }
        }

        for (auto &i : permutation) cout << i << " ";
        cout << "\n";
    }
}