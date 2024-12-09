#include <stdio.h>

int main() {
    long int amount,balance;
    enum otions{CHECK_BALANCE = 1,DEPOSIT,WITHDRAW,EXIT};
    int option;
    printf("Welcome to the Banking System!\n");
    printf("Enter the initial balance: ");
    scanf("%ld", &balance);
    while (1) {
        printf("\nBanking System Menu:\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case CHECK_BALANCE:
                printf("Your current balance is: %ld\n",balance);
                break;
            case DEPOSIT:
                printf("Enter amount to deposit: ");
                scanf("%ld", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Successfully deposited %ld\n",amount);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;
            case WITHDRAW:
                printf("Enter amount to withdraw: ");
                scanf("%ld", &amount);
                if(amount > 0) {
                    if (amount <= balance) {
                        balance -= amount;
                        printf("Successfully withdrew $%ld\n", amount);
                } 
                }
                else {
                    printf("Invalid withdraw amount.\n");
                }
                break;
            case EXIT:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
