#include <stdio.h>
void main()
{
    int arr[6] = {5,4,3,2,1,0}, i = 0, j, size = 6, key;
    for (j = i + 1; j < size; j++)
    {
        key = arr[j];
        for (; i > 0; i--)
        {

            if (arr[i] > key)
            {
                arr[i + 1] = arr[i];
            }
            else
            {
                break;
            }
            
            
        }
        arr[i + 1] = key;
        i++;
    }
    for (i = 0; i < 6; i++)
    {
        printf("%d  ", arr[i]);
    }
}