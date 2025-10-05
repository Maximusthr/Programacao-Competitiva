#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int stop = n;
    for (int i = 0; i < n; i++){
        if (arr[i] != i) {
            stop = i;
            break;
        }
    }

    int mov = 0;
    while(mov < 2 * n + 1){
        cout << stop << endl;
        mov++;

        int x; cin >> x;
        mov++;
        
        if (x == -1) break;
        
        stop = x;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}