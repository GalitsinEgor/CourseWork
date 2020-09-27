// CourseTask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include "../CourseTask.DomainModel/Matrix.h"

const int firstWidth = 5;
const int firstHeight = 4;

/*const int firstWidth = 2;
const int firstHeight = 2;*/

const int secondWidth = 4;
const int secondHeight = 6;

/*const int secondWidth = 2;
const int secondHeight = 2;*/

int** fillArray(int width, int height) {

    int** arr = new int*[height];
    for (size_t i = 0; i < height; i++)
    {
        std::string str;
        std::cout << "Enter " << width << " values divided by white space" << std::endl;
        std::getline(std::cin, str);


        arr[i] = new int[width] {0};
        std::stringstream ss(str);
        int temp;
        int lineId = 0;
        while (ss >> temp && lineId < width) {
            arr[i][lineId++] = temp;
        }
    }

    return arr;
}

/// <summary>
/// 5.	Если среднее арифметическое SA положительных элементов мат¬рицы A (5×4) 
/// больше среднего арифметического SB положительных элементов матрицы B (4×6),
///  найти сумму SA + SB, иначе найти раз¬ность SA –  SB.
/// </summary>
/// <returns></returns>
int main()
{
    int** array1 = fillArray(firstWidth, firstHeight);
    Matrix* first = new Matrix(array1, firstWidth, firstHeight);
    int** array2 = fillArray(secondWidth, secondHeight);
    Matrix* second = new Matrix(array2, secondWidth, secondHeight);

    double res = 0;
    if (first->CompareAverage(second) > 0) {
        res = first->GetAverage() + second->GetAverage();
    }
    else {
        res = first->GetAverage() - second->GetAverage();
    }

    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "Result: " << res << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
