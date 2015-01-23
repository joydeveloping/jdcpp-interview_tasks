/**
 * Reverse single linked list.
 *
 * Input:
 *   Simple linked list L1 -> L2 -> ... -> Ln.
 *
 * Output:
 *   Reversed list Ln -> ... -> L2 -> L1.
 *
 * Note:
 *   Algorithm compexity should be O(N).
 *
 * Copyright Joy Developing.
 */

#include <iostream>

using std::cout;
using std::endl;

/**
 * List element.
 */
typedef struct Elem
{
    int I;               /* inner data */
    struct Elem *Next_p; /* next element pointer */

    /**
     * Constructor.
     */
    Elem(int i, struct Elem *next_p)
    {
        I = i;
        Next_p = next_p;
    }

    /**
     * Destructor.
     */
    ~Elem()
    {
        if (Next_p != NULL)
        {
            delete Next_p;
        }
    }
} Elem;

/**
 * Push new element to list.
 */
Elem *Push(Elem *head_p, int i)
{
    return new Elem(i, head_p);
}

/**
 * Print list.
 */
void Print(Elem *head_p)
{
    Elem *cur_p = head_p;

    cout << "List :";
    while (cur_p != NULL)
    {
        cout << " " << cur_p->I;
        cur_p = cur_p->Next_p;
    }
    cout << endl;
}

/**
 * Reverse list.
 */
Elem *Reverse(Elem *head_p)
{
    if (head_p == NULL)
    {
        return NULL;
    }

    /*
     * Core of the test.
     * General case.
     */

    Elem *cur_head_p = head_p->Next_p;
    Elem *new_head_p = head_p;
    new_head_p->Next_p = NULL;

    while (cur_head_p != NULL)
    {
        Elem *tmp_p = cur_head_p->Next_p;

        cur_head_p->Next_p = new_head_p;
        new_head_p = cur_head_p;
        cur_head_p = tmp_p;
    }

    return new_head_p;
}

/**
 * Main function.
 */
int main()
{
    cout << "Reverse single linked list:" << endl;

    /* Create list with integers from 1 to 10. */
    Elem *head_p = new Elem(10, NULL);
    for (int i = 9; i > 0; i--)
    {
        head_p = Push(head_p, i);
    }

    /* Print, reverse and print again. */
    Print(head_p);
    head_p = Reverse(head_p);
    Print(head_p);

    /* Delete list. */
    delete head_p;

    return 0;
}

