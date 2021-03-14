#include <iostream>
#include <numbers>

#define PI (3.14159265358979f)

using namespace std;

int main()
{
	__int32 k;
	cin >> k;

	__int32 x, y;
	cin >> x >> y;

	double krad = k * (PI / 180);

	double cosk = cos(krad);
	double sink = sin(krad);

	double rotx = cosk * x - sink * y;
	double roty = sink * x + cosk * y;

	printf("%.8lf %.8lf", rotx, roty);



	return 0;
}