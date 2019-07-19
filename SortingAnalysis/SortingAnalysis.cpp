#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// References
// https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
// https://stackoverflow.com/questions/8877448/how-do-i-reverse-a-c-vector
// https://stackoverflow.com/questions/421573/best-way-to-extract-a-subvector-from-a-vector
// https://stackoverflow.com/questions/12231166/timing-algorithm-clock-vs-time-in-c
// https://stackoverflow.com/questions/15092504/how-to-time-a-function-in-milliseconds-without-boosttimer

using namespace std;
using namespace std::chrono;

// Prototypes
void BubbleSort(vector<int>& list);
void swap(int* a, int* b);
vector<int> MergeSort(vector<int> list);
vector<int> Merge(vector<int>& leftSub, vector<int>& rightSub);
void QuickSort(vector<int>& list, int lowIndex, int highIndex);
int Partition(vector<int>& list, int lowIndex, int highIndex);
void InsertionSort(vector<int>& list);

int main() {
	
	auto rng = std::default_random_engine{};
	vector<int> lengths = { 50000, 10000, 20000, 50000 };

	vector<int> ascend_order;
	vector<int> descend_order;
	vector<int> random_order;
		
	for (unsigned int i = 0; i < lengths.size(); i++) {

		ascend_order.clear();
		descend_order.clear();
		random_order.clear();

		// Creating the lists
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

		// Timing sorting algorithms
		auto start = std::chrono::steady_clock::now();
		InsertionSort(random_order);
		auto end = std::chrono::steady_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);

		std::cout << std::endl << duration.count() << " miliseconds" << std::endl;
		cout << endl;


		return 0;
	}

}

void BubbleSort(vector<int>& list) {

	bool swapped;
	int shrink = 1;
	do {
		swapped = false;		
		for(unsigned int i = 0; i < list.size() - shrink; i++)
			if (list[i] > list[i + 1]) {
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		shrink++;
	} while (swapped);

}

// Helper function
void swap(int* a, int* b) {
	int* temp = a;
	a = b;
	b = temp;
}

vector<int> MergeSort(vector<int> list) {
	if (list.size() == 1) {
		vector<int> single(1,list[0]);
		return single;
	}

	vector<int> leftSub(list.begin(), list.begin() + (list.size() / 2));  
	vector<int> rightSub(list.begin() + (list.size() / 2), list.end());
	leftSub = MergeSort(leftSub);
	rightSub = MergeSort(rightSub);

	return Merge(leftSub, rightSub);
}

// Helper function for merge sort
vector<int> Merge(vector<int>& listA, vector<int>& listB) {
	
	vector<int> sorted;
	sorted.reserve(listA.size() + listB.size());

	while (!listA.empty() && !listB.empty()) {
		if (listA[0] > listB[0]) {
			sorted.push_back(*listB.begin());
			listB.erase(listB.begin());
		}
		else {
			sorted.push_back(*listA.begin());
			listA.erase(listA.begin());
		}
	}

	// Either vector is now empty
	while (!listA.empty()) {
		sorted.push_back(*listA.begin());
		listA.erase(listA.begin());
	}
	while (!listB.empty()) {
		sorted.push_back(*listB.begin());
		listB.erase(listB.begin());
	}

	return sorted;
}

void InsertionSort(vector<int>& list) {
	for (unsigned int i = 0; i < list.size(); i++) {
		int j = i;
		while (j > 0 && list[j - 1] > list[j]) {
			swap(list[j], list[j - 1]);
			j--;
		}
	}
}

// Cries in stack overflow
void QuickSort(vector<int>& list, int lowIndex, int highIndex) {
	
	if (lowIndex < highIndex) {
		int pivotIndex = Partition(list, lowIndex, highIndex);
		if (pivotIndex - lowIndex < highIndex - pivotIndex) {
			QuickSort(list, lowIndex, pivotIndex);
			QuickSort(list, pivotIndex + 1, highIndex);
		}
		else {
			QuickSort(list, pivotIndex + 1, highIndex);
			QuickSort(list, lowIndex, pivotIndex);
		}
	}
}

int Partition(vector<int>& list, int lowIndex, int highIndex) {
	int pivot = list[lowIndex];
	int leftFence = lowIndex;

	for (int i = lowIndex + 1; i < highIndex; i++) {
		if (list[i] < pivot) {
			swap(list[i], list[leftFence]);
			leftFence++;
		}
	}
	swap(pivot, list[leftFence]);
	return leftFence;
}

