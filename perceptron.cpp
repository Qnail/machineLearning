#include <iostream>

using namespace std;


int perceptronOringinal(int matrix[][2], int m, int n, int c[3])
{
	int result = -2;
	int count = 0;
	double b, lr;
	double w[2] = { 0, 0 };
	b = 0;
	lr = 1;//学习率

	while (count != m)
	{
		for (int i_m = 0; i_m < m; i_m++)
		{
			if ((matrix[i_m][0] * w[0] + matrix[i_m][1] * w[1] + b)*c[i_m] <= 0)
				{
					w[0] = w[0] + lr*c[i_m] * matrix[i_m][0];
					w[1] = w[1] + lr*c[i_m] * matrix[i_m][1];
					b = b + lr*c[i_m];
					count = 0;
					cout << w[0] << " === " << w[1] << endl;
				}
				else{
					count++;
				}
		}
	}
	



	return result;
}


//main function
int main()
{
	int m = 3;
	int n = 2;;
	int matrix[3][2] = { { 3, 3 }, { 4, 3 }, { 1, 1 } };
	int c[3] = { 1, 1, -1 };
	perceptronOringinal(matrix, m, n, c);
	return 0;
}