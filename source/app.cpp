//------------------------------------------------------------------------------
// app.cpp
// 
// Displays a list of random numbers in forward order, then in backward order.
// Random numbers range from 1 to user's maximum n, inclusive.
//------------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <vector>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::endl;
using std::vector;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int NUM_RANDOMS = 10;
int max = 1;
vector<int> vi;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void getRange();
void makeList();
void displayForwards();
void displayBackwards();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
// updates global int max
//------------------------------------------------------------------------------
void getRange() {
	cout << "\nEnter n, your max random number (0 quits): ";
	cin >> max;
	max = abs(max);
}

//------------------------------------------------------------------------------
// fills vector with NUM_RANDOMS random numbers from 1 to max, inclusive
//------------------------------------------------------------------------------
void makeList() {

	for (int i = 0; i < NUM_RANDOMS; i++) {
		vi.push_back(rand() % max + 1);
	}
}

//------------------------------------------------------------------------------
// traverses vector in forward order to display its elements
//------------------------------------------------------------------------------
void displayForwards() {

	for (int i = 0; i < NUM_RANDOMS; i++) {
		cout << vi.at(i) << ' ';
	}
	cout << endl;
}

//------------------------------------------------------------------------------
// traverses vector in backwards order to display its elements
//------------------------------------------------------------------------------
void displayBackwards() {

	while (!vi.empty()) {

		cout << vi.back() << ' ';
		vi.pop_back();
	}
	cout << endl;
}
