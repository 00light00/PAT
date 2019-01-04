#include<bits/stdc++.h>
using namespace std;

struct fushu {
	double real, image;
	fushu operator+(const fushu & op) {
		fushu tmp;
		tmp.real = real + op.real;
		tmp.image = image + op.image;
		return tmp;
	}

	fushu operator-(const fushu & op) {
		fushu tmp;
		tmp.real = real - op.real;
		tmp.image = image - op.image;
		return tmp;
	}

	fushu operator*(const fushu & op) {
		fushu tmp;
		tmp.real = real * op.real - image * op.image;
		tmp.image = real * op.image + image * op.real;
		return tmp;
	}

	fushu operator/(const fushu & op) {
		fushu tmp;
		tmp.real = (real * op.real + image * op.image) / (op.real*op.real + op.image*op.image);
		tmp.image = (image * op.real - real * op.image) / (op.real*op.real + op.image*op.image);
		return tmp;
	}
	void print(int flag = 0) {
		if (flag)
			printf("(");
		if (fabs(real)>=0.05 || fabs(image)>=0.05) {
			if (fabs(real) >= 0.05)
				printf("%.1f", real);
			if (image > 0.05&&fabs(real) >= 0.05)
				printf("+");
			else if (image < -0.05)
				printf("-");
			if (fabs(image) >= 0.05)
				printf("%.1fi", fabs(image));
		}
		else
			printf("0.0");
		if (flag)
			printf(")");
	}
};

int main() {
	fushu a, b;
	scanf("%lf %lf %lf %lf", &a.real, &a.image, &b.real, &b.image);
	fushu re;
	re = a + b;
	a.print(1);
	printf(" + ");
	b.print(1);
	printf(" = ");
	re.print();
	printf("\n");
	re = a - b;
	a.print(1);
	printf(" - ");
	b.print(1);
	printf(" = ");
	re.print();
	printf("\n");
	re = a * b;
	a.print(1);
	printf(" * ");
	b.print(1);
	printf(" = ");
	re.print();
	printf("\n");
	re = a / b;
	a.print(1);
	printf(" / ");
	b.print(1);
	printf(" = ");
	re.print();
	printf("\n");
	return 0;
}