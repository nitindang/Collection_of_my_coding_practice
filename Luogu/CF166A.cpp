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

    int n, k;
    IO::read(n, k);
    vector<pair<int, int> > A(n);
    for (auto &i : A) {
        IO::read(i.first, i.second);
    }
    sort(A.begin(), A.end(),
         [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
             if (lhs.first == rhs.first) {
                 return (lhs.second < rhs.second);
             }
             return (lhs.first > rhs.first);
         });
    auto p = A.at(k - 1);
    IO::writeln(count_if(A.begin(), A.end(), [&](const pair<int, int> &obj) {
        return obj == p;
    }));

    return 0;
}