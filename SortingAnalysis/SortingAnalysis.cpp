#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

// References
// https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
// https://stackoverflow.com/questions/8877448/how-do-i-reverse-a-c-vector
// https://stackoverflow.com/questions/12231166/timing-algorithm-clock-vs-time-in-c

using namespace std;

void BubbleSort(vector<int>& list);
void MergeSort(vector<int>& list);
void QuickSort(vector<int>& list);

int main() {
	
	auto rng = std::default_random_engine{};
	vector<int> lengths = { 5000, 10000, 20000, 50000 };

	vector<int> ascend_order;
	vector<int> descend_order;
	vector<int> random_order;
		
	for (int i = 0; i < lengths.size(); i++) {

		ascend_order.clear();
		descend_order.clear();
		random_order.clear();

		ascend_order.reserve(lengths[i]);
		descend_order.reserve(lengths[i]);
		random_order.reserve(lengths[i]);

		for (int j = 0; j < lengths[i]; j++) {
			ascend_order.push_back(j);
		}
		random_order = ascend_order;
		std::shuffle(random_order.begin(), random_order.end(), rng);
		descend_order = ascend_order;
		std::reverse(descend_order.begin(), descend_order.end());

		// DEBUG FIXME
		//for (auto it = random_order.begin(); it != random_order.end(); it++) {
		//	cout << *it << " ";
		//}

		return 0;
	}

}
