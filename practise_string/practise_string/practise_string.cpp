#include <iostream>
#include<string>
#include <algorithm>
bool IsNumber(const std::string& s) {
	for (size_t i = 0; i < s.size(); ++i) {
		if (!isdigit(s[i])) {
			return false;
		}
	}
	return true;
}
std::string Sum(const std::string& s1, const std::string& s2) {
	std::string s3;
	bool carry = false;
	for (int i = s1.size() - 1; i >= 0; --i) {
		int n1 = static_cast<int>(s1[i]) - 48;
		int n2 = static_cast<int>(s2[i]) - 48;
		int res = n1 + n2 + carry;
		carry = (res > 9);
		s3 += std::to_string(res % 10);//нужно перевернуть строку в конце 
	}
	if (carry) s3 += '1';
	std::reverse(s3.begin(), s3.end());
	return s3;
}
int main() {
	std::string s1, s2;
	std::cin >> s1 >> s2;
	if (IsNumber(s1) && IsNumber(s2)) {
		std::cout << Sum(s1, s2);
	}
	else { 
		std::cerr << "wrong input"; 
	}
	return 0;
}