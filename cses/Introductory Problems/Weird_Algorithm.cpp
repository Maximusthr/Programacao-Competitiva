#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    long long num; cin >> num;

    while(num != 1){
        cout << num << " ";
        if (num % 2 == 0) num /= 2;
        else num = (num * 3) + 1;
    }

    cout << num << "\n";
}
