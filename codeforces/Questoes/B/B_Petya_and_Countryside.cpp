#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;

    vector<int> arr(n);
    for(int &i : arr) cin >> i;

    int ans = 1;
    for (int i = 0; i < n; i++){
        int sum = 1;

        int aux = arr[i];
        int pos = i;

        int atual = 1001;
        for (int j = i-1; j >= 0; j--){
            if (arr[j] <= aux && arr[j] <= atual) {
                atual = min(atual, arr[j]);
                sum++;
            }
            else break;
        }

        atual = 1001;
        for (int j = i+1; j < n; j++){
            if (arr[j] <= aux && arr[j] <= atual) {
                atual = min(atual, arr[j]);
                sum++;
            }
            else break;
        }

        ans = max(ans, sum);
    }

    cout << ans << "\n";
}
