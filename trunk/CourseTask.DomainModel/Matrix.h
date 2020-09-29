#pragma once

#include <iostream>
#include <string>
#include <sstream> 

class Matrix
{
public:
	Matrix(int** array, int width, int height);
	Matrix(std::wstring str);
	~Matrix();
	double GetAverage();
	int CompareAverage(Matrix* subj);

private:
	double average;
	int** array;
	int width;
	int height;
};

