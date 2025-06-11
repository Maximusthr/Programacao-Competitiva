#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, b, d; cin >> n >> b >> d;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int sum = 0;
    long long aux = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] <= b) {
            aux += arr[i];
        }
        if (aux > d) {
            sum++;
            aux = 0;
        }
    }

    cout << sum << "\n";
}
