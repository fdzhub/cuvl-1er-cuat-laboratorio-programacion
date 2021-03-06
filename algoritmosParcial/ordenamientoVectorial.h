#ifndef ORDENAMIENTOVECTORIAL_INCLUDED
#define ORDENAMIENTOVECTORIAL_INCLUDED

#include <stdio.h>

void bubbleSortSimple( int vec[], int len )
{
    int i = 0;
    for ( int i = 0; i < len; i++ )
    {
        for ( int j = 0; j < len-1; j++ )
        {
            if ( vec[j] > vec[j+1] )
            {
                int aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
}

void bubbleSort( int vec[], int len )
{
    int i = 0;
    bool cambio = true;
    while ( cambio  )
    {
        cambio = false;
        for ( int j = 0; j < len-1; j++ )
        {
            if ( vec[j] > vec[j+1] )
            {
                int aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
                cambio = true;
            }
        }
    }
}

void bubbleSort2( int vec[], int len )
{
    int i = 0;
    int jMax = len;
    while ( jMax > 1 )
    {
        for ( int j = 0; j < jMax-1; j++ )
        {
            if ( vec[j] > vec[j+1] )
            {
                int aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
        jMax--;
    }
}

void bubbleSort3( int vec[], int len )
{
    int i = 0;
    int jMax = len;
    bool cambio = true;
    while ( jMax > 1 && cambio  )
    {
        cambio = false;
        for ( int j = 0; j < jMax-1; j++ )
        {
            if ( vec[j] > vec[j+1] )
            {
                int aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
                cambio = true;
            }
        }
        jMax--;
    }
}

void bubbleSort( char vec[], int len )
{
    bool cambio = true;
    int i = 0;
    int jMax = len;
    while ( jMax > 1 && cambio  )
    {
        cambio = false;
        for ( int j = 0; j < jMax-1; j++ )
        {
            if ( vec[j] > vec[j+1] )
            {
                char aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
                cambio = true;
            }
        }
        jMax--;
    }
}

void insertionOrder( int vec[], int len )
{
    for ( int i = 0; i < len; i++ )
    {
        int aux = vec[i];
        int j = i-1;
        while ( j >= 0 && vec[j] >= aux )
        {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = aux;
    }
}

//https://mathbits.com/MathBits/CompSci/Arrays/Shell.htm
void shellSort( int vec[], int len)
{
    int i = 0;
    int aux = 0;
    int otro = len;
    bool flag = true;
    while( flag || otro > 1)// boolean flag (true when not equal to 0)
    {
        flag = false;// reset flag to 0 to check for future swaps
        otro = (otro+1) / 2;
        for (i = 0; i < (len - otro); i++)
        {
            if (vec[i + otro] < vec[i])
            {
              aux = vec[i + otro];// swap positions i+d and i
              vec[i + otro] = vec[i];
              vec[i] = aux;
              flag = true;// tells swap has occurred
            }
        }
    }
    return;
}

/**
 * esta funcion hace...
 * @param[in] {int[]} vector
 * @param[in] {int} principio
 * @param[in] {int} fin
 * @return {int} retorno
 */
void quickSort( int vec[], int p, int f )
{
    int medio = ( p + f ) / 2;
    int pivote = vec[medio];
    int i = p;
    int j = f;
//    printf("%i a %i, medio: %i\n", i, j, medio );
    do
    {
        while( vec[i] < pivote )
        {
            i++;
        }
        while( vec[j] > pivote )
        {
            j--;
        }
        if( i <= j )
        {
            int aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;
            i++;
            j--;
        }
    }
    while ( i <= j );

    if ( p <= j )
    {
        quickSort(vec, p, j);
    }
    if ( i < f )
    {
        quickSort(vec, i, f);
    }
}

#endif // ORDENAMIENTOVECTORIAL_INCLUDED
