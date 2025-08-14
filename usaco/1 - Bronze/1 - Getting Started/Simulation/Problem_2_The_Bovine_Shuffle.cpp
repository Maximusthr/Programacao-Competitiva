#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n; cin >> n;
    
    vector<int> shuffle(n);
    for (auto &i : shuffle) cin >> i;

    vector<int> id(n);
    for (auto &i : id) cin >> i;


    vector<int> new_id = id;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            new_id[j] = id[shuffle[j] - 1];
        }
        id = new_id;
    }

    for (int i = 0; i < n; i++){
        cout << new_id[i] << "\n";
    }
}