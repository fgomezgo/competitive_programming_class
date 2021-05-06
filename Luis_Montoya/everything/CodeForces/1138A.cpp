#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack <int> ones;
	stack <int> twos;
	// Save the maximum sushis for each type
	int onesMax		= 0;
	int twosMax		= 0;
	// Saver the current count of each sushi
	int onesCurrent = 0;	
	int twosCurrent = 0;

	int sushis;	// Variable for sushi count
	int sushi;	// Auxiliary variable to input sushi values
		
	// Get the number of suchis
	cin >> sushis;
	// Iterate through the sushi chain
	for (int i = 0; i < sushis; ++i) {
		// Get sushi
		cin >> sushi;
		// Get sushi type
		if (sushi == 1) {
			// Reset counter once a transition has been made from type two to type one.
			// This transistion is detectable if the current one counter is not 0
			if (onesCurrent != 0) {
				// If the current value of ones is bigger, save it
				if (onesCurrent > onesMax) {
					onesMax = onesCurrent;
				}
				// Reset sushi 1 counter
				onesCurrent = 0;
			}
			
			// Push sushi to stack
			ones.push(sushi);
			
			// If stack of other sushi is not empty, pop and increment the counter
			if (!twos.empty()) {
				twos.pop();
				twosCurrent++;
			}
			else {
				// When other sushi type is empty, if current count is higher, save it.
				if (twosCurrent > twosMax) {
					twosMax = twosCurrent;
				}
				// Reset sushi 2 counter
				twosCurrent = 0;
			}
		}
		else {
			if (twosCurrent != 0) {
				if (twosCurrent > twosMax) {
					twosMax = twosCurrent;
				}
				twosCurrent = 0;
			}
			twos.push(sushi);

			if (!ones.empty()) {
				ones.pop();
				onesCurrent++;
			}
			else {
				if (onesCurrent > onesMax) {
					onesMax = onesCurrent;
				}
				onesCurrent = 0;
			}
		}
		//cout << "onesMax: " << onesMax << " onesCurrent: " << onesCurrent  << "\t" << " twosMax: " << twosMax << " twosCurrent: " << twosCurrent << "\n";
	}


	if (twosCurrent > twosMax) {
		twosMax = twosCurrent;
	}
	if (onesCurrent > onesMax) {
		onesMax = onesCurrent;
	}



		// Get the highest sushi count, and multiply by 2 to obtain true length
	if (onesMax > twosMax) {
		cout << onesMax * 2;
	}
	else {
		cout << twosMax * 2;
	}

	return 0;
}


