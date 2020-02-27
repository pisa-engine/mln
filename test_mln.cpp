#include "mln.hpp"

#include <vector>

int main(int argc, char const *argv[])
{

    std::vector<uint32_t> input{1, 2, 3, 2, 1, 2, 1, 2, 8, 2, 9, 2};
    std::cout << "Input values: " << std::endl;
    for (auto &&v : input) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    std::vector<uint32_t> encoded(input.size());
    auto table = mln<8>::encode(input.data(), input.size(), encoded.data());
    std::cout << "Encoded values: " << std::endl;
    for (auto &&v : encoded) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    std::vector<uint32_t> decoded(input.size());
    mln<8>::decode(encoded.data(), decoded.data(), encoded.size(), table);
    std::cout << "Decoded values: " << std::endl;
    for (auto &&v : decoded) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}