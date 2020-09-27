#pragma once

class Matrix
{
public:
	Matrix(int** array, int width, int height);
	~Matrix();
	double GetAverage();
	int CompareAverage(Matrix* subj);

private:
	double average;
	int** array;
	int width;
	int height;
};

