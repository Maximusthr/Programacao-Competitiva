#include <iostream>

using namespace std;

int main(){
    int x, y, sum;

    cin >> x >> y;

    sum = x + y;

    if (sum % 2 == 0){
        cout << "Bino" << endl;    
    } else {
        cout << "Cino" << endl;
    }
}