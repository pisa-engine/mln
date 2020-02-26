#include "mln.hpp"

#include <vector>

int main(int argc, char const *argv[])
{

    std::vector<uint32_t> input{1, 2, 3, 2, 1, 2, 1, 2, 8, 2, 9, 2};
    std::vector<uint32_t> out(input.size());

    mln<8>::encode(input.data(), input.size(), out.data());
    for (auto &&v : out) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    std::vector<uint32_t> decoded(input.size());
    mln<8>::decode(out.data(), decoded.data(), out.size());
}