#include "search.h"

namespace searching
{
    int findNumber(const int numbers[] , int size , int target){
        int value =-1;
        for(int i=0;i<size;i++)
        {
            if(numbers[i]==target)
                value=i;
        }
        return  value;
    }
}

