#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

// References
// https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
// https://stackoverflow.com/questions/8877448/how-do-i-reverse-a-c-vector

using namespace std;

int main() {
	
	auto rng = std::default_random_engine{};
	vector<int> lengths = { 5000, 10000, 20000, 50000 };

	vector<int> ascend_order;
	vector<int> descend_order;
	vector<int> random_order;
		
	for (int i = 0; i < lengths.size(); i++) {
		
		ascend_order.reserve(lengths[i]);
		descend_order.reserve(lengths[i]);
		random_order.reserve(lengths[i]);
	}

	vector<int> temp;
	std::shuffle(temp.begin(), temp.end(), rng);
}
