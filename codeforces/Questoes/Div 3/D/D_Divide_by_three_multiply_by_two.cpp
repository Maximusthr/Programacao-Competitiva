#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
set<ll> arr;
vector<ll> a;
vector<ll> index;

bool backtracking(int i){
    if (i == n){
        return true;
    }

    // n * 2
    if (arr.count(index[i - 1] * 2)){
        index[i] = index[i - 1] * 2;
        return backtracking(i + 1);
    }

    // n / 3
    if (index[i - 1] % 3 == 0){
        if (arr.count(index[i - 1]/3)){
            index[i] = index[i - 1]/3;
            return backtracking(i + 1);
        }
    }

    return false;
}

bool isValid(int i){
    index[0] = a[i];

    return backtracking(1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        arr.insert(a[i]);
    }

    index.resize(n);
    for (int i = 0; i < n; i++){
        if (isValid(i)){
            break;
        }   
    }

    for (int i = 0; i < n; i++){
        cout << index[i] << " \n"[i == n-1];
    }
}