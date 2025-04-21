#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int x; cin >> x;

        set<int> arr;
        for (int i = 0; i < x; i++){
            int y; cin >> y;

            arr.insert(y);
        }

        cout << arr.size() << "\n";
    }
}