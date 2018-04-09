#include <stdlib.h>
#include <stdio.h>

void swap(int *n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main(int argc, const char * argv[])
{
    
    int arr[7] = {7,4,5,4,1,6,3};
    
    for(int i = 1; i < 7; i++)
    {
        int k = i;
        for(int j = i - 1 ; j >= 0; j--)
        {
            if(arr[k] < arr[j])
            {
                swap(&arr[k], &arr[j]);
                k = j;
            }
        }
    }
    
    for(int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

