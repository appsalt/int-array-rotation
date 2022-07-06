// int array rotation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void arrayRotator(int* intArr, int intArr_N, int& rotation)
{
    int* tmp = new int[intArr_N];
    if (rotation < 0)
    {
        // we cut the front and shift to end
        rotation = -rotation;
        for (int i{ 0 }; i < intArr_N; ++i)
        {
            if (i + rotation < intArr_N)
            {
                tmp[i] = intArr[(i + rotation)];
            }
            else {
                tmp[i] = intArr[(i + rotation) % intArr_N];
            }
        }
            
    }
    else if  (rotation == 0)
    {
        return ;
    }
    else
    {
        // we cut the end and shift to front
        for (int i{ 0 }; i < intArr_N; ++i)
        {
            if ((intArr_N - rotation) + i < intArr_N)
            {
                tmp[i] = intArr[(intArr_N - rotation) + i];
            }
            else {
                tmp[i] = intArr[((intArr_N - rotation) + i) % intArr_N];
            }
        }
    }
    for (int i{ 0 }; i < intArr_N; ++i)
    {
        intArr[i] = tmp[i];
    }
    delete[] tmp;
}

void showIntArr(int* intArr, int& intArr_N)
{
    std::cout << std::endl;
    for (int i{ 0 }; i < intArr_N; ++i)
    {
        std::cout << intArr[i];
        std::cout << " ";
    }
    std::cout << std::endl;
}

void fillIntArr_linear(int* intArr, int& intArr_N, int slope)
{
    for (int i{ 0 }; i < intArr_N; i += slope)
    {
        intArr[i] = i;
    }
}


int main()
{
    int N{ 20 };
    int* intArr = new int[N] {};
    int N_shift{ 5 };

    fillIntArr_linear(intArr, N, 1);

    showIntArr(intArr, N);

    arrayRotator(intArr, N, N_shift);

    showIntArr(intArr, N);

    N_shift = -N_shift;

    arrayRotator(intArr, N, N_shift);

    showIntArr(intArr, N);
}