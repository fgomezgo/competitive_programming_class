#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, m;
	string s;
	cin>>n>>s>>m;
	vector <string> names(m);
	vector < vector<int> > s_comp(26, vector<int>()); 
	
	
	for (int i = 0; i < m; ++i) {
		cin>>names[i];
	}
	//Compresion of S
	for (int i = 0; i < n; ++i) {
		s_comp[s[i] - 'a'].push_back(i);
	}

	for (int i = 0; i < m; ++i) {
		vector <int> name_comp(26);

		for (int j = 0; j < names[i].size(); ++j) {
			name_comp[names[i][j] - 'a']++;
		}
		int maxi = 0;
		for (int j = 0; j < 26; ++j) {
			if (name_comp[j] != 0)
				maxi = max(s_comp[j][name_comp[j] - 1], maxi);
		}
		cout << maxi + 1 << endl;	
	}
	
	return 0;
}