#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_pisanoPeriod(long long m)
{
    long long previous = 0;
    long long current = 1;

    for(long long i = 0; i < (m*m); i++)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;

        // A Pisano Period starts with 01
        if (previous == 0 and current == 1)
            return i + 1;
    }
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

int fibonacci_sum_fast(long long n) {
    long long lPeriod = get_pisanoPeriod(10);
    // trick
    // Pisano period modulo 10 is 60
    // Sum of n Fibonacci numbers is F(n + 2) - 1
    int last_digit = get_fibonacci_last_digit_fast((n + 2) % lPeriod);
    int sum_last_digit = (last_digit != 0) ? (last_digit - 1) : 9;
    return sum_last_digit;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {

    long long lPeriod = get_pisanoPeriod(10);
    // trick
    // Pisano period modulo 10 is 60
    // Sum of n Fibonacci numbers is F(n + 2) - 1
    int first_last_digit = fibonacci_sum_fast((from - 1));
	int second_last_digit = fibonacci_sum_fast((to));

	//int sum_last_digit = (second_last_digit - first_last_digit)%10;
	if (second_last_digit >= first_last_digit) return (second_last_digit - first_last_digit);
	else return (10 - (first_last_digit - second_last_digit));
    //return sum_last_digit;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
