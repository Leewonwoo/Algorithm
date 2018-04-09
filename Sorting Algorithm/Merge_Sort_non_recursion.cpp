#include <vector>
#include <queue>
#include <time.h>
#include <iostream>
#include <math.h>

using namespace std;

#define N 1000

void merge(int* left, int* right, int* merge)
{
    
    int sizeL = left[0];
    int sizeR = right[0];
    
    int l = 1;
    int r = 1;
    
    int move = 1;
    
    merge[0] = sizeL + sizeR;
    
    while(move != sizeL + sizeR + 1)
    {
        if( r >= right[0] + 1 || (l < left[0] + 1 && left[l] < right[r]))
        {
            merge[move] = left[l++];
            move++;
            
        }
        else if(l >= left[0] + 1 || (r < right[0] + 1 && left[l] > right[r]))
        {
            merge[move] = right[r++];
            move++;
        }
    }
    
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
    
    for(int i = 0; i < N; i++)
    {
        int *temp = new int[2];
        temp[0] = 1;
        temp[1] = arr[i];
        q.push(temp);
    }
    
    while(q.size() > 1)
    {
        
        int *left = q.front();
        q.pop();
        int *right = q.front();
        q.pop();
        int *m = new int[left[0] + right[0] + 1];
        merge(left, right, m);
        q.push(m);
        
    }
    
    for(int i = 1; i <= q.front()[0];i++)
    {
        cout << q.front()[i] << endl;
    }
    
    
    return 0;

}
