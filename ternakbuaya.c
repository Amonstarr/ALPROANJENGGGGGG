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
