#include <iostream>

using namespace std;

int fatorial(int x){
    if (x == 0) return 1;
    else if (x == 1) return 1;
    else return fatorial(x-1)*x;
}

int main(){
    int x;
    cin >> x;

    int result = fatorial(x);

    cout << result << "\n";
}