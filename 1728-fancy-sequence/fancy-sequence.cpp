class Fancy {
public:
    long long mod = 1e9 + 7;
    vector<long long> seq;
    long long mul = 1;
    long long add = 0;

    long long modPow(long long a, long long b) {
        long long res = 1;
        a %= mod;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return modPow(x, mod - 2);
    }

    Fancy() {
        
    }
    
    void append(int val) {
        long long normalized = ((val - add + mod) % mod) * modInverse(mul) % mod;
        seq.push_back(normalized);
    }
    
    void addAll(int inc) {
        add = (add + inc) % mod;
    }
    
    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        return (seq[idx] * mul % mod + add) % mod;
    }
};