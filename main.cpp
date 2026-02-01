#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>

int main(){
    std::cout << "<3" << std::endl;
    std::array<int, 5> arr;
    std::sort(arr.begin(), arr.end(), std::less{});
    auto a = new int[10];
    return 0;
}