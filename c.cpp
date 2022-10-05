#include <nlohmann/json.hpp>
#include <iostream>
#include <algorithm>
#include <vector>

using json = nlohmann::json;

struct Filters {
	std::string NAME_CONTAINS;
	int PRICE_GREATER_THAN;
	int PRICE_LESS_THAN;
	std::string DATE_BEFORE;
	std::string DATE_AFTER;
};

struct Product {
	int id;
	std::string name;
	int price;
	std::string date;
};

void to_json(json& j, const Product& p) {
	j = json{
		{"id", p.id},
		{"name", p.name},
		{"price", p.price},
		{"date", p.date}
	};
}

void from_json(const json& j, Product& p) {
	j.at("id").get_to(p.id);
	j.at("name").get_to(p.name);
	j.at("price").get_to(p.price);
	j.at("date").get_to(p.date);
}

bool compare_by_id(Product const& a, Product const& b) {
	return a.id < b.id;
}

std::string iso_date(std::string date) {
	auto day = date.substr(0, 2);
	auto month = date.substr(3, 2);
	auto year = date.substr(6);
	return year + "-" + month + "-" + day;
}

std::string lower(std::string s) {
	std::string r;
	for (auto c : s) {
		r += std::tolower(c);
	}
	return r;
}

int main(int argc, char *argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	json j;
	std::cin >> j;
	auto stocks = j.get<std::vector<Product>>();

	Filters filters;
	for (int i = 0; i < 5; i++) {
		std::string key, value;
		std::cin >> key >> value;

		if (key == "NAME_CONTAINS") {
			filters.NAME_CONTAINS = lower(value);
		} else if (key == "PRICE_GREATER_THAN") {
			filters.PRICE_GREATER_THAN = std::stoi(value);
		} else if (key == "PRICE_LESS_THAN") {
			filters.PRICE_LESS_THAN = std::stoi(value);
		} else if (key == "DATE_BEFORE") {
			filters.DATE_BEFORE = iso_date(value);
		} else if (key == "DATE_AFTER") {
			filters.DATE_AFTER = iso_date(value);
		}
	}

	std::vector<Product> result;
	for (auto& p : stocks) {

		auto name = lower(p.name);
		if (name.find(filters.NAME_CONTAINS) == std::string::npos) {
			continue;
		}

		if (p.price < filters.PRICE_GREATER_THAN || p.price > filters.PRICE_LESS_THAN) {
			continue;
		}

		auto date = iso_date(p.date);
		if (date < filters.DATE_AFTER || date > filters.DATE_BEFORE) {
			continue;
		}

		result.push_back(p);
	}

	std::sort(result.begin(), result.end(), &compare_by_id);
	json outj = result;
	std::cout << outj << '\n';

}
