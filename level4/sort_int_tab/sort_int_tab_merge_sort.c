
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:15:21 by exam              #+#    #+#             */
/*   Updated: 2019/03/05 11:41:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Merge Sort O(NlogN)

/**************************** PASSES IN EXAM ***************************/

void merger(int arr[], unsigned int start, unsigned int middle, unsigned int end)
{
    unsigned int h1 = (middle - start) + 1;
    unsigned int h2 = (end - (middle + 1)) + 1;
    int arrh1[h1], arrh2[h2];
    
    for (unsigned int i = 0; i < h1; i++)
    {
        arrh1[i] = arr[start + i];
    }
    for (unsigned int j = 0; j < h2; j++)
    {
        arrh2[j] = arr[middle + 1 +  j];
    }
    unsigned int i = 0; unsigned int j = 0; unsigned int k = start;
    while ( i < h1 && j < h2)
    {
        if (arrh1[i] <= arrh2[j])
        {
            arr[k] = arrh1[i];
            i++;
        }
        else
        {
            arr[k] = arrh2[j];
            j++;
        }
        k++;
    }
    while ( i < h1)
    {
        arr[k] = arrh1[i];
        i++;
        k++;
    }
    while (j < h2)
    {
        arr[k] = arrh2[j];
        j++;
        k++;
    }
}

void merge_sort(int tab[], unsigned int start, unsigned int end)
{
    if (start < end)
    {
        unsigned int middle = start + (end - start) / 2; // or (start + end) / 2, this is not taken because the addition will outbound the int range.
        merge_sort(tab, start, middle);
        merge_sort(tab, middle + 1, end);

        merger(tab, start, middle, end);
    }

}

void sort_int_tab(int *tab, unsigned int size)
{
    merge_sort(tab, 0, size - 1);   
}

/*
#include <stdio.h>
void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main (void)
{
    int arr[12] = {0 ,1, 3, 6, 2, 4, 1324, 16774, 9, 2, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort_int_tab(arr, size);
    print_arr(arr, size);
    return 0;
}
*/
