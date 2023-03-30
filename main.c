#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

FILE *fp;
int buffer[200];
char filename[100];

void addData(){
    printf("Masukkan nama file baru: ");
    scanf("%s", filename);
    strcat(filename, ".txt");
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Gagal membuat file %s.\n", filename);
    } else {
        printf("File %s berhasil dibuat.\n", filename);
        fclose(fp);
    }
}

void readData(){
    printf("Masukkan nama file yang ingin dibaca: ");
    scanf("%s", filename);
    strcat(filename, ".txt");
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File %s tidak ditemukan.\n", filename);
    } else {
        printf("Isi file %s:\n", filename);
        while(fgets(filename, 100, fp) != NULL) {
            printf("%s", filename);
        }
        fclose(fp);
    }
    getch();
}

void updateData() {
    printf("Masukkan nama file yang ingin diubah: ");
    scanf("%s", filename);
    strcat(filename, ".txt");
    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("File %s tidak ditemukan.\n", filename);
        return;
    }

    int index, num;
    printf("Masukkan indeks data yang ingin diubah: ");
    scanf("%d", &index);
    printf("Masukkan nilai baru: ");
    scanf("%d", &num);

    fseek(fp, index * sizeof(int), SEEK_SET);
    fwrite(&num, sizeof(int), 1, fp);
    fclose(fp);
    printf("Data pada indeks %d telah diubah.\n", index);
    getch();
}

void deleteData() {
    printf("Masukkan nama file yang ingin dihapus: ");
    scanf("%s", filename);
    strcat(filename, ".txt");
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File %s tidak ditemukan.\n", filename);
        return;
    }

    int index, num, count = 0;
    printf("Masukkan indeks data yang ingin dihapus: ");
    scanf("%d", &index);

    while(fread(&num, sizeof(int), 1, fp) == 1) {
        if (count != index) {
            buffer[count] = num;
        }
        count++;
    }
    fclose(fp);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Gagal membuka file %s.\n", filename);
        return;
    }

    fwrite(buffer, sizeof(int), count-1, fp);
    fclose(fp);
    printf("Data pada indeks %d telah dihapus.\n", index);
    getch();
}

int main(){
system("color 37");
    int choice;

    do {
        system("cls");
        menuawal:
        printf("\tPilihan Menu:\n");
        printf("\t1. Tambah data baru\n");
        printf("\t2. Lihat data\n");
        printf("\t3. Ubah data\n");
        printf("\t4. Hapus data\n");
        printf("\t5. Keluar\n");
        printf("\tMasukkan pilihan Anda: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                system("cls");
                addData();
                break;

            case 2:
                system("cls");
                readData();
                break;
                goto menuawal;
            case 3:
                system("cls");
                updateData();
                break;
                goto menuawal;
            case 4:
                system("cls");
                deleteData();
                break;
            case 5:
                system("cls");
                printf("\nTerima kasih telah menggunakan program ini!\n");
                exit(0);
                break;
            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 5);

    return 0;
}

