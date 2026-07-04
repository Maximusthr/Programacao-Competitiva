#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> arr(n+1);
    int x = 5;
    vector<int> prefix(n+2);
    for (int i = n; i >= 1; i--){
        prefix[i] += (s[i-1] == 'o');
        prefix[i] += prefix[i+1];
    }

    int k = 1, j = n;
    for (int i = n; i >= 1; i--){
        if (k > j) break;
        if (prefix[i] % 2){
            arr[k] = i;
            k++;
        }
        else {
            arr[j] = i;
            j--;
        }
    }
    for (int i = 1; i <= n; i++){
        cout << arr[i] << " \n"[i == n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}