#include<stdio.h>
#include"header.h"
#include<stdlib.h>
#include<time.h>

int data_bilangan[1000];
clock_t waktu_mulai, waktu_akhir;
double kompleksitas_waktu;
int tampilan;

void acak_data_bilangan(){
    srand(time(NULL));
    for (int i = 0; i < 1000; i++)
    { data_bilangan[i]=rand(); }
}

int InputTampilanSebelumAtauSetelahSorting(){
    int input=0;
    int p=0;
    do{
        printf("masukkan banyak data yang ingin ditampilkan:");
        p=scanf("%d",&input);
        while(getchar()!='\n');
        if (p==0 || input<=0)
        { printf("input tidak valid!\n"); }
    }while(input<=0);
    return input;
}

void TampilanSebelumAtauSetelahSorting(int tampilan){
    for (int i = 0; i < tampilan; i++)
    { printf("%d ",data_bilangan[i]); }
    printf("\n");
}

void bubble_sort(){
    acak_data_bilangan();
    tampilan=InputTampilanSebelumAtauSetelahSorting();
    printf("sebelum sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan);

    waktu_mulai=clock();
    for (int i = 0; i < sizeof(data_bilangan)/sizeof(int); i++)
    {
        for (int j = 1; j < sizeof(data_bilangan)/sizeof(int); j++)
        {
            if (data_bilangan[j-1]>data_bilangan[j])
            {
                int temp=data_bilangan[j];
                data_bilangan[j]=data_bilangan[j-1];
                data_bilangan[j-1]=temp;
            }
        } 
    }
    waktu_akhir=clock();
    kompleksitas_waktu=((double) (waktu_akhir - waktu_mulai)) / CLOCKS_PER_SEC;
    printf("waktu yang diperlukan:%f detik\n",kompleksitas_waktu);

    tampilan=InputTampilanSebelumAtauSetelahSorting();
    printf("setelah sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan);
}

void insertion_sort(){
    acak_data_bilangan();
    tampilan=InputTampilanSebelumAtauSetelahSorting();
    printf("sebelum sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan);



    tampilan=InputTampilanSebelumAtauSetelahSorting();
    printf("setelah sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan);
}

void selection_sort(){
    acak_data_bilangan();
    tampilan=InputTampilanSebelumAtauSetelahSorting();
    printf("sebelum sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan);
    
    waktu_mulai=clock();
    for (int i = 0; i < sizeof(data_bilangan)/sizeof(int); i++)
    {
        for (int j = i+1; j < sizeof(data_bilangan)/sizeof(int); j++)
        {
            if (data_bilangan[i]>data_bilangan[j])
            {
                int temp=data_bilangan[j];
                data_bilangan[j]=data_bilangan[i];
                data_bilangan[i]=temp;
            }
        } 
    }
    waktu_akhir=clock();
    kompleksitas_waktu=((double) (waktu_akhir - waktu_mulai)) / CLOCKS_PER_SEC;
    printf("waktu yang diperlukan:%f detik\n",kompleksitas_waktu);

    tampilan=InputTampilanSebelumAtauSetelahSorting();
    printf("setelah sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan);
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