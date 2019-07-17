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
	int lengths[] = { 5000, 10000, 20000, 50000 };

	vector<int> ascend_order;
	vector<int> descemd_order;
	vector<int> random_order;
	
	ascend_order.reserve();

	std::shuffle(std::begin(cards_), std::end(cards_), rng);
}
