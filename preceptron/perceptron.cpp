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
void perceptronOringinal(vector<vector<double>> matrix,vector<double> &param,double learning_rate)
{
	unsigned int count = 0;
	//training samples' total_rows
	unsigned int total_rows = matrix.size();
	//initialize param
	for(size_t i = 0;i<matrix[0].size();i++)
	{
		param.push_back(0.0);
	}
	while (count != total_rows)
	{
		for (size_t rows = 0; rows < total_rows; rows++)
		{
			double sum=0;
			size_t colums;
			for(colums = 0; colums < matrix[rows].size()-1; colums++ )
			{
				sum += matrix[rows][colums]*param[colums];
			}
			if((sum + param[param.size()-1])*matrix[rows][colums] <= 0)
			{
				for(size_t param_index = 0; param_index<param.size()-1;param_index++)
				{
					param[param_index] = param[param_index] + learning_rate*matrix[rows][colums] * matrix[rows][param_index];
				}
				param[param.size()-1] = param[param.size()-1] + learning_rate*matrix[rows][colums];
				count = 0;
				//cout << param[0] << " " << param[1] <<" "<<param[param.size()-1]<<endl;
			}
			else{
				count++;
			}
		}
	}
}

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
	vector<double> param;
	double learning_rate = 1.0;
	if(readFileNumber("1.txt",numbers))
	{
		//preceptron method
		perceptronOringinal(numbers,param,learning_rate);
		cout<<"The param is : ( ";
		for(size_t i = 0; i<param.size();i++)
		{
			cout<<param[i]<<" ";
		}
		cout<<")\n";
	}else{
		cout<<"Error!"<<endl;
	}
	return 0;
}