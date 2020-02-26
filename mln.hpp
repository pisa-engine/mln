#include <cstdint>
#include <cstddef>

class mln {
public:
    static void encode(const uint32_t *in, const size_t length, uint8_t *out, size_t &nvalue) {}

    static void decode(const uint8_t *in, uint32_t *out, size_t len, size_t &n) {}
};