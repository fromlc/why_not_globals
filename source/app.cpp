#include <iostream>
#include <cstdlib>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

constexpr int NUM_RANDOMS = 10;
int max = 1;
vector<int> vi;

void getRange();
void makeList();
void displayForwards();
void displayBackwards();

int main() {

	cout << "\nDisplays a list of " << NUM_RANDOMS
		<< " numbers from 1 to n, inclusive." << endl;

	srand(time(0));

	do {

		getRange();
		if (max) {
			makeList();
			displayForwards();
			displayBackwards();
		}

	} while (max);

	cout << "\nGoodbye!\n";

	return 0;
}

void getRange() {
	cout << "\nEnter n, your max random number (0 quits): ";
	cin >> max;
	max = abs(max);
}

void makeList() {

	for (int i = 0; i < NUM_RANDOMS; i++) {
		vi.push_back(rand() % max + 1);
	}
}

void displayForwards() {

	for (int i = 0; i < NUM_RANDOMS; i++) {
		cout << vi.at(i) << ' ';
	}
	cout << endl;
}

void displayBackwards() {

	while (!vi.empty()) {

		cout << vi.back() << ' ';
		vi.pop_back();
	}
	cout << endl;
}
