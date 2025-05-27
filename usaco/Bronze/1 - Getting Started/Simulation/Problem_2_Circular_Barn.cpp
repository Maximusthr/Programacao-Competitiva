#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n; cin >> n;
    vector<int> arr(n);

    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    int dist = INF;
    for (int i = 0; i < n; i++){
        int temp = 0;
        int total = sum;
        for (int j = i; total >= 0; j++){
            if (j == i) {
                total -= arr[j];
                continue;
            }
            temp += total;
            total -= arr[j % n];
        }
        dist = min(dist, temp);
    }

    cout << dist << "\n";
}