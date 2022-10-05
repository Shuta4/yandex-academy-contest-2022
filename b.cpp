#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Member {
	string c;
	int r;
	int p;
};

bool compare(Member const& a, Member const& b) {
	if (a.r == b.r) {
		return a.p < b.p;
	}
	return a.r > b.r;
}

int main(int argc, char *argv[])
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	map<string, int> maxmembers;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;

		auto commapos = input.find(',');

		maxmembers[input.substr(0, commapos)] = stoi(input.substr(commapos + 1));
	}

	int k;
	cin >> k;
	map<string, vector<Member>> members;
	for (int i = 0; i < k; i++) {
		string input;
		cin >> input;

		auto commapos1 = input.find(',');
		auto commapos2 = input.find(',', commapos1 + 1);
		auto commapos3 = input.find(',', commapos2 + 1);

		string c = input.substr(0, commapos1);
		string q = input.substr(commapos1 + 1, commapos2 - commapos1 - 1);
		int p = stoi(input.substr(commapos2 + 1, commapos3 - commapos2 - 1));
		int r = stoi(input.substr(commapos3 + 1));

		members[q].push_back({c, p, r});
	}

	vector<string> result;
	for (auto& [key, value] : members) {
		if ((int) value.size() > maxmembers[key]) {
			sort(value.begin(), value.end(), &compare);
		}
		for (int i = 0; i < min(maxmembers[key], (int) value.size()); i++) {
			result.push_back(value[i].c);
		}
	}

	sort(result.begin(), result.end());
	for (auto s : result) {
		cout << s << '\n';
	}
}
