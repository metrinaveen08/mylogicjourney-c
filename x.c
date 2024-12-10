#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

void addItem(Item inventory[], int *count);
void viewItems(Item inventory[], int count);
void searchItem(Item inventory[], int count);

int main() {
    Item inventory[MAX_ITEMS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nInventory Management System:\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Search Item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &count);
                break;
            case 2:
                viewItems(inventory, count);
                break;
            case 3:
                searchItem(inventory, count);
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addItem(Item inventory[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", inventory[*count].name);
    printf("Enter item quantity: ");
    scanf("%d", &inventory[*count].quantity);
    printf("Enter item price: ");
    scanf("%f", &inventory[*count].price);
    (*count)++;
    printf("Item added successfully!\n");
}

void viewItems(Item inventory[], int count) {
    if (count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\nInventory Items:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchItem(Item inventory[], int count) {
    char name[50];
    printf("Enter item name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Item found: Name: %s, Quantity: %d, Price: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }

    printf("Item not found.\n");
}