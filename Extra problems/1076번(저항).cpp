#include <iostream>
#include <map>
#include <string>
#include <cmath>

int main(void)
{
	std::map<std::string, long long> r;

	r.insert(std::map<std::string, long long>::value_type("black", 0));
	r.insert(std::map<std::string, long long>::value_type("brown", 1));
	r.insert(std::map<std::string, long long>::value_type("red", 2));
	r.insert(std::map<std::string, long long>::value_type("orange", 3));
	r.insert(std::map<std::string, long long>::value_type("yellow", 4));
	r.insert(std::map<std::string, long long>::value_type("green", 5));
	r.insert(std::map<std::string, long long>::value_type("blue", 6));
	r.insert(std::map<std::string, long long>::value_type("violet", 7));
	r.insert(std::map<std::string, long long>::value_type("grey", 8));
	r.insert(std::map<std::string, long long>::value_type("white", 9));


	std::string c1, c2, c3;
	std::cin >> c1 >> c2 >> c3;

	long long res = 0;
	if (!c1.compare("black")) res = r[c2];
	else res = r[c1] * 10 + r[c2];

	long long mul = (long long)(std::pow(10, r[c3]));

	printf("%lld", res*mul);

	return 0;
}