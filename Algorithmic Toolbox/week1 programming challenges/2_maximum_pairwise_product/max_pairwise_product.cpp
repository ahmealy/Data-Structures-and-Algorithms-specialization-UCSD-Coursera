#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    int firstlargestIndex = 0;
    int secondlargestIndex = -1;

    for(int i = 1; i < n; i++)
    {
        if(numbers[i] > numbers[firstlargestIndex])     firstlargestIndex = i;
    }

    for(int j = 1; j < n; j++)
    {
        if((j != firstlargestIndex) && (numbers[j] > numbers[secondlargestIndex]))     secondlargestIndex = j;
    }
    /*for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }*/
    max_product = (long long) numbers[firstlargestIndex] * numbers[secondlargestIndex];
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
