#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <numeric>

template <size_t Q>
class mln {
    using Table = std::array<std::array<uint8_t, Q>, Q>;

    static Table generate_table(const uint32_t *in, const size_t n)
    {
        std::array<std::array<uint32_t, Q>, Q> freq_table{};

        for (int i = 0; i < n - 1; ++i) {
            uint32_t current = in[i];
            uint32_t next = in[i + 1];
            if (current <= Q and next <= Q) {
                freq_table[current - 1][next - 1] += 1;
            }
        }
        Table t{};
        for (int i = 0; i < freq_table.size(); ++i) {
            auto freq_row = freq_table[i];
            std::array<uint8_t, Q> idx{};
            std::iota(idx.begin(), idx.end(), 1);
            std::stable_sort(idx.begin(), idx.end(), [&](size_t i1, size_t i2) {
                return freq_table[i1] > freq_table[i2];
            });
            t[i] = idx;
        }
        return t;
    }

   public:
    static void encode(const uint32_t *in, const size_t n, uint32_t *out)
    {
        auto t = generate_table(in, n);
        out[0] = in[0];
        for (int i = 1; i < n; ++i) {
            auto prev = in[i - 1];
            auto current = in[i];
            if (prev <= Q and current <= Q) {
                out[i] = t[prev - 1][current - 1];
            } else {
                out[i] = in[i];
            }
        }
    }

    static void decode(const uint32_t *in, uint32_t *out, size_t n) {}
};