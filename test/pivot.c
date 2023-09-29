// Online C compiler to run C program online
#include <stdio.h>
void quickSort(int *A, int size)
{
    int pivoIndex = size - 1;
    int i, j, c, swap = 0;
    for (i = 0; i < size; i++)
    {
        char *mark = "hi";
        if ((A[i] > A[pivoIndex] && i < pivoIndex) || (A[i] < A[pivoIndex] && i > pivoIndex))
        {
            swap++;
            if (swap < size / 2)
            {
                
                c = A[i];
                A[i] = A[pivoIndex];
                A[pivoIndex] = c;
                pivoIndex = i;
            }
            else
            {
                c = A[i];
                j =  i - 1;
                while (j >= pivoIndex)
                {
                    A[j + 1] = A[j];
                    j--;
                }
                A[pivoIndex] = c;
                pivoIndex++;
                
                
            }
            
        }
        j = 0;
        while (j < size)
            printf("%d\t", A[j++]);
        printf("\n");
    }
    
}
int main() {
    // Write C code here
    int A[] = {7, 2, 1, 6, 8};
    int size = sizeof(A) / sizeof(A[0]);
    quickSort(A, size);

    return 0;
}
