// https://open.kattis.com/problems/tritiling
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A[] = {1,0,3,0,11,0,41,0,153,0,571,0,2131,0,7953,0,29681,0,110771,0,413403,0,1542841,0,5757961,0,21489003,0,80198051,0,299303201};


int main() {

    int n;
    while (true) {
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        printf("%lld\n", A[n]);
    }

    return 0;
}
