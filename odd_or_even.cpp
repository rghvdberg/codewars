// Odd or Even?
// https://www.codewars.com/kata/5949481f86420f59480000e7

#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
std::string odd_or_even(const std::vector<int> &arr)
{
	auto sum = accumulate(arr.begin(),arr.end(),0);
	string result = (sum %2 == 0) ? "even" : "odd";
	return result;
}

int main() {
	cout << odd_or_even({0}) << "\n";
	cout << odd_or_even({0,1,4}) << "\n";
	cout << odd_or_even({0,-1,-5}) << "\n";
}
