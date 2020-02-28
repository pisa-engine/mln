# MLN

An implementation of the **Most-Likely-Next** algorithm as described in *Hao Yan, Shuai Ding, and Torsten Suel. 2009. Inverted index compression and query processing with optimized document ordering. In Proceedings of the 18th international conference on World wide web.*

## Description
MLN is used to transform numbers to smaller values. MLN uses a *QxQ* table that stores for each value which values are most likely to follow.  When applying MLN, we replace each value with its rank in the array indexed by the value of its predecessor. For values >= Q, no tranformation is applied.

## Usage

```cpp
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
```

