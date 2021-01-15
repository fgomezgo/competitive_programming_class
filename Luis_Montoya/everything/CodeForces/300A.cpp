#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;


void print_v(int size, vector <int> b) {
    
    cout << size << " ";

    for (int i = 0; i < b.size(); ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
}


int main()
{
    int input;              // Vector for reading each number of the main set
        
    int size;               // Input for vector size
    vector <int> set1;       // Set < 0
    vector <int> set2;       // Set > 0
    vector <int> set3;       // Set = 0
    
    // Get size of complete set
    cin >> size;

    // Read all numbers and add to vector
    for (int i = 0; i < size; i++) {
        cin >> input;

        if (input < 0) {
            set1.push_back(input);
        }
        else if (input > 0) {
            set2.push_back(input);
        }
        else {
            set3.push_back(input);
        }
    }
    
    // If set2 is empty, remove 2 negative from set1 and add themto set2
    if (set2.empty()) {
        set2.push_back(set1.back());
        set1.pop_back();
        set2.push_back(set1.back());
        set1.pop_back();
    }

    // Validate that first set length is not odd
    if (set1.size() % 2 != 1) {
        set3.push_back(set1.back());
        set1.pop_back();
    }

    print_v(set1.size(), set1);
    print_v(set2.size(), set2);
    print_v(set3.size(), set3);
    return 0;
   }
