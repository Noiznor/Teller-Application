#include "teller.h"

int main() {
    PaymentRecord* head = NULL;
    int record_count = 0;
    char choice;
    do {
        printf("=== PAYMENT RECORD MAIN MENU ===\n");
        printf("[+] ADD NEW PAYMENT\n");
        printf("[-] DELETE PAYMENT RECORD\n");
        printf("[X] EDIT\n");
        printf("\nChoose:  ");
        scanf(" %c", &choice);
        switch (choice) {
            case '+':
                head = add_payment_record(head, &record_count);
                display_payment_records(head, record_count);

                break;
            case '-':
                head = delete_payment_record(head, &record_count);
                display_payment_records(head, record_count);
                break;
            case 'X':
            case 'x':
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'X' && choice != 'x');


    PaymentRecord* record = head;
    while (record != NULL) {
        PaymentRecord* next_record = record->next;
        free(record->payee_name);
        free(record->pay_date);
        free(record);
        record = next_record;
    }

    return 0;
}
