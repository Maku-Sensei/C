#include <stdio.h>
#include <stdlib.h>

int randInRange(int min, int max)
{
    return min + (int)(rand() / (double)(RAND_MAX + 1) * (max - min + 1));
}

int main()
{
    int result = randInRange(1, 2);
    printf("%d\n", result);

    int myList [] = {1,2,3,4,5};
    int n = sizeof(myList)/sizeof(myList[0]);
    for (int i = 0; i < n; i++){
        
        if (i != n-1)
        {
           printf("%d,", myList[i]);
        }else{
            printf("%d", myList[i]);
        }
        
    }

}