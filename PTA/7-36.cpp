//本题要求编写程序，计算2个复数的和、差、积、商。
//
//输入格式：
//输入在一行中按照a1 b1 a2 b2的格式给出2个复数C1 = a1 + b1i和C2 = a2 + b2i的实部和虚部。题目保证C2不为0。
//
//输出格式：
//分别在4行中按照(a1 + b1i) 运算符(a2 + b2i) = 结果的格式顺序输出2个复数的和、差、积、商，数字精确到小数点后1位。如果结果的实部或者虚部为0，则不输出。如果结果为0，则输出0.0。
//
//输入样例1：
//2 3.08 - 2.04 5.06
//输出样例1：
//(2.0 + 3.1i) + (-2.0 + 5.1i) = 8.1i
//(2.0 + 3.1i) - (-2.0 + 5.1i) = 4.0 - 2.0i
//(2.0 + 3.1i) * (-2.0 + 5.1i) = -19.7 + 3.8i
//(2.0 + 3.1i) / (-2.0 + 5.1i) = 0.4 - 0.6i
//输入样例2：
//1 1 - 1 - 1.01
//输出样例2：
//(1.0 + 1.0i) + (-1.0 - 1.0i) = 0.0
//(1.0 + 1.0i) - (-1.0 - 1.0i) = 2.0 + 2.0i
//(1.0 + 1.0i) * (-1.0 - 1.0i) = -2.0i
//(1.0 + 1.0i) / (-1.0 - 1.0i) = -1.0

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