#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int i = 0, j = 0;
    ll ans = 0;

    int pos = 0;
    for (int i = 0; i <= n; i++){
        if (arr[i] == 0) {
            pos = i;
            break;
        }
    }   
    i = pos-1;
    j = pos+1;

    while(i >= 0 || j <= n){
        int a = arr[pos];

        int x = INF;
        int y = INF;
        if (i >= 0){
            x = a + arr[i];
            if (arr[i] <= 0 && a <= 0) x = abs(a - arr[i]);
            else if (arr[i] >= 0 && a <= 0) x = abs(arr[i] - a);
            else if (arr[i] <= 0 && a >= 0) x = abs(a - arr[i]);
            else if (arr[i] >= 0 && a >= 0) x = abs(a - arr[i]);
        }
        if (j <= n){
            y = a + arr[j];
            if (arr[j] <= 0 && a <= 0) y = abs(a - arr[j]);
            else if (arr[j] >= 0 && a <= 0) y = abs(arr[j] - a);
            else if (arr[j] <= 0 && a >= 0) y = abs(a - arr[j]);
            else if (arr[j] >= 0 && a >= 0) y = abs(a - arr[j]);
        }

        if (x != INF && y != INF){
            if (x > y){
                ans += y;
                pos = j;
                j++;
            }
            else {
                ans += x;
                pos = i;
                i--;
            }
        }
        else if (x == INF){
            ans += y;
            pos = j;
            j++;
        }
        else {
            ans += x;
            pos = i;
            i--;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
