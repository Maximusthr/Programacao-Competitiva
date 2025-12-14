#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> odd, even;
    for (int i = 0; i < n; i++){
        int x; cin >> x;

        if (x & 1) odd.push_back(i + 1);
        else even.push_back(i + 1);
    }

    if (odd.size() == 1) cout << odd[0] << "\n";
    else cout << even[0] << "\n";
}