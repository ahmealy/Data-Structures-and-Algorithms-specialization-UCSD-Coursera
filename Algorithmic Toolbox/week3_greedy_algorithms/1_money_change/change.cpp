#include <iostream>
#define COIN10 10
#define COIN5  5
#define COIN1  1

int get_change(int m) {
  //write your code here
  int coinsType[3] = {COIN10, COIN5, COIN1};
  int currentCoinType = 0;
  int numCoins = 0;
  while(m > 0)
  {
      if(m / coinsType[currentCoinType])
      {
          numCoins++;
          m -= coinsType[currentCoinType];
      }
      else  currentCoinType++;
  }
  return numCoins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
