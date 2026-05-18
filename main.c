#include <stdio.h>


int menu_advanced_sorting(){
    int input;
    int p=0;
   
    do
    {
        input=0;
        printf("\n==== ADVANCED SORTING ====\n");
        printf("1.Merge Sort\n");
        printf("2.Quick Sort\n");
        printf("3.Shell Sort\n");
        printf("4.Kembali\n");
        printf("Pilih metode:");
        p=scanf("%d",&input);
        while(getchar()!='\n');
        switch (input)
        {
        case 1:
           printf("Merge sort\n");
            break;
        case 2:
            printf("Quick sort\n");
            break;
        case 3:
            printf("Shell sort\n");
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
    int p=0;
   
    do
    {   
        input=0;
        printf("\n==== SORTING DASAR ====\n");
        printf("1.Bubble Sort\n");
        printf("2.Insertion Sort\n");
        printf("3.Selection Sort\n");
        printf("4.Kembali\n");
        printf("Pilih metode:");
        p=scanf("%d",&input);
        while(getchar()!='\n');
        switch (input)
        {
        case 1:
           printf("bubble sort\n");
            break;
        case 2:
            printf("insertion sort\n");
            break;
        case 3:
            printf("selection sort\n");
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
    int p=0;
   
    do
    {   
        input=0;
        printf("\n==== MENU UTAMA ====\n");
        printf("1.Sorting Dasar\n");
        printf("2.Advanced Sorting\n");
        printf("3.Keluar\n");
        printf("Pilih menu:");
        p=scanf("%d",&input);
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