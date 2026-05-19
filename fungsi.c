#include<stdio.h>
#include"header.h"
#include<stdlib.h>
#include<time.h>

int data_bilangan[1000];

void bubble_sort(){

}

void insertion_sort(){

}

void selection_sort(){

}

void merge_sort(){

}

void quick_sort(){

}

void shell_sort(){

}

void menu_advanced_sorting(){
    int input;
    do
    {
        input=0;
        printf("\n==== ADVANCED SORTING ====\n");
        printf("1.Merge Sort\n");
        printf("2.Quick Sort\n");
        printf("3.Shell Sort\n");
        printf("4.Kembali\n");
        printf("Pilih metode:");
        scanf("%d",&input);
        while(getchar()!='\n');
        switch (input)
        {
        case 1:
           merge_sort();
            break;
        case 2:
            quick_sort();
            break;
        case 3:
            shell_sort();
            break;
        case 4:
            printf("Kembali ke manu utama!\n");
            break;
        default:
            printf("input tidak valid!\n");
            break;
        }
    } while (input!=4);
}

void menu_sorting_dasar(){
    int input;
    do
    {   
        input=0;
        printf("\n==== SORTING DASAR ====\n");
        printf("1.Bubble Sort\n");
        printf("2.Insertion Sort\n");
        printf("3.Selection Sort\n");
        printf("4.Kembali\n");
        printf("Pilih metode:");
        scanf("%d",&input);
        while(getchar()!='\n');
        switch (input)
        {
        case 1:
           bubble_sort();
            break;
        case 2:
            insertion_sort();
            break;
        case 3:
            selection_sort();
            break;
        case 4:
            printf("Kembali ke manu utama!\n");
            break;
        default:
            printf("input tidak valid!\n");
            break;
        }
    } while (input!=4);
}