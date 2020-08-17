#include <iostream>
using namespace std;

int d[1001];

int cal(int n) {
	if (d[n] > 0) return d[n];	// memorization
	
	// d[n] : 2xn ũ���� ���簢���� Ÿ�Ϸ� ä��� ����� ��
	// 2x(n-1) ���簢���� 1x2 Ÿ���� �ٿ� 2xn ���簢���� ���� �� �ִ�.
	// 2x(n-2) ���簢���� 2x1 Ÿ�� 2���� �ٿ� 2xn ���簢���� ���� �� �ִ�.
	// 2x(n-2) ���簢���� 2x2 Ÿ�� 1���� �ٿ� 2xn ���簢���� ���� �� �ִ�.
	// ���� ��ȭ���� d[n] = d[n-1] + 2*d[n-2];

	// ��� �߰��� �����÷ο찡 �߻��� �� �ֱ� ������
	// ����� ������ 10007�� ������ �ش�.
	// ��� �߿� %10007�� �ϴ� �Ͱ� �������� %10007�� �ϴ� ���� ����� ����.
	d[n] = (cal(n - 1) + (2*cal(n - 2))) % 10007;
	return d[n];
}

int main() {
	d[0] = 0;
	d[1] = 1;
	d[2] = 3;

	int n;
	cin >> n;
	cout << cal(n);
	// cout << cal(n) % 10007 ��� �ϸ�
	// n�� ū ���϶� cal(n)�� ���� �̹� ������ �����÷ο츦 ���ļ� ���� Ʋ�� ���� �Ǿ� �䵵 Ʋ���� �ȴ�.
}