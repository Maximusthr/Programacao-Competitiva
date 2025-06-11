#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int qtd; cin >> qtd;
    vector<int> arr(qtd+1);

    for (int i = 1; i < qtd+1; i++){
        cin >> arr[i];
    }
    arr.push_back(100000);

    long long i = 1, j = 1;
    long long ans = 0;
    for (; i < qtd+1;){
        if (arr[i] == arr[j]){
            j++;
        }
        else {
            ans += ((j-i)*((j-i)+1))/2;
            i = j;
        }
    }

    cout << ans << "\n";
}
