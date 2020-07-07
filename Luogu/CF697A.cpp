#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

int main() {

    ll t, s, x;
    IO::read(t, s, x);
    ll k = (x - t) / s;
    if (t + k * s == x && k >= 0) {
        fputs("YES\n", stdout);
        return 0;
    }
    k = (x - 1 - t) / s;
    if (t + k * s + 1 == x && k > 0) {
        fputs("YES\n", stdout);
        return 0;
    }
    fputs("NO\n", stdout);

    return 0;
}
