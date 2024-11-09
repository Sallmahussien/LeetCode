class Solution {
public:
    long long minEnd(int n, int x) {
        string x_bits = bitset<64>(x).to_string();
        string n_bits = bitset<32>(n-1).to_string();

        int idx = 63;
        for (int i = 31; i >= 0; i--) {
            while (x_bits[idx] == '1') idx--;

            x_bits[idx--] = n_bits[i];
        }

        return stoll(x_bits, nullptr, 2);
    }
};