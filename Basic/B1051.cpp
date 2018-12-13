#include <iostream>
#include <cmath>
using namespace std;

const double delta = 0.005;
struct fushu {
	double R, P;
	fushu(double r = 0, double p = 0) :R(r), P(p) {};
	fushu operator*(fushu plus) {
		return fushu(R*plus.R, P + plus.P);
	}
};

int main() {
	fushu a1, a2, re;
	scanf("%lf %lf %lf %lf", &a1.R, &a1.P, &a2.R, &a2.P);
	re = a1 * a2;
	double real, image;
	real = re.R*cos(re.P);
	image = re.R*sin(re.P);
	if (fabs(real) < delta)
		real = 0;
	if (fabs(image) < delta)
		image = 0;
	if (image < -1*delta)
		printf("%.2f%.2fi\n", real, image);
	else
		printf("%.2f+%.2fi\n", real, image);
	return 0;
}