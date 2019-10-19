#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int summand = 1;
  //write your code here
  if(n <= 2)    summands.push_back(n);
  else
  {
      do
      {
          n -= summand;
          summands.push_back(summand++);
      } while((n - summand) > summands[summands.size()-1]+1);
    summands.push_back(n);
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}