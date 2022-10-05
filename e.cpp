#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	vector<int> opening;
	vector<int> closing;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '{') {
			opening.push_back(i + 1);
		} else if (s[i] == '}') {
			closing.push_back(i + 1);
		}
	}

	map<int, bool> used;
	for (int i = opening.size() - 1; i >= 0; i--) {
		for (int j = opening[i] - 1; j < closing.size(); j++) {

		}
	}
}
