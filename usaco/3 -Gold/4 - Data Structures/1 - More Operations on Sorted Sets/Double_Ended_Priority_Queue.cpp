#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, q; cin >> n >> q;

    multiset<int> arr;
    for (int i = 0; i < n; i++){
        int x; cin >> x;

        arr.insert(x);
    }

    while(q--){
        int x; cin >> x;
        if (x == 0){
            int y; cin >> y;
            arr.insert(y);
            continue;
        }

        if (x == 1){
            cout << *(arr.begin()) << "\n";
            arr.erase(arr.find(*(arr.begin())));
        }
        else {
            cout << *(--arr.end()) << "\n";
            arr.erase(arr.find(*(--arr.end())));
        }
    }
}