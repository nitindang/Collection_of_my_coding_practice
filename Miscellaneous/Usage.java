// 转自http://pepcy.cf/icpc-templates/008Others/javabi.html
// 这些java功能有用
//
import java.math.BigInteger;
import java.util.Scanner;

public class Usage {
    
    // Get Catalan[n]
    // Catalan[0] = 1, Catalan[1] = 1
    public static BigInteger Catalan(BigInteger n) {
        BigInteger C_i_1 = BigInteger.ONE;
        BigInteger Four = new BigInteger("4");
        BigInteger Two = new BigInteger("2");
        BigInteger C_i = C_i_1;
        for (BigInteger i = BigInteger.ONE; i.compareTo(n) < 0; i = i.add(BigInteger.ONE)) {
            C_i = i.multiply(Four).subtract(Two).multiply(C_i_1).divide(i.add(BigInteger.ONE));
            C_i_1 = C_i;
        }
        return C_i;
    }

    public static void main(String args[]) {
        // read
        Scanner in = new Scanner(System.in);
        BigInteger a = in.nextBigInteger();

        // 3 special numbers
        a = BigInteger.ZERO;
        a = BigInteger.ONE;
        a = BigInteger.TEN;

        // convert an int to BigInteger
        BigInteger b = BigInteger.valueOf(2333);
        BigInteger p = BigInteger.valueOf(998244353);

        // convert a BigInteger to int
        int i = b.intValue();
        // convert a BigInteger to long
        long l = b.longValue();

        // operations:
        // a + b;                                BigInteger add(BigInteger b);
        a.add(b);
        // a - b;                                BigInteger subtract(BigInteger b);
        a.subtract(b);
        // a * b;                                BigInteger multiply(BigInteger b);
        a.multiply(b);
        // a / b;                                BigInteger divide(BigInteger b);
        a.divide(b);
        // a % b;                                BigInteger mod(BigInteger b);
        a.mod(b);
        // -a;                                   BigInteger negate();
        a.negate();
        // a < 0 ? -1 : (a > 0 ? 1 : 0);         int signum();
        a.signum();
        // signum(a - b);                        int compareTo(BigInteger b);
        a.compareTo(b);
        // a == b;                               boolean equals(BigInteger b);
        a.equals(b);

        // abs(a);                               BigInteger abs();
        a.abs();
        // max(a, b);                            BigInteger max(BigInteger b);
        a.max(b);
        // min(a, b);                            BigInteger min(BigInteger b);
        a.min(b);
        // gcd(a, b);                            BigInteger gcd(BigInteger b);
        a.gcd(b);
        // pow(a, i);                            BigInteger pow(int i);
        a.pow(i);

        // modPow(a, b, p);              BigInteger modPow(BigInteger b, BigInteger p);
        a.modPow(b, p);  // 求a的b次方模c
        // modPow(a, p - 2, p);                  BigInteger modInverse(BigInteger p);
        a.modInverse(p); // 求a在模p意义下的逆元
        // isPrime(a); (probability:1 - 0.5^i)  boolean isProbablePrime(int certainty);
        a.isProbablePrime(i); // 判断a是不是质数 i越高质数可能性越高耗时越高

        // a << i;                               BigInteger shiftLeft(int i);
        a.shiftLeft(i);
        // a >> i;                               BigInteger shiftRight(int i);
        a.shiftRight(i);
        // a ^ b;                                BigInteger xor(BigInteger b);
        a.xor(b);
        // a | b;                                BigInteger or(BigInteger b);
        a.or(b);
        // a & b;                                BigInteger and(BigInteger b);
        a.and(b);
        // ~a;                                   BigInteger not();
        a.not();
        // a & ~b;                               BigInteger andNot(BigInteger b);
        a.andNot(b);

        // ((a >> i) & 1) == 1;                  BigInteger testBit(int i);
        a.testBit(i);
        // a | (1 << i);                         BigInteger setBit(int i);
        a.setBit(i);
        // a & ~(1 << i);                        BigInteger clearBit(int i);
        a.clearBit(i);
        // a ^ (1 << i);                         BigInteger flipBit(int i);
        a.flipBit(i);
        // a & -a;                               BigInteger getLowerSetBit();
        a.getLowestSetBit();
        // __builtin_popcount(a);                int bitCount();
        a.bitCount();
        // ceil(log2(this < 0 ? -this : this+1)) int bitLength();
        a.bitLength();
    }
}
