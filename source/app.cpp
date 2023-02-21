//------------------------------------------------------------------------------
// app.cpp
// 
// Displays a list of random numbers in forward order, then in backwards order.
// Random numbers range from 1 to the absolute value of user's maximum,
// inclusive.
//------------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <vector>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::vector;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int NUM_RANDOMS = 10;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
vector<int> g_vi;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void initApp();
void appLoop();
bool getMax(int&);
void makeList(int);
void displayForwards();
void displayBackwards();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	initApp();
	appLoop();

	cout << "\nGoodbye!\n";

	return 0;
}

//------------------------------------------------------------------------------
// app banner, seed random number generator
//------------------------------------------------------------------------------
void initApp() {

	cout << "\nCreates a list of " << NUM_RANDOMS
		<< " numbers from 1 to n, inclusive.\n";
	cout << "Displays the list in forward, then backwards order\n\n";

	srand((unsigned int)time(0));
}

//------------------------------------------------------------------------------
// app input and execution loop
//------------------------------------------------------------------------------
void appLoop() {

	int max = 0;
	while (getMax(max)) {
		makeList(max);
		displayForwards();
		displayBackwards();
	}
}

//------------------------------------------------------------------------------
// - stores abs value of user's maximum random number in reference param max
// - returns true if user entered a non-zero number, false otherwise
//------------------------------------------------------------------------------
bool getMax(int& max) {
	cout << "\nEnter n, your max random number (0 quits): ";

	cin >> max;
	max = abs(max);

	return max ? true : false;
}

//------------------------------------------------------------------------------
// fills vector with NUM_RANDOMS random numbers from 1 to max, inclusive
//------------------------------------------------------------------------------
void makeList(int max) {

	for (int i = 0; i < NUM_RANDOMS; i++) {
		g_vi.push_back(rand() % max + 1);
	}
}

//------------------------------------------------------------------------------
// traverses vector in forward order to display its elements
//------------------------------------------------------------------------------
void displayForwards() {

	for (int i = 0; i < NUM_RANDOMS; i++) {
		cout << g_vi.at(i) << ' ';
	}
	cout << '\n';
}

//------------------------------------------------------------------------------
// traverses vector in backwards order to display its elements
//------------------------------------------------------------------------------
void displayBackwards() {

	while (!g_vi.empty()) {

		cout << g_vi.back() << ' ';
		g_vi.pop_back();
	}
	cout << '\n';
}
