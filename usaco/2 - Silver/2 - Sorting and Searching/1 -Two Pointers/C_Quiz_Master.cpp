#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    vector<vector<int>> fatores(MAX);

    for (int i = 1; i < MAX; i++){
        for (int j = i; j < MAX; j += i){
            fatores[j].push_back(i);
        }
    }

    int t; cin >> t;

    while(t--){
        int n, m; cin >> n >> m;

        vector<int> freq(m+1);
        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        sort(arr.begin(), arr.end());

        int ans = INF;
        int topics = 0;

        for (int i = 0, j = 0; i < n; i++){
            while (j < n && topics < m){
                for (auto u : fatores[arr[j]]){
                    if (u <= m){
                        freq[u]++;
                        if (freq[u] == 1) topics++;
                    }
                }
                j++;
            }
            if (topics == m) ans = min(ans, arr[j-1] - arr[i]);

            for (auto u : fatores[arr[i]]){
                if (u <= m){
                    freq[u]--;
                    if (freq[u] == 0) topics--;
                }
            }
        }

        cout << (ans == INF ? -1 : ans) << "\n";
    }
}