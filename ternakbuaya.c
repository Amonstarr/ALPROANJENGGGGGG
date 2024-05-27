#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_ITEMS 100
#define MEMBER_FILE "members.dat"
#define ITEM_FILE "items.dat"
#define INITIAL_DEPOSIT 50000.0

typedef struct {
    char name[50];
    float amount;
    int duration; // in months
} Loan;

typedef struct {
    char name[50];
    float price;
    int quantity;
} item;

typedef struct {
    char name[50];
    long int id;
    float balance;
    Loan loans[MAX_MEMBERS];
    int loanCount;
} Member;

item items[MAX_ITEMS] = {
    {"Pakan ayam", 20000.0, 80},
    {"Pakan Kambing", 50000.0, 50},
    {"Pakan Sapi", 80000.0, 20},
    {"Telur Ayam", 18000.0, 100},
    {"Daging Ayam", 35000.0, 20},
    {"Daging Kambing", 65000.0, 20},
    {"Daging Sapi", 105000.0, 20},
};
int itemCount = 3;

Member members[MAX_MEMBERS];
int memberCount = 0;

void menuMember() 
{
    //loadMembers();
    loadItems();

    int choice;
    
    printf("========================================================\n");
    printf("-------------------------- MEMBER ----------------------\n");
    printf("========================================================\n");
    printf("1. Ajukan Pinjaman\n");
    printf("2. Beli Barang\n");
    printf("3. Cek Saldo\n");
    printf("4. Pembayaran\n");
    printf("5. Kembali\n");
    printf("Pilih menu: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
        //applyLoan();
        break;

        case 2:
        //buyItem();
        break;

        case 3:
        //checkBalance();
        break;

        case 4:
        //makePayment();
        break;

        case 5:
        main();
        break;

        default:
        printf("Pilihan tidak valid!\n");
    }
}

void employee() 
{
    int choice;
    
    printf("========================================================\n");
    printf("------------------------- EMPLOYEE ---------------------\n");
    printf("========================================================\n");
    printf("1. Tambah Anggota\n");
    printf("2. Lihat Anggota\n");
    printf("3. Lihat Penjualan\n");
    printf("4. Kembali\n");
    printf("Pilih menu: ");
    scanf("%d", &choice);
    getchar();
    system("cls");

    switch (choice)
    {
        case 1:
        //addMember();
        break;

        case 2:
        //viewMember();
        break;

        case 3:
        //income();
        break;

        case 4:
        main();
        break;

        default:
        printf("Pilihan tidak valid!\n");
    }
}

int main() 
{
    system("cls");
    int choice;
    
    printf("========================================================\n");
    printf("------------------------- COOFARM ----------------------\n");
    printf("========================================================\n");
    printf("1. Pegawai\n");
    printf("2. Pelanggan\n");
    printf("3. Keluar\n");
    printf("Pilih menu: ");
    scanf("%d", &choice);
    getchar();
    system("cls");

    switch (choice)
    {
        case 1:
        employee();
        break;

        case 2:
        menuMember();
        break;

        case 3:
        printf("Good byee!!");
        system("pause");
        exit(0);
        break;

        default:
        printf("Pilihan tidak valid!\n");
    }
}

void loadItems() {
    FILE *file = fopen(ITEM_FILE, "rb");
    if (file) {
        fread(&itemCount, sizeof(int), 1, file);
        fread(items, sizeof(item), itemCount, file);
        fclose(file);
    }
}
