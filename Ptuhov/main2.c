#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sampler.h"

const int max = 200;

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int x[max], int n)
{
    int left[50], right[50], sp, i, j, mid, pivot;

    left[0] = 0;
    right[0] = n - 1;
    sp = 0;
	
	SAMPLE;
    while (sp > -1)
    {
		SAMPLE;
        if (left[sp] >= right[sp])
		{
			SAMPLE;
            --sp;
			SAMPLE;
		}
        else
        {
			SAMPLE;
            i = left[sp];
            j = right[sp];
            pivot = x[j];
            mid = (i + j) / 2;
			
			SAMPLE;
            if (j - i > 5) {
				SAMPLE;
                if ((x[mid] < pivot && x[mid] > x[i]) ||
                    (x[mid] > pivot && x[mid] < x[i]))
                    swap(&(x[mid]), &(x[j]));

                else if ((x[i] < x[mid] && x[i] > pivot) ||
                         (x[i] > x[mid] && x[i] < pivot))
                    swap(&(x[i]), &(x[j]));
				SAMPLE;
            }
			SAMPLE;

            pivot = x[j];
			SAMPLE;
            while (i < j) {
				SAMPLE;
                while (x[i] < pivot)
                    ++i;
                --j;
                while (i < j && pivot < x[j])
                    --j;
                if (i < j)
                    swap(&(x[i]), &(x[j]));
				SAMPLE;
            }
			SAMPLE;

            j = right[sp];
            swap(&(x[i]), &(x[j]));
			SAMPLE;
            if (i - left[sp] >= right[sp] - i) {
				SAMPLE;
                left[sp + 1] = left[sp];
                right[sp + 1] = i - 1;
                left[sp] = i + 1;
				SAMPLE;
            }
            else
            {
				SAMPLE;
                left[sp + 1] = i + 1;
                right[sp + 1] = right[sp];
                right[sp] = i - 1;
				SAMPLE;
            }
			SAMPLE;
            ++sp;
        }
		SAMPLE;
    }
	SAMPLE;
}

int main(int pargc, char **argv) {
	sampler_init(&pargc, argv);
	
    int n = max;
    int x[max];
    srand(time(NULL));

    for (int i = 0; i < n; ++i)
        x[i] = rand() % 100;

    sort(x, n);


   // for (int i = 0; i < n; ++i)
   //     printf("%d ", x[i]);

    return 0;
}