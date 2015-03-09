/**
 * Simultaneously find minimum and maximum elements of array.
 *
 * Input:
 *   Array of numbers.
 *
 * Output:
 *   Minimum and maximum elements.
 *
 * Note:
 *   Count of comparison operations should be less than 2 * (n - 1).
 *   See T. Cormen, C. Leiserson, R. Rivest, C. Stein -
 *          Introduction to Algothithms, 2nd edition, Part II, Chapter 9.1.
 *
 * Author:
 *   Alexey Rybakov
 */

#include <iostream>

using std::cout;
using std::endl;

#define SIZE 100
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

double Array[SIZE];

/**
 * Main function.
 */
int main()
{
    cout << "Simultaneous minmax:" << endl;

    Array[SIZE / 3] = 100;
    Array[SIZE / 2] = -100;

    /* Core of task. */

    double min = Array[0];
    double max = Array[0];
    int i = 1;

    while (i < SIZE)
    {
        if (i == SIZE - 1)
        {
            min = MIN(min, Array[i]);
            max = MAX(max, Array[i]);

            i++;
        }
        else
        {
            if (Array[i] < Array[i + 1])
            {
                min = MIN(min, Array[i]);
                max = MAX(min, Array[i + 1]);
            }
            else
            {
                min = MIN(min, Array[i + 1]);
                max = MAX(max, Array[i]);
            }

            i += 2;
        }
    }

    cout << "Min = " << min << ", Max = " << max << endl;

    return 0;
}

