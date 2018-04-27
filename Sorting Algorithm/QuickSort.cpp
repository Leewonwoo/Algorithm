#include <iostream>

using namespace std;

void swap(int* a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end)
{

    int left = start;
    int right = end;

    int pivot = (left + right) / 2;

    while(left < right)
    {

        while ((arr[left] < arr[pivot]) && (left < right))
        {
            left++;
        }

        while ((arr[right] >= arr[pivot]) && (left < right))
        {
            right--;
        }

        if(left < right)
        {
            swap(&arr[left], &arr[right]);
        }

    }

    swap(&arr[pivot],&arr[right]);

    return pivot;
}

void QuickSort(int arr[], int start, int end)
{
    if(start < end)
    {

       int pivot = partition(arr, start, end);
       QuickSort(arr, start, pivot - 1);
       QuickSort(arr, pivot + 1, end);
       
    }
}

int main(void)
{

    int arr[] = {7,5,2,3,1,6};

    QuickSort(arr,0,5);

    for(int i = 0; i < 6; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;

}
