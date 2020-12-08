#include "pch.h"
#include "Matrix.h"


std::wstring temp2;
Matrix::Matrix(std::wstring str) {

	std::wstring temp;
	std::wstringstream lineJoined(str);

	size_t posn;
	std::wstring replaceFrom = L"\r\n";
	std::wstring replaceTo = L"SOMETHING";
	while (std::wstring::npos != (posn = str.find(replaceFrom)))
	{
		str.replace(posn, replaceFrom.length(), L"\n");
	}


	

	while (std::getline(lineJoined, temp)) {
		std::wstringstream spaceJoined(temp);
		temp2 = temp;
		while (std::getline(spaceJoined, temp, L' ')){
			
		}

	}
		

	

		


}

Matrix::Matrix(int** array, int width, int height) {
	Matrix::width = width;
	Matrix::height = height;
	Matrix::average = -1;

	Matrix::array = new int* [height];
	for (size_t i = 0; i < height; i++)
	{
		Matrix::array[i] = new int[width];
		std::memcpy(Matrix::array[i], array[i], width * sizeof(int));
	}
}

Matrix::~Matrix() {
	for (size_t i = 0; i < height; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}


double Matrix::GetAverage() {

	if (average > -1)
		return average;

	int sum = 0;
	int counter = 0;
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			int tmp = array[i][j];
			if (tmp > 0) {
				sum += tmp;
				counter++;
			}
		}
	}

	double result = (double)sum / counter;
	return result;
}

int Matrix::CompareAverage(Matrix* subj) {
	double thisAverage = GetAverage();
	double subjAverage = subj->GetAverage();

	if (thisAverage == subjAverage)
		return 0;

	if (thisAverage > subjAverage)
		return 1;

	return -1;
}
