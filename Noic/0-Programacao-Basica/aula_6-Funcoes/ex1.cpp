#include <bits/stdc++.h>

using namespace std;

int mod(int x){
    if (x < 0) x *= -1;
    return x;
}

int main(){
    int num; cin >> num;
    cout << mod(num) << '\n';
}