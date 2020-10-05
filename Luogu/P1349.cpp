#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template<typename T, int size>
struct Mat {
    T A[size][size]{0};
    T mod;

    explicit Mat(const T &mod) : mod(mod) {}

    Mat operator+(const Mat &lhs) const {
        Mat res;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                res.A[i][j] = (A[i][j] + lhs.A[i][j]) % mod;
            }
        }
        return res;
    }

    Mat operator-(const Mat &lhs) const {
        Mat res;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                res.A[i][j] = (A[i][j] - lhs.A[i][j]) % mod;
            }
        }
        return res;
    }

    Mat operator*(const Mat &lhs) const {
        Mat res(mod);
        T temp;
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size; ++k) {
                temp = A[i][k];
                for (int j = 0; j < size; ++j) {
                    res.A[i][j] = (res.A[i][j] + lhs.A[k][j] * temp) % mod;
                }
            }
        }
        return res;
    }

    Mat operator^(T n) const {
        Mat res(mod), base(mod);
        for (int i = 0; i < size; ++i) {
            res.A[i][i] = 1;
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                base.A[i][j] = A[i][j] % mod;
            }
        }
        while (n) {
            if (n & 1) {
                res = res * base;
            }
            base = base * base;
            n >>= 1;
        }
        return res;
    }
};

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
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
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

int main() {

    ll a_1, a_2, p, q, n, mod;
    IO::read(p, q, a_1, a_2, n, mod);

    if (n == 1) {
        IO::writeln(a_1 % mod);
    } else if (n == 2) {
        IO::writeln(a_2 % mod);
    } else {

        Mat<ll, 2> mat(mod);
        mat.A[0][0] = p;
        mat.A[0][1] = q;
        mat.A[1][0] = 1;
        mat.A[1][1] = 0;
        mat = mat ^ (n - 2);

        Mat<ll, 2> result(mod);
        result.A[0][0] = a_2;
        result.A[0][1] = 1;
        result.A[1][0] = a_1;
        result.A[1][1] = 1;

        result = mat * result;
        IO::writeln(result.A[0][0]);
    }
    return 0;
}