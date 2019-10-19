#include <iostream>
#include <vector>
using namespace std;
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if(n <= 1)  return n;
    vector<int> lFib(n+1);
    lFib[0] = 0;
    lFib[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        lFib[i] =  (lFib[i - 1] +  lFib[i - 2])%10;
    }

    return lFib[n]%10;
}

int fibonacci_sum_squares_fast(long long n) {
    //long long lPeriod = get_pisanoPeriod(10);  /// =60
    // trick
    // Pisano period modulo 10 is 60
    // Sum of n Fibonacci numbers is F(n + 2) - 1
    int vertical_side = get_fibonacci_last_digit_fast(n % 60);
    int horizontal_side = get_fibonacci_last_digit_fast((n + 1) % 60);
    return (vertical_side * horizontal_side) % 10;
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
