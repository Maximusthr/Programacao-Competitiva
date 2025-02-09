#include <iostream>

using namespace std;

int main(){

    int km;
    cin >> km;

    int local = (km-5) % 8; // -5, pois (3 km distância até o acelerador e 2km para o sensor)
    
    cout << local << endl;

}