#include <stdio.h>
#include"header.h"

int menu_advanced_sorting(){
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
    return 1;
}

int menu_sorting_dasar(){
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
    return 1;
}

int menu_utama(){
    int input;
    do
    {   
        input=0;
        printf("\n==== MENU UTAMA ====\n");
        printf("1.Sorting Dasar\n");
        printf("2.Advanced Sorting\n");
        printf("3.Keluar\n");
        printf("Pilih menu:");
        scanf("%d",&input);
        while(getchar()!='\n');
        switch (input)
        {
        case 1:
            menu_sorting_dasar();
            break;
        case 2:
            menu_advanced_sorting();
            break;
        case 3:
            printf("Keluar dari program!");
            break;
        default:
            printf("input tidak valid!\n");
            break;
        }
    } while (input!=3);
    return 1;
}

int main(){
    menu_utama();
    return 0;
}