<<<<<<< HEAD
/*
* perceptron.cpp
* created on 2015/11/01
* version 0.2
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

/*
*	perceptron method original style
*/
int perceptronOringinal(vector<vector<double>> matrix)
{
	int result = -2;
	unsigned int count = 0;
	//training samples' lines
	unsigned int m = matrix.size();
	//learning_rate
	double b, learning_rate;
	double w[2] = { 0, 0 };
	b = 0;
	learning_rate = 1;//学习率
	while (count != m)
	{
		for (size_t i_m = 0; i_m < m; i_m++)
		{
			if ((matrix[i_m][0] * w[0] + matrix[i_m][1] * w[1] + b)*matrix[i_m][2] <= 0)
				{
					w[0] = w[0] + learning_rate*matrix[i_m][2] * matrix[i_m][0];
					w[1] = w[1] + learning_rate*matrix[i_m][2] * matrix[i_m][1];
					b = b + learning_rate*matrix[i_m][2];
=======
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
>>>>>>> 515d8697b2d68dfd77dfe58b26aa5432a54d8948
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

<<<<<<< HEAD
/*
* writen by @egmkang
*/
void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
 
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}

/*
* read file into matrix
* @parm filename 
* @parm num_vector  
*/
bool readFileNumber(string filename,vector<vector<double>> &num_vector)
{
	const int LINE_LENGTH = 100;
	char str[LINE_LENGTH];
	ifstream fin(filename);
	if(!fin)
	{
		cout<<"Error opening "<<filename<<" for input!"<<endl;
		return false;
	}
	while(fin.getline(str,LINE_LENGTH))
	{
		vector<string> tem_string;
		vector<double> tem_vector;
		SplitString(str,tem_string," ");
		for(size_t i = 0; i<tem_string.size(); i++)
		{
			tem_vector.push_back(atof(tem_string[i].c_str()));
		}
		num_vector.push_back(tem_vector);
	}
	return true;
}

//test function
int main()
{
	//read training numbers
	vector<vector<double>> numbers;
	if(readFileNumber("1.txt",numbers))
	{
		//preceptron method
		perceptronOringinal(numbers);
	}else{
		cout<<"Error!"<<endl;
	}
=======

//main function
int main()
{
	int m = 3;
	int n = 2;;
	int matrix[3][2] = { { 3, 3 }, { 4, 3 }, { 1, 1 } };
	int c[3] = { 1, 1, -1 };
	perceptronOringinal(matrix, m, n, c);
>>>>>>> 515d8697b2d68dfd77dfe58b26aa5432a54d8948
	return 0;
}