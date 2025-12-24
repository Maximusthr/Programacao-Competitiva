#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int query(int i, int j){
    cout << "? " << i << " " << j << endl;

    int sum; cin >> sum;

    return sum;
}

void solve(){
    int n; cin >> n;
    
    int x_y = query(1, 2);
    int y_z = query(2, 3);
    int x_z = query(1, 3);

    int X = (x_y + x_z - y_z)/2;

    vector<int> ans;
    ans.push_back(X);
    ans.push_back(x_y - ans[0]);
    ans.push_back(y_z - ans[1]);

    for (int i = 3; i < n; i++){
        int sum = query(i, i+1);
        ans.push_back(sum - ans[i-1]);
    }

    cout << "! ";
    for (auto &i : ans) cout << i << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}