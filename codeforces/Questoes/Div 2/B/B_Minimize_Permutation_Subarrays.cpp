#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n + 1);
    int pos_1 = -1, pos_2 = -1, pos_n = -1;

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        if (arr[i] == 1) pos_1 = i;
        if (arr[i] == 2) pos_2 = i;
        if (arr[i] == n) pos_n = i;
    }

    if ((pos_n > pos_1 && pos_n < pos_2) || (pos_n > pos_2 && pos_n < pos_1)){
        cout << pos_n << " " << pos_n << "\n";
    }
    else if (pos_n > pos_1 && pos_n > pos_2){
        cout << pos_n << " " << max(pos_1, pos_2) << "\n";
    }
    else if (pos_n < pos_1 && pos_n < pos_2){
        cout << pos_n << " " << min(pos_1, pos_2) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}