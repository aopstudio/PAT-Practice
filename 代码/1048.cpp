#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> numbers;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num < M) {
			numbers.push_back(num);
		}
	}
	if (numbers.size() == 0) {
		cout << "No Solution";
		return 0;
	}
	sort(numbers.begin(), numbers.end());
	int i = 0, j = numbers.size() - 1;
	while (i < j) {
		if (numbers[i] + numbers[j] == M) {
			break;
		}
		else if (numbers[i] + numbers[j] < M) {
			i++;
		}
		else {
			j--;
		}
	}
	if (i == j)
		cout << "No Solution";
	else
		cout << numbers[i] << ' ' << numbers[j];
	return 0;
}