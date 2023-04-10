// 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void SetColor(unsigned short);
void SetColor(unsigned short color) {
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleOutput,color);
}
struct data {
    int id;
    char nama[30], tanggal[20], harga[30], telp[20];
}dat[15];

struct node {
    char hist[100];
    struct node *next;
};

int jum=0, tot=0, temp, oy, result, x;
char temps[100];
struct node*head = NULL;

void letak();
void kotak1();
void Ulang_Login();
void Tampilan_Tetap();
void Mencari();

// 2

 void letak (int x, int y){
        COORD CRD;
        CRD.X=x;
        CRD.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
    }

void Tampilan_Tetap() {
    printf(" ====================================================\n");
    printf("                   APLIKASI PERPUSTAKAAN              \n");
    printf(" ====================================================\n");
}

void Mencari(){
    int i, j;
    struct data temp;

    // sorting the data array by book ID in ascending order using bubble sort
    for(i=0; i<tot-1; i++){
        for(j=0; j<tot-i-1; j++){
            if(dat[j].id > dat[j+1].id){
                temp = dat[j];
                dat[j] = dat[j+1];
                dat[j+1] = temp;
            }
        }
    }
}


void append(struct node** head_ref, char histo[]) {

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = * head_ref;

    strcpy(new_node->hist, histo);
    new_node->next = NULL;

    if(*head_ref == NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// 3

void printlist(struct node *node){
    while(node != NULL){
        printf("%s \n", node->hist);
        node = node->next;
    }
}

// 4

void tambah(){

    printf(" ===== Tambah Data Buku ===== ");
    letak(6,27);
    printf(" Masukan Jumlah Data Buku Yang Dimasukan (max = 15): "); scanf("%d", &jum);

    for(int i = 0; i < jum; i++) {
        system("cls");
        Tampilan_Tetap();
        letak(6,25);
        printf(" ===== Tambah Data Buku ===== ");
        letak(6,27);
        printf(" Masukan Jumlah Data Buku Yang Dimasukan (max = 15): %d", jum);
        letak(6,29);
        printf(" Data ke %d", i+1);
        letak(6,31);
        printf(" Tanggal       : ");
        letak(6,32);
        printf(" Judul Buku    : ");
        letak(6,33);
        printf(" ID Buku       : ");
        letak(6,34);
        printf(" Penerbit      : ");
        letak(20,31);
        scanf(" %[^\n]%*c", &dat[i+tot].tanggal);
        letak(20,32);
        scanf(" %[^\n]%*c", &dat[i+tot].nama);
        letak(20,33);
        scanf(" %[^\n]%*c", &dat[i+tot].harga);
        letak(20,34);
    }

// 5

    snprintf(temps, sizeof(temps), "ADMIN menambahkan %d data buku", jum);
    append(&head, temps);
    tot += jum;
    letak(9,38);
    printf(" ===== NOTIFIKASI ===== ");
    letak(9,39);
    printf(" %d Data Buku Berhasil Ditambahkan", tot);
    letak(9,41);
    printf(" Tekan Enter Untuk Kembali ke Menu"); getch();

}

// 6

void lihat() {
    for(int i = 0; i < tot; i++) {
        if(i==0 || i%3==0) {
            system("cls");
            Tampilan_Tetap();
            letak(6,25);
            printf(" ===== Daftar Data Buku ===== \n\n");
            letak(6,27);
            printf(" Data ke %d", i+1);
            letak(6,29);
            printf(" Tanggal Input      :%s", dat[i].tanggal);
            letak(6,30);
            printf(" Judul Buku         :%s", dat[i].nama);
            letak(6,31);
            printf(" Nomor ID Buku      :%s", dat[i].id);
            letak(6,32);
            printf(" Penerbit           :%s", dat[i].harga);
        }else if(i==1 || i==4 || i==7 || i==10 || i==13) {
            letak(6,35);
            printf(" Data ke %d", i+1);
            letak(6,37);
            printf(" Tanggal Input      :%s", dat[i].tanggal);
            letak(6,38);
            printf(" Judul Buku         :%s", dat[i].nama);
            letak(6,39);
            printf(" Nomor ID Buku      :%s", dat[i].id);
            letak(6,40);
            printf(" Penerbit           :%s", dat[i].harga);

// 7

        }else {
            letak(6,43);
            printf(" Data ke %d", i+1);
            letak(6,45);
            printf(" Tanggal Input      :%s", dat[i].tanggal);
            letak(6,46);
            printf(" Judul Buku         :%s", dat[i].nama);
            letak(6,47);
            printf(" Nomor ID Buku      :%s", dat[i].id);
            letak(6,48);
            printf(" Penerbit           :%s", dat[i].harga);
            letak(6,51);
            getch();
        }
    }

    letak(6,51);
    printf(" Tekan Enter Untuk Kembali ke Menu"); getch();
}

// 8

void urut() {
    int j=0;
    for (int i = 0; i < tot -1; j++) {
        for (int j = 0; j < tot -i -1; j++) {
            if (dat[j].id > dat[j+1].id) {
                temp = dat[j].id;
                dat[j].id = dat[j+1].id;
                dat[j+1].id = temp;

                strcpy(temps, dat[j].nama);
                strcpy(dat[j].nama, dat[j+1].nama);
                strcpy(dat[j+1].nama, temps);

                strcpy(temps, dat[j].telp);
                strcpy(dat[j].telp, dat[j+1].telp);
                strcpy(dat[j+1].telp, temps);

                strcpy(temps, dat[j].tanggal);
                strcpy(dat[j].tanggal, dat[j+1].tanggal);
                strcpy(dat[j+1].tanggal, temps);

                strcpy(temps, dat[j].harga);
                strcpy(dat[j].harga, dat[j+1].harga);
                strcpy(dat[j+1].harga, temps);
            }
        }
    }

// 9

    for(int i = 0; i < tot; i++) {
        if(i == 0 || i% 3 == 0 ) {
            system("cls");
            Tampilan_Tetap();
            letak(6,25);
            printf(" ===== Daftar Data Buku ===== \n\n");
            letak(6,27);
            printf(" Data ke %d", i+1);
            letak(6,29);
            printf(" Tanggal Input      :%s", dat[i].tanggal);
            letak(6,30);
            printf(" Judul Buku         :%s", dat[i].nama);
            letak(6,31);
            printf(" Nomor ID Buku      :%s", dat[i].id);
            letak(6,32);
            printf(" Penerbit           :%s", dat[i].harga);
        }else if(i==1 || i==4 || i==7 || i==10 || i==13) {
            letak(6,35);
            printf(" Data ke %d", i+1);
            letak(6,37);
            printf(" Tanggal Input      :%s", dat[i].tanggal);
            letak(6,38);
            printf(" Judul Buku         :%s", dat[i].nama);
            letak(6,39);
            printf(" Nomor ID Buku      :%s", dat[i].id);
            letak(6,40);
            printf(" Penerbit           :%s", dat[i].harga);

//10
        }else{
            printf("Data ke %d", i+1);
            letak (6,45);
            printf("Tanggal input : %s", dat[i].tanggal);
            letak (6, 46);
            printf("Judul Buku: %s", dat[i].nama);
            letak (6,47);
            printf("Nomor ID buku : %d", dat[i].id);
            letak (6,48);
            printf("Penerbit: %s", dat[i].harga);
            letak (6,51); getch();
        }
    }
    letak (6,29);
    strcpy (temps, " ADMIN mengurutkan data buku");
    append (&head, temps);

    letak (6,51);
    printf("Tekan Enter Untuk Kembali ke Menu");
}

//11
void cari(){
    letak(45,13);
    printf("==Pencarian Data Buku=="); letak (45,15);
    printf("Masukkan Nomor ID Buku: "); scanf("%d", &oy);
    result = 0;
    Mencari ();
    for (x=0; x <= tot; x++) {
        if (oy == dat[x].id){
            result = 1;
            break;
        }
    }
    if (result == 1){
        letak (6,25);
        printf("~ Data Ditemukan ");
        letak (6,27);
        printf("Tanggal input : %s", dat [x].tanggal);
        letak (6,28);
        printf("Judul Buku : %s", dat [x].nama);
        letak (6,29);
        printf("Nomor ID Buku : %d", dat [x].id);
        letak (6,30);
        printf("Penerbit: %s", dat [x].harga);
    }
    else{
        letak (6,28);
        printf("~ Data Tidak Ditemukan ~");
    }

    snprintf(temps, sizeof(temps), "ADMIN mencari data Buku No. %d", oy);
    append(&head, temps);
    letak (6,33);
    printf("Tekan Enter Untuk Kembali ke Menu"); getch();
}

void hapus () {
    char jawab, search[30];
    letak (45, 13);
    printf("=== Hapus Data Buku ===");
    letak (45, 15);
    printf("Masukkan Nomor ID Buku : "); scanf("%d", &oy);
    Mencari ();
    result = 0;
    for ( x = 0; x <= tot; x++) {
            if (oy == dat [x].id) {
                result = 1;
                break;
            }
    }

    if (result == 1) {
        letak (6,25);
        printf("Data buku berikut akan dihapus :");
        letak (6,27);
        printf("Tanggal input : %s", dat [x].tanggal);
        letak (6,28);
        printf("Judul Buku : %s", dat [x].nama);
        letak (6,29);
        printf("Nomor ID Buku : %d", dat [x].id);
        letak (6,30);
        printf("Penerbit : %s", dat [x].harga);

        snprintf(temps, sizeof(temps), " ADMIN menghapus data Buku No. %d", dat [x].id);
        append(&head, temps);

        for (int i = 0; i < tot; i++) {
            strcpy(dat [x+i].nama, dat [x+1+i].nama);
            dat [x+i].id = dat [x+1+i].id;
            strcpy(dat [x+i].telp, dat [x+1+i].telp);
            strcpy(dat [x+i].tanggal, dat [x+1+i].tanggal);
            strcpy(dat [x+i].harga, dat [x+1+i].harga);
        }
        tot -= 1;
    }
    else{
        letak (6,28);
        printf("~ Data Tidak Ditemukan ");
    }
    letak (6,33);
    printf("Tekan Enter Untuk Kembali ke Menu"); getch();

}

//14
void edit () {
    char stemp [30], search [30];
    int jaw= 0;

    letak (45,13);
    printf("=== Ubah Data Buku ===");
    letak (45,15);
    printf("Masukkan Nomor ID Buku: "); scanf("%d", &oy);
    Mencari ();
    result = 0;
    for ( x = 0; x <= tot; x++) {
        if (oy == dat [x].id) {
            result = 1;
            break;
        }
    }

    if (result == 1) {
        letak (6,25);
        printf("Data Buku berikut akan Diubah :");
        letak (6,27);
        printf("Tanggal input : %s", dat [x].tanggal);
        letak (6,28);
        printf("Judul Buku : %s", dat [x].nama);
        letak (6,29);
        printf("Nomor ID Buku : %d", dat [x].id);
        letak (6,30);
        printf("Penerbit : %s", dat [x].harga);

        letak (6,34);
        printf("Pilih Data yang akan diganti");
        letak (6,35);
        printf("1. Tanggal input");
        letak (6,36);
        printf("2. Judul Buku");
        letak (6,37);
        printf("3. Nomor ID Buku");
        letak (6,38);
        printf("4. Penerbit");
        letak (6,39);
        printf("5. Selesai / Batal");
        letak (6,41);
        printf("Pilihan : "); scanf("%d", &jaw);

        switch (jaw) {
            case 1: letak (6, 43); printf("Tanggal Input Baru: "); scanf("%[^\n]*c", &stemp);
            strcpy (search, dat [x]. tanggal);
            strcpy (dat [x].tanggal, stemp); snprintf(temps, sizeof(temps), "ADMIN mengubah tanggal input buku No. %d dari is menjadi %s", dat [x].id, search, dat [x]. tanggal);
            append(&head, temps);
            break;

            case 2: letak (6,43); printf("Judul Baru "); scanf("%[^\n]*c", &stemp); strcpy (search, dat [x].nama);
            strcpy(dat [x].nama, stemp); snprintf(temps, sizeof(temps), " ADMIN mengubah judul buku No. %d dari s menjadi %s", dat [x].id, search, dat [x].nama); append(head, temps);
            break;

            case 3: letak (6,43); printf("Nomor ID Buku: "); scanf("%d", &temp);
            jaw = dat [x]. id;
            dat [x].id = temp;
            snprintf(temps, sizeof(temps), " ADMIN mengubah Nomor ID buku No. %d dari %d menjadi %d", dat [x].id, jaw, dat [x].id);
            append(&head, temps);
            break;

            case 4:
            letak(6,43); printf("Penerbit Baru: "); scanf("%[^\n]*c", stemp);
            strcpy(search, dat[x].harga);
            strcpy(dat[x].harga, stemp);
            snprintf(temps, sizeof(temps), " ADMIN mengubah Penerbit buku No. %d dari %s menjadi %s", dat[x].id, search, dat[x].harga);
            append(&head, temps);
            break;
            case 5:
            break;
            default:
                letak (6,43);
                printf("Pilihan Tidak Tersedia");
                break;
            }

            letak (6,45);
            printf("Tekan Enter Untuk Kembali ke Menu");
            getch();


    }
}
//17
void riwayat () {
     system("cls");
     printf("\n printlist (head); Riwayat Perubahan Data Buku =====\n\n");
     printf("\n\n Tekan Enter Untuk Kembali ke Menu"); getch();
}
//18

//20

//21
    void kotak1(){
        letak(26, 6);
        printf("\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf\n");
        letak(26, 7);
        printf("\xb3                        \xb3");
        letak(26, 8);
        printf("\xb3                        \xb3");
        letak(26, 9);
        printf("\xb3                        \xb3");
        letak(26, 10);
        printf("\xb3                        \xb3");
        letak(26, 11);
        printf("\xb3                        \xb3");
        letak(26, 12);
        printf("\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    }

//22
int main()
{
    SetColor(10);
    system("color 8F");
    getch();
    fflush(stdin);

     int pilihan;
    char a=170,b=219;
    printf("\n\n\n\n\n\n\n");
    printf("\n\n\n\t\t\t\t\tLoading...");
    printf("\n\n");
    printf( "\t\t\t\t\t");

    for (int i=0; i<= 25; i++)
    {
          printf(">");
        Sleep(100);
    }
    printf ("\n\n\t\t\t\t\t'PRESS ANY BUTTON TO LOGIN'");
    system ("pause>0");


    char nama[10], psw[8];
    int ulang = 0;
    system ("cls");

    for(int i=0; i<3; i++)
    {
        for(int i=0; i<120; i++)
        {
            printf("_");Sleep(10);
        }
        printf("\n\n");
        for(int i=0; i<46; i++)
        {
            printf("=");Sleep(10);
        }
        printf(" | LOGIN KE TOKO KLONTONG KAMI | ");

        for(int i=0; i<51; i++)
        {
            printf("=");Sleep(10);
        }
        printf("\n");
         for(int i=0; i<120; i++)
        {
            printf("_");Sleep(10);
        }
        printf("\n\n");
        printf(" Username: ");
        scanf ( "%s", &nama);
        printf(" Password: ");
        scanf("%s", &psw);

        if ((strcmp(nama,"admin")==0)&&(strcmp(psw,"1234")==0))
        {
            break;
        } else
        {
            printf("\n Password atau username yang anda masukan salah.");
            ulang = ulang + 1;
            Sleep(2000);
        }
        system ("cls");
    }

    if(ulang<3)
    {
        printf("\n Anda berhasil login");
     {system ("cls"); goto menu;}
    }

    else
    {
        printf("\n Anda terlalu banyak membuat kesalahan, Anda bisa ngopi dulu kemudian merenungkan kesalahan Anda,\nlalu setelah itu Anda bisa mencoba login kembali.");
    }
    printf("\n-----------------------------------\n\n");return 0;
	


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////v-tabel pembuka

    menu:
//////////////////////////////////////////////////v-garis pembuka
          printf("\n\n");
          printf( "\t\t\t");
        printf("|");
         for(int i=0; i<51; i++)
        {
            printf("=");Sleep(10);
        }
        printf("|");printf("\n");
//////////////////////////////////////////////////v-spasi satu
          printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(10);
        }
        printf("|");printf("\n");
//////////////////////////////////////////////////v-spasi tulisan satu
        printf( "\t\t\t");printf("|");
        for(int i=0; i<12; i++)
        {
            printf(" ");Sleep(10);
        }
        printf(" SELAMAT DATANG DALAM PROGRAM");
 //////////////////////////////////////////////////v-spasi tulisan dua
         for(int i=0; i<11; i++)
        {
            printf(" ");Sleep(10);
        } printf("|");printf("\n");
 //////////////////////////////////////////////////v-spasi tulisan satu
         printf( "\t\t\t");printf("|");
        for(int i=0; i<7; i++)
        {
            printf(" ");Sleep(10);
        }
        printf(" DATABASE TOKO KLONTONG KAMI");
         for(int i=0; i<6; i++)
        {
            printf(" ");Sleep(10);
        } printf("|");printf("\n");
//////////////////////////////////////////////////v-spasi tulisan dua
         printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(10);
        }
        printf("|");printf("\n");
//////////////////////////////////////////////////v-garis pembatas tengah
       printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf("-");Sleep(10);
        }
        printf("|");printf("\n");
//////////////////////////////////////////////////v-spasi satu
        printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(10);
        }
        printf("|");printf("\n");
//////////////////////////////////////////////////v-spasi tulisan satu
         printf( "\t\t\t");
        for(int i=0; i<15; i++)
        {
            printf(" ");Sleep(10);
        }
////////////////////////////////////////////////////////////////////////////////////v-waktu
        time_t mytime;
		mytime = time(NULL);
		printf(ctime(&mytime));

//////////////////////////////////////////////////v-spasi dua
         printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(10);
        }
        printf("|");printf("\n");
//////////////////////////////////////////////////v-garis penutup
        printf( "\t\t\t");
        printf("|");
         for(int i=0; i<51; i++)
        {
            printf("-");Sleep(10);
        }
        printf("|");printf("\n");

////////////////////////////////////////////////////////////////////////////////////////////////////////////v-menu utama

        printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(10);
        }
        printf("|");printf("\n");
        do {
        letak (6,9);
        printf("= Menu Utama =");
        letak (6,11);
        printf("1. Tambah Data Buku");
        letak (6, 12);
        printf("2. Lihat Data Buku");
        letak (6,13);
        printf("3. Urutkan Data Buku");
        letak (6,14);
        printf("4. Pencarian Data Buku");
        letak (6, 15);
        printf("5. Hapus Data Buku");
        letak(6,16);
        printf("6. Ubah Data Buku");
        letak (6, 17);
        printf("7. Lihat Riwayat Perubahan");
        letak (6,18);
        printf("8. Exit");
        letak (6,19);
        printf("Masukkan Pilihan Anda : "); scanf("%d", &pilihan);

        switch(pilihan) {
            case 1: tambah(); break;
            case 2: lihat(); break;
            case 3: urut(); break;
            case 4: cari(); break;
            case 5: hapus(); break;
            case 6: edit(); break;
            case 7: riwayat(); break;
            case 8: return 0;
            default: letak(6,21); printf("Pilihan Tidak Tersedia");getch();
        }
    } while(pilihan != 8);

    return 0;
}
