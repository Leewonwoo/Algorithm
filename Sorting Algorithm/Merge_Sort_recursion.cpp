#include <vector>
#include <queue>
#include <time.h>
#include <iostream>
#include <math.h>

using namespace std;

#define N 1000

void mg(int *arr, int left ,int mid, int right)
{
    
    int l = left;
    
    int size = abs(left - right) + 1;
    int sizeL = abs(mid - left) + 1;
    int sizeR = abs(mid - right);
    
    right = mid + 1;
    
    int r = right;
    
    int *m = new int[size];
    
    int move = 0;
    
    while(move != sizeL + sizeR)
    {
        if( r >= right + sizeR || (l < left + sizeL && arr[l] < arr[r]))
        {
            m[move] = arr[l++];
            move++;
            
        }
        else if(l >= left + sizeL || (r < right + sizeR && arr[l] > arr[r]))
        {
            m[move] = arr[r++];
            move++;
        }
        
    }
    
    int j = 0;
    
    for(int i = left; i < left + sizeL;i++,j++)
    {
        arr[i] = m[j];
    }
    
    for(int i = right; i < right + sizeR;i++,j++)
    {
        arr[i] = m[j];
    }
    
}

void mSort(int *arr, int l, int r)
{
    
    if(r - l < 1)
    {
        return;
    }
    
    int mid = (l + r) / 2;
    
    mSort(arr,l,mid);
    mSort(arr,mid + 1,r);
    mg(arr, l, mid ,r);
    
}

int main(void)
{
    
    srand(time(NULL));
    
    queue<int*> q;
    
    int arr[N] = {0};
    
    for(int i = 0; i < N; i++)
    {
        
        arr[i] = rand() % N + 1;
        
        for(int j = 0; j < i;j++)
        {
            if(arr[i] == arr[j])
            {
                i--;
                break;
            }
        }
    }
    
    mSort(arr, 0, N-1);
    
    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << endl;
    }
    
    return 0;

}
