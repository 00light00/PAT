#include<bits/stdc++.h>
using namespace std;

struct std_info {
	string name, birthday, genda, tel, phone;
};

int main() {
	int n;
	cin >> n;
	vector<std_info> re;
	for (int i = 0; i < n; i++) {
		std_info std;
		cin >> std.name >> std.birthday >> std.genda >> std.tel >> std.phone;
		re.push_back(std);
	}
	int len = re.size();
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int check;
		cin >> check;
		if (check < len&&check >= 0)
			cout << re[check].name << " " << re[check].tel << " " << re[check].phone << " " << re[check].genda << " " << re[check].birthday << endl;
		else
			cout << "Not Found" << endl;
	}
	return 0;
}