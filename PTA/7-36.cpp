//����Ҫ���д���򣬼���2�������ĺ͡�������̡�
//
//�����ʽ��
//������һ���а���a1 b1 a2 b2�ĸ�ʽ����2������C1 = a1 + b1i��C2 = a2 + b2i��ʵ�����鲿����Ŀ��֤C2��Ϊ0��
//
//�����ʽ��
//�ֱ���4���а���(a1 + b1i) �����(a2 + b2i) = ����ĸ�ʽ˳�����2�������ĺ͡�������̣����־�ȷ��С�����1λ����������ʵ�������鲿Ϊ0���������������Ϊ0�������0.0��
//
//��������1��
//2 3.08 - 2.04 5.06
//�������1��
//(2.0 + 3.1i) + (-2.0 + 5.1i) = 8.1i
//(2.0 + 3.1i) - (-2.0 + 5.1i) = 4.0 - 2.0i
//(2.0 + 3.1i) * (-2.0 + 5.1i) = -19.7 + 3.8i
//(2.0 + 3.1i) / (-2.0 + 5.1i) = 0.4 - 0.6i
//��������2��
//1 1 - 1 - 1.01
//�������2��
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