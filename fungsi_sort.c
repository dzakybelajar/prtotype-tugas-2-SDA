#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"header.h"

clock_t waktu_mulai, waktu_akhir;
double kompleksitas_waktu;
int tampilan;
int data_bilangan[1000];

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
        for (int j = 1; j < sizeof(data_bilangan)/sizeof(int)-i; j++)
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

void insertion_sort() {
    int n = sizeof(data_bilangan) / sizeof(data_bilangan[0]);
    
    acak_data_bilangan();
    printf("sebelum sorting:\n");
    TampilanSebelumAtauSetelahSorting(InputTampilanSebelumAtauSetelahSorting());

    clock_t waktu_mulai = clock();
    
    for (int i = 0; i < n - 1; i++) {   
        int j = i + 1;
        int temp = data_bilangan[j];
        while (j > 0 && temp < data_bilangan[j - 1]) {
            data_bilangan[j] = data_bilangan[j - 1];
            j--;
        }
        data_bilangan[j] = temp;
    }
    
    clock_t waktu_akhir = clock();
    double kompleksitas_waktu = ((double)(waktu_akhir - waktu_mulai)) / CLOCKS_PER_SEC;
    printf("waktu yang diperlukan: %f detik\n", kompleksitas_waktu);
    
    printf("setelah sorting:\n");
    TampilanSebelumAtauSetelahSorting(InputTampilanSebelumAtauSetelahSorting());
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
