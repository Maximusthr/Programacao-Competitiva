#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);

    ll k = 0;

    for (int i = 0; i < m; i++){
        int x; cin >> x;
        if (x == 1){
            int y, z; cin >> y >> z;
            y--;
            arr[(n+k+y)%n] = z;
        }
        else if (x == 2){
            int y; cin >> y;
            y--;
            cout << arr[(n+k+y)%n] << "\n";
        }
        else {
            int y; cin >> y;
            k += y;
        }
    }
}