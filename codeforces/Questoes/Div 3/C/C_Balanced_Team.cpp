#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int ans = 1;

    int aux = 1;
    int i = 0, j = 1;
    while (i < n && j < n){
        if (arr[j] - arr[i] <= 5){
            aux++;
            j++;
        }
        else {
            ans = max(ans, aux);
            aux--;
            i++;
        }
    }

    cout << max(ans, aux) << "\n";
}