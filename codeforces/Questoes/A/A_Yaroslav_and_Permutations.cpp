#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    map<int, int> val;

    for (int i = 0; i < t; i++){
        int x; cin >> x;
        val[x]++;
    }

    int elem = 0;
    for (auto[x, y] : val){
        elem = max(elem, y);
    }

    if (t - elem >= elem-1) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}
