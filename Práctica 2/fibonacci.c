#include <stdio.h>
#include <stdlib.h>

void fibonacci_iterativa(unsigned long long num_fibonacci_anterior, unsigned long long num_fibonacci_actual, unsigned long long aux, int count, int *ct)
{
    char excel[] = "fibonacci_ite.csv"; // Nombre del archivo
    FILE *pSalida = fopen(excel, "w"); // Abrir archivo para escritura

    (*ct)++;

    for (int i = 0; i < count; i++)
    {
        (*ct)++;

        aux = num_fibonacci_actual;
        (*ct)++;
        num_fibonacci_actual += num_fibonacci_anterior;
        (*ct)++;
        num_fibonacci_anterior = aux;
        (*ct)++;

        fprintf(pSalida, "%d,%d\n", i + 1, *ct); // Escribir en el archivo
    }
    (*ct)++;

    fclose(pSalida); // Cerrar archivo
}

// int fibonacci(int n, int *ct) 
// {
//     (*ct)++;
//     if (n == 0 || n == 1)
//     {
//         (*ct)++;
//         return n;
//     }  

//     (*ct)++;
//     return fibonacci (n - 1, ct) + fibonacci(n - 2, ct); 
// }

// void imprimir_fib (int n)
// {
//     int ct = 0;
//     char excel[] = "fibonacci_rec_exp.csv"; // Nombre del archivo
//     FILE *pSalida = fopen(excel, "w"); // Abrir archivo para escritura

//     for (int i = 0; i < n; i++) 
//     {
//         ct = 0;

//         printf("[%d] ", fibonacci(i, &ct));
//         fprintf(pSalida, "%d,%d\n", i + 1, ct); // Escribir en el archivo
//     }

//     pSalida = fopen(excel, "r"); // Abrir archivo para lectura
//     fclose(pSalida); // Cerrar archivo

// }


void fibonacci_recursiva_l (char excel[], unsigned long long num_fibonacci_anterior, unsigned long long num_fibonacci_actual, int count, int *ct_r, int i)
{
    (*ct_r)++;
    if (count == 0)
    {
        (*ct_r)++;
        return;
    }
    else
    {
        printf("[%llu] ", num_fibonacci_anterior);
        // (*ct_r)++;

        FILE *pSalida = fopen(excel, "a"); // Abrir archivo en modo de adición

        (*ct_r)++;

        fprintf(pSalida, "%d,%d\n", i, *ct_r); // Escribir en el archivo
        i++;

        fclose(pSalida); // Cerrar archivo
        
        fibonacci_recursiva_l (excel, num_fibonacci_actual, num_fibonacci_actual + num_fibonacci_anterior, count - 1, ct_r, i); 
    }
}

int main()
{
    system("clear");
    char excel[] = "fibonacci_rec.csv"; // Nombre del archivo
   
    int count, ct_i = 0, ct_r = 0, i = 1;

    printf("Ingrese cuántos valores de la sucesión de Fibonacci desea\n=> ");
    scanf("%d", &count );

    fibonacci_iterativa(0, 1, 0, count, &ct_i);
    printf("Iterativo con %d procesos\n", ct_i);

    fibonacci_recursiva_l (excel, 0, 1,count, &ct_r, i);
    printf("Recursivo con %d procesos\n", ct_r);

    // imprimir_fib (count);
    // printf("\n");

    return 0;
}