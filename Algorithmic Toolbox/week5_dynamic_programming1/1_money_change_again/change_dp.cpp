#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
int get_change(int xMoney) {
  //write your code here
  int lCoins [] = {1,3,4};
  vector<int> minNumCoins(xMoney + 1, INT_MAX);
  minNumCoins[0] = 0;
  for(int m = 1; m <= xMoney; m++)
  {
      for(int j = 0; j < 3; j++)
      {
          if(m >= lCoins[j])
          {
              int lNumCoins = minNumCoins[ m - lCoins[j]] + 1;
              if(lNumCoins < minNumCoins[m])    minNumCoins[m] = lNumCoins;
          }
      }
  }
  return minNumCoins[xMoney];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
