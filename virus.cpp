#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long k, p, n;
    cin >> k >> p >> n;

    for (int i = 0 ; i< n; i++){
        k = (k * p) % 1000000007;
    }
    cout << k;

    return 0;
}
