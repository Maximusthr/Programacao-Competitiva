#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    
    vector<int> copy = arr;
    sort(copy.begin(), copy.end());
    copy.resize(unique(copy.begin(), copy.end()) - copy.begin());
    
    auto compress = [&](int x){
        return lower_bound(copy.begin(), copy.end(), x) - copy.begin();
    };

    map<int, int> real;
    for (int i = 0; i < n; i++){
        int x = compress(arr[i]);
        real[x] = arr[i];
    }

    vector<vector<int>> pos(copy.size());
    for (int i = 0; i < n; i++){
        int x = compress(arr[i]);
        pos[x].push_back(i);
    }

    int num = real[compress(copy[0])];
    int best_sum = -1;
    pair<int, int> rang = {0, -1};
    for (int i = 0; i < copy.size(); i++){
        int aux = 1;
        int sum = 1;
        pair<int, int> new_r {pos[i][0], pos[i][0]};
        int left = pos[i][0];
        for (int j = 1; j < pos[i].size(); j++){
            int elem =  - (pos[i][j] - pos[i][j-1] - 1);
            aux += elem + 1;
            if (aux > sum){
                sum = aux;
                new_r = {left, pos[i][j]};
            }
            if (aux <= 0) {
                aux = 1;
                left = pos[i][j];
            }
        }
        
        if (sum > best_sum){
            num = real[i];
            rang = new_r;
            best_sum = sum;
        }
    }

    cout << num << " " << rang.first + 1 << " " << rang.second + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}