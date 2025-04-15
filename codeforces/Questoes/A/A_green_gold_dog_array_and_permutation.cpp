#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++){
            int x; cin >> x;

            arr.push_back({x, i});
        }
        
        sort(arr.begin(), arr.end(), [&](pair<int, int> &x, pair<int, int> &y){
            if (x.first != y.first) return x.first > y.first;
            return x.second < y.second;
        });

        vector<pair<int, int>> perm;
        for (int i = 0; i < n; i++){
            perm.push_back({i+1, arr[i].second});
        }
        
        sort(perm.begin(), perm.end(), [&](pair<int, int> &x, pair<int, int> &y){
            return x.second < y.second;
        });

        for (int i = 0; i < n; i++){
            cout << perm[i].first << " ";
        }
        cout << "\n";
    }
}