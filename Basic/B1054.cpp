#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<double> legal;
	int n, cnt = 0;
	double sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		int islegal = 1, len = input.size();
		int period_cnt = 0;
		double input_d;
		if (len > 8)
			islegal = 0;
		for (int i = 0; i < len&&islegal; i++) {
			if (input[i] >= '0'&&input[i] <= '9'||input[0]=='-') {
				
			}
			else if (input[i] == '.') {
				period_cnt++;
				if (i > 5 || len - i > 3 || period_cnt > 1)
					islegal = 0;
			}
			else{
				islegal = 0;
			}
		}
		if (islegal) {
			input_d = stod(input);
			if (input_d < -1000 || input_d>1000)
				islegal = 0;
		}
		if(islegal){
			cnt++;
			sum += input_d;
		}
		else {
			printf("ERROR: %s is not a legal number\n", input.c_str());
		}
	}

	if (cnt>1) {
		printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);
	}
	else if (cnt == 1) {
		printf("The average of 1 numbers is %.2lf\n", sum);
	}
	else
		printf("The average of 0 numbers is Undefined\n");
	return 0;
}