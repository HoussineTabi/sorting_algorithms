// Online C compiler to run C program online
#include <stdio.h>

int *merge(int *arr, int *arrL, int *arrR, int size, int left, int right)
{
    int i, j, k;
    i = j = k = 0;
    /*
    while (left-- > 0)
	    printf("arrL%d = %d\t", left,arrL[left]);
    while (right-- > 0)
            printf("arrR%d = %d\t", right, arrR[right]);
    */
    while (i < size)
    {
        if (j >= left || k >= right)
            break;
        if (arrL[j] <= arrR[k])
        {
            arr[i] = arrL[j];
            i++;
            j++;
        }
        else
        {
            arr[i] = arrR[k];
            i++;
            k++;
        }
    }
 
    while (j < left)
    {
        arr[i] = arrL[j];
        i++;
        j++;
    }
    while (k < right)
    {
        arr[i] = arrR[k];
        k++;
        i++;
    }
    return arr;
}

int main() {
    // Write C code here
    int count = 0;
    printf("Hello world\n");
    int arr[7] = {1,2,3,5,0,8,6};
    int arrL[3] = {1, 6, 8};
    int arrR[4] = {0, 2, 3, 5};
    merge(arr, arrL, arrR, 7, 3, 4);
    while (count < 7)
    { 
        printf("%d\t", arr[count]);
        count++;
        
    }
    return 0;
}
