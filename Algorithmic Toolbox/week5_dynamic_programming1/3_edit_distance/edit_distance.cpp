#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::min;

int edit_distance(const string &str1, const string &str2) {
    int m = str1.length();
    int n = str2.length();
  	vector<vector<int>> lEditDistanceDP(m + 1, vector<int>(n + 1));

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0)
				lEditDistanceDP[i][j] = j;

			else if (j == 0)
				lEditDistanceDP[i][j] = i;

			else if (str1[i - 1] == str2[j - 1])
				lEditDistanceDP[i][j] = lEditDistanceDP[i - 1][j - 1];

			else
				lEditDistanceDP[i][j] = 1 + min(min(lEditDistanceDP[i][j - 1],          // insert
                                                    lEditDistanceDP[i - 1][j]),         // remove
                                                    lEditDistanceDP[i - 1][j - 1]);     // replace
		}
	}

	return lEditDistanceDP[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
