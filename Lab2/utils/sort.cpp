#include  "sort.h"

namespace sorting
{
    void swap(int& firstNum , int& secondNum)
    {
        int temp = secondNum;
        secondNum = firstNum;
        firstNum=temp;
    }

    int BubbleSort(int numbers[] , int size)
    {
        int sorted=0 , j=0;
        while (!sorted)
        {
            sorted = 1;
            for(int i=0; i<size-j ;i++)
            {
                if(numbers[i] > numbers[i+1])
                {
                    swap(numbers[i]  ,numbers[i+1] );
                    sorted = 0;
                }
            }
            j++;
        }
        return sorted;
    }
}