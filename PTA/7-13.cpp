#include<bits/stdc++.h>
using namespace std;

string re_co[3] = { "BW-Solid","R-Hollow","R-Cross" };
string re_ty[2] = { "Lower Shadow","Upper Shadow" };

int main() {
	double open, high, low, close;
	scanf("%lf %lf %lf %lf", &open, &high, &low, &close);
	int co, ty = 0;
	if (close < open)
		co = 0;
	else if (close > open)
		co = 1;
	else
		co = 2;
	if (low < close&&low < open)
		ty += 1;
	if (high > close&&high > open)
		ty += 2;
	cout << re_co[co];
	if (ty > 0) {
		cout << " with ";
		switch (ty) {
		case 1:
			cout << re_ty[0];
			break;
		case 2:
			cout << re_ty[1];
			break;
		case 3:
			cout << re_ty[0] << " and " << re_ty[1];
		}
		
	}
	return 0;
}