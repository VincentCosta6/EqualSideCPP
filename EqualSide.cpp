#include <iostream>
#include <vector>

using std::vector;

using std::cout;
using std::endl;

int equalSides(const vector<int>& arr) {
	const int size = arr.size();

	if (size == 0) return -1;

	vector<int> leftSum(size);
	leftSum[0] = arr[0];

	vector<int> rightSum(size);
	rightSum[size - 1] = arr[size - 1];

	for (int i = 1; i < size - 1; i++) {
		int rightIndex = size - 1 - i;

		leftSum[i] = leftSum[i - 1] + arr[i];
		rightSum[rightIndex] = rightSum[rightIndex + 1] + arr[rightIndex];

		if (leftSum[i] == rightSum[i]) return i;
		if (rightSum[rightIndex] == leftSum[rightIndex]) return rightIndex;
	}

	return -1;
}

int main()
{
	vector<int> arr1 = { 2, 1, 5, 9, 8 };
	vector<int> arr2 = { 1, 1, 1, 4, 2, 1 };
	vector<int> arr3 = { };

	cout << equalSides(arr1) << endl;
	cout << equalSides(arr2) << endl;
	cout << equalSides(arr3) << endl;
}

