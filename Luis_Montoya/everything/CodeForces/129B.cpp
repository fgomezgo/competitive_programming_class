#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

void print_2d_v(vector <vector <int>> input) {
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input.size(); j++)
		{
			cout << input[i][j] << " ";
		}
		cout << endl;
	}
}

void print_v(vector <int> b) {

	for (int i = 0; i < b.size(); ++i) {
		cout << b[i] << " ";
	}
	cout << endl;
}





int main() {
	// n: number of students, 
	// m: number of laces
	int n, m;
	// Row and column auxiliary variables for putting everithing in a matrix
	int n_in, m_in;

	// Get students and laces
	cin >> n >> m;

	//  2D vector for acquiring data and saving the relationships
	vector<vector<int>> data(n, vector<int>(n));
	// Vector  to keep the count of relationships between students
	vector <int> count;

	// Save relationships to the matrix
	for (int i = 0; i < m; i++) {
		cin >> n_in >> m_in;
		data[n_in - 1][m_in - 1] = 1;
	}

	bool ones_detected = true;
	int groups = 0;

	while (ones_detected) {
		ones_detected = false;
		// Clear relations
		count.clear();

		// Count the relations
		for (int i = 0; i < n; i++) {
			// Counter for matrix
			int counter = 0;

			for (int j = 0; j < n; j++) {
				counter += data[i][j];
			}

			for (int k = 0; k < n; k++) {
				counter += data[k][i];
			}
			// Save number of relationships to a vector
			count.push_back(counter);
			// If single relations are detected, repeat
			if (counter == 1) {
				ones_detected = true;
			}
		}

		// If single links are present, remove them
		if (ones_detected) {
			for (int i = 0; i < n; i++) {
				if (count[i] == 1) {
					for (int j = 0; j < n; j++) {
						data[i][j] = 0;
					}

					for (int k = 0; k < n; k++) {
						data[k][i] = 0;
					}
				}
			}
			// And count the groups
			groups++;
		}
	}

	cout << groups << endl;
}