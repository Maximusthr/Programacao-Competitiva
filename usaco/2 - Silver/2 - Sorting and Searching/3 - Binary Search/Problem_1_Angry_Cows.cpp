#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, k;
vector<int> arr;

bool isValid(int mid){
    int cows = 0, limite = 0;;

    bool pode = false;
    for (int i = 0; i < n; i++){
        if (pode){
            if (arr[i] > limite){
                pode = false;
            }
        }
        if (!pode){
            cows++;
            limite = arr[i] + mid*2;
            pode = true;
        }
    }

    return cows <= k;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    cin >> n >> k;

    arr.resize(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int l = 0, r = arr[n-1];
    while(l < r){
        int mid = l + (r-l)/2;

        if (isValid(mid)){
            r = mid;
        }
        else l = mid + 1;
    }

    cout << l << "\n";
}