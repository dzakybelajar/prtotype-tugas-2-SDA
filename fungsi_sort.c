#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"header.h"

clock_t waktu_mulai, waktu_akhir;
double kompleksitas_waktu;
int tampilan;
int data_bilangan[MAX_INT];
char data_string[MAX_WORD][20];

int baca_file(){
    FILE *file=fopen("words.txt","r");

    if (file==NULL)
    { printf("file tidak ditemukan!\n"); return 0; }
    else if (fgetc(file)==EOF)
    { printf("file tidak ada konten!\n"); fclose(file); return 0; }
    rewind(file);

    printf("file berhasil dibaca!\n");
    int i=0;
    while (i<MAX_WORD && (fgets(data_string[i],20,file))!=NULL)
    {
        data_string[i][strcspn(data_string[i], "\n")] = 0;
        i++;
    }
    fclose(file);
    return 1;
}

void acak_data(int mode){
    if(mode==MAX_INT)
    {
        srand(time(NULL));
        for (int i = 0; i < MAX_INT; i++)
        { data_bilangan[i]=rand(); }
    }
    else if(mode==MAX_WORD)
    {
        srand(time(NULL));
        for (int i = MAX_WORD - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            char temp[20];
            strcpy(temp, data_string[i]);
            strcpy(data_string[i], data_string[j]);
            strcpy(data_string[j], temp);
        }
    } 
}

int InputTampilanSebelumAtauSetelahSorting(int max){
    int input=0;
    int p=0;
    do{
        printf("masukkan banyak data yang ingin ditampilkan:");
        p=scanf("%d",&input);
        while(getchar()!='\n');
        if (p==0 || input<=0 || input>max)
        { printf("input tidak valid!\n"); }
    }while(input<=0 || input>max);
    return input;
}

void TampilanSebelumAtauSetelahSorting(int tampilan,int mode){
    if(mode==MAX_INT)
    {
        for (int i = 0; i < tampilan; i++)
        { printf("%d ",data_bilangan[i]); }
        printf("\n");
    }
    else if(mode==MAX_WORD)
    {
        for (int i = 0; i < tampilan; i++)
        { printf("%s\n",data_string[i]); }
    }   
}

void bubble_sort(){
    acak_data(MAX_INT);
    tampilan=InputTampilanSebelumAtauSetelahSorting(MAX_INT);
    printf("sebelum sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan,MAX_INT);

    waktu_mulai=clock();
    for (int i = 0; i < MAX_INT; i++)
    {
        for (int j = 1; j < MAX_INT-i; j++)
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

    tampilan=InputTampilanSebelumAtauSetelahSorting(MAX_INT);
    printf("setelah sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan,MAX_INT);
}

void insertion_sort() {    
    acak_data(MAX_INT);
    tampilan=InputTampilanSebelumAtauSetelahSorting(MAX_INT);
    printf("sebelum sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan,MAX_INT);

    waktu_mulai = clock();
    for (int i = 0; i < MAX_INT - 1; i++) 
    {   
        int j = i + 1;
        int temp = data_bilangan[j];
        while (j > 0 && temp < data_bilangan[j - 1])
        { data_bilangan[j] = data_bilangan[j - 1]; j--; }
        data_bilangan[j] = temp;
    }
    
    waktu_akhir = clock();
    kompleksitas_waktu = ((double)(waktu_akhir - waktu_mulai)) / CLOCKS_PER_SEC;
    printf("waktu yang diperlukan: %f detik\n", kompleksitas_waktu);
    tampilan=InputTampilanSebelumAtauSetelahSorting(MAX_INT);
    printf("setelah sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan,MAX_INT);
}

void selection_sort(){
    acak_data(MAX_INT);
    tampilan=InputTampilanSebelumAtauSetelahSorting(MAX_INT);
    printf("sebelum sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan,MAX_INT);
    
    waktu_mulai=clock();
    for (int i = 0; i < MAX_INT-1; i++)
    {   
        int indeks=i;
        for (int j = i+1; j < MAX_INT; j++)
        {
            if (data_bilangan[j]<data_bilangan[indeks])
            { indeks=j; }
        } 
        if (indeks!=i)
        {
            int temp=data_bilangan[indeks];
            data_bilangan[indeks]=data_bilangan[i];
            data_bilangan[i]=temp;
        }
    }
    waktu_akhir=clock();
    kompleksitas_waktu=((double) (waktu_akhir - waktu_mulai)) / CLOCKS_PER_SEC;
    printf("waktu yang diperlukan:%f detik\n",kompleksitas_waktu);

    tampilan=InputTampilanSebelumAtauSetelahSorting(MAX_INT);
    printf("setelah sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan,MAX_INT);
}

void merge(int left, int mid, int right){
    char temp[MAX_WORD][20];
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right)
    {
        if(strcmp(data_string[i], data_string[j]) < 0)
        { strcpy(temp[k], data_string[i]); i++; }
        else
        { strcpy(temp[k], data_string[j]); j++; } 
        k++;
    }

    while(i <= mid)
    {
        strcpy(temp[k], data_string[i]);
        i++; k++;
    }

    while(j <= right)
    {
        strcpy(temp[k], data_string[j]);
        j++; k++;
    }
        for(i = left; i <= right; i++)
    { strcpy(data_string[i], temp[i]); }
}

void merge_sort_recursive(int left, int right){
    if(left < right)
    {
        int mid = (left + right) / 2;
        merge_sort_recursive(left, mid);
        merge_sort_recursive(mid + 1, right);
        merge(left, mid, right);
    }
}

void merge_sort(){
    acak_data(MAX_WORD);
    tampilan=InputTampilanSebelumAtauSetelahSorting(MAX_WORD);
    printf("sebelum sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan,MAX_WORD);

    waktu_mulai=clock();
    merge_sort_recursive(0, MAX_WORD - 1);
    waktu_akhir=clock();
    kompleksitas_waktu= ((double) (waktu_akhir - waktu_mulai)) / CLOCKS_PER_SEC;
    printf("waktu yang diperlukan:%f detik\n", kompleksitas_waktu);

    tampilan=InputTampilanSebelumAtauSetelahSorting(MAX_WORD);
    printf("setelah sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan,MAX_WORD);
}

void quick_sort(){
    acak_data(MAX_WORD);
    tampilan=InputTampilanSebelumAtauSetelahSorting(MAX_WORD);
    printf("sebelum sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan,MAX_WORD);

    waktu_mulai=clock();
    //algoritmanya
    waktu_akhir=clock();
    kompleksitas_waktu=((double) (waktu_akhir - waktu_mulai)) / CLOCKS_PER_SEC;
    printf("waktu yang diperlukan:%f detik\n",kompleksitas_waktu);

    tampilan=InputTampilanSebelumAtauSetelahSorting(MAX_WORD);
    printf("setelah sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan,MAX_WORD);
}

void shell_sort(){
    acak_data(MAX_WORD);
    tampilan=InputTampilanSebelumAtauSetelahSorting(MAX_WORD);
    printf("sebelum sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan,MAX_WORD);

    waktu_mulai=clock();
    int gap=MAX_WORD/2;
    while (gap>=1)
    {
        for (int i = gap; i < MAX_WORD; i++) 
        {   
            int j = i;
            char temp[1][20];
            strcpy(temp[0],data_string[j]);
            while (j-gap>=0 && strcmp(temp[0],data_string[j-gap])<0)
            {
                strcpy(data_string[j],data_string[j-gap]);
                j-=gap;
            }
            strcpy(data_string[j],temp[0]);
        }
        gap=gap/2;
    }
    waktu_akhir=clock();
    kompleksitas_waktu=((double) (waktu_akhir - waktu_mulai)) / CLOCKS_PER_SEC;
    printf("waktu yang diperlukan:%f detik\n",kompleksitas_waktu);

    tampilan=InputTampilanSebelumAtauSetelahSorting(MAX_WORD);
    printf("setelah sorting:\n");
    TampilanSebelumAtauSetelahSorting(tampilan,MAX_WORD);    
}
