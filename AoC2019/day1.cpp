// AoC2019.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <string>

int get_fuel_recursive(int m)
{
	int new_fuel = (int)floor(m / 3.0f) - 2;
	if (new_fuel < 1)
		return 0;
	else
		return (new_fuel + get_fuel_recursive(new_fuel));
}

int main()
{
	std::vector<int> inputs;
	std::ifstream fs("day1.txt");
	std::copy(std::istream_iterator<int>(fs), std::istream_iterator<int>(), std::back_inserter(inputs));
	std::cout << "Part 1: " << std::accumulate(inputs.begin(), inputs.end(), 0, [](int acc, int mass) { return acc + mass / 3 - 2; }) << std::endl;
	std::cout << "Part 2: " << std::accumulate(inputs.begin(), inputs.end(), 0, [](int acc, int mass) { return acc + get_fuel_recursive(mass); }) << std::endl;
}
