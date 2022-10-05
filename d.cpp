#include <iostream>
#include <vector>

using namespace std;

void walk(vector<vector<char>>& scheme, int i, int j) {
	/* UP */
	if (scheme[i][j] != 'U' && scheme[i - 1][j] != '#') {
		scheme[i - 1][j] = 'D';
		walk(scheme, i - 1, j);
	}
	/* DOWN */
	if (scheme[i][j] != 'D' && scheme[i + 1][j] != '#') {
		scheme[i + 1][j] = 'U';
		walk(scheme, i + 1, j);
	}
	/* LEFT */
	if (scheme[i][j] != 'L' && scheme[i][j - 1] != '#') {
		scheme[i][j - 1] = 'R';
		walk(scheme, i, j - 1);
	}
	/* RIGHT */
	if (scheme[i][j] != 'R' && scheme[i][j + 1] != '#') {
		scheme[i][j + 1] = 'L';
		walk(scheme, i, j + 1);
	}
}

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, si, sj;
	cin >> n >> m;

	vector<vector<char>> scheme;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		scheme.push_back({});
		for (int j = 0; j < m; j++) {
			scheme[i].push_back(input[j]);

			if (input[j] == 'S') {
				si = i;
				sj = j;
			}
		}
	}

	walk(scheme, si, sj);

	for (auto& v : scheme) {
		for (auto& c : v) {
			cout << c;
		}
		cout << '\n';
	}
}
