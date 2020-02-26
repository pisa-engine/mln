#include "mln.hpp"

#include <vector>

int main(int argc, char const *argv[])
{

    std::vector<uint32_t> input{1, 2,3,4,5};
    std::vector<uint8_t> out(4* input.size());

    size_t n;
    mln::encode(input.data(), input.size(), out.data(), n);

    std::vector<uint32_t> decoded(input.size());
    size_t n_decoded;
    mln::decode(out.data(), decoded.data(), out.size(), n_decoded);

}