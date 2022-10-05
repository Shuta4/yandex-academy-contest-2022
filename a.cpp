#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a, b;
	cin >> a;
	cin >> b;
	int n = a.length();

	map<char, int> charcount;
	for (const auto& c : a) {
		charcount[c]++;
	}

	string result = "";
	for (int i = 0; i < n; i++) {
		result += 'I';
		if (a[i] == b[i]) {
			result[i] = 'P';
			charcount[a[i]]--;
		}
	}

	for (int i = 0; i < n; i++) {
		if (result[i] == 'I' && charcount[b[i]] > 0) {
			result[i] = 'S';
			charcount[b[i]]--;
		}
	}

	cout << result << '\n';

}
