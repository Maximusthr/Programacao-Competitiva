#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    map<int, int> num;

    for (int i = 0; i < 4; i++){
        int aux; cin >> aux;
        num[aux]++;
    }

    int sum = 0;
    for (auto [x, y] : num){
        if (y > 1) sum += y-1;
    }

    cout << sum << "\n";
}
