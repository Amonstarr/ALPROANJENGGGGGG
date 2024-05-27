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
} Livestock;

typedef struct {
    char name[50];
    float balance;
    Loan loans[MAX_MEMBERS];
    int loanCount;
} Member;

Livestock items[MAX_ITEMS] = {
    {"Ayam", 50000.0, 100},
    {"Kambing", 1500000.0, 50},
    {"Sapi", 10000000.0, 20}
};
int itemCount = 3;

Member members[MAX_MEMBERS];
int memberCount = 0;

int main() {
    loadMembers();
    loadItems();

    int choice;
    while (1) {
        printf("\n========================================================\n");
        printf("------------------------- COOFARM ----------------------\n");
        printf("========================================================\n");
        printf("1. Tambah Anggota\n");
        printf("2. Ajukan Pinjaman\n");
        printf("3. Beli Barang Ternak\n");
        printf("4. Lihat Anggota\n");
        printf("5. Cek Saldo\n");
        printf("6. Pembayaran\n");
        printf("7. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMember();
                break;
            case 2:
                applyLoan();
                break;
            case 3:
                buyItem();
                break;
            case 4:
                viewMember();
                break;
            case 5:
                checkBalance();
                break;
            case 6:
                makePayment();
                break;
            case 7:
                saveMembers();
                saveItems();
                exit(0);
            default:
                printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}
