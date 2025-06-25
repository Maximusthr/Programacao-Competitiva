#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    if (is_sorted(arr.begin(), arr.end())){
        cout << 0 << "\n";
        return;
    }

    struct pontos{
        int x, y, z;
    };

    vector<pontos> change;
    for (int i = 0; i < n - 1; i++){
        int min_pos = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min_pos]){
                min_pos = j;
            }
        }

        if (min_pos > i){
            change.push_back({i, min_pos});
            int troca = arr[min_pos];
            for (int j = min_pos; j > i; j--){
                arr[j] = arr[j-1];
            }
            arr[i] = troca;
        }
    }

    cout << change.size() << "\n";
    for (int i = 0; i < change.size(); i++){
        cout << change[i].x + 1 << " " << change[i].y + 1 << " " << change[i].y - change[i].x << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}