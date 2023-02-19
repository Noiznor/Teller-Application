#include "teller.h"

PaymentRecord* add_payment_record(PaymentRecord* head, int* record_count) {
                                                                                                                                        // Create new payment record
    PaymentRecord* new_record = malloc(sizeof(PaymentRecord));
    if (new_record == NULL) {
        return head;
    }
    new_record->id = ++(*record_count);
    printf("\n=== ADD PAYMENT RECORD ===\n");
    printf("Enter Payee's ID: ");
    char id_buf[15];
    scanf(" %10s", id_buf);
    new_record->payee_id = strdup(id_buf);
    printf("Enter Payee's Full Name: ");
    char name_buf[300];
    scanf(" %255[^\n]", name_buf);
    new_record->payee_name = strdup(name_buf);
    printf("Enter Pay Date (MM/DD/YYYY): ");
    char date_buf[15];
    scanf(" %10s", date_buf);
    new_record->pay_date = strdup(date_buf);
    printf("Enter Pay Amount: ");
    scanf("%f", &new_record->pay_amount);

                                                                                                                                                // Add new record
    new_record->prev = NULL;
    new_record->next = NULL;
    if (head == NULL) {
        head = new_record;
    } else {
        PaymentRecord* current_record = head;
        while (current_record->next != NULL) {
            current_record = current_record->next;
        }
        current_record->next = new_record;
        new_record->prev = current_record;
    }


    printf("\nRecord #%d added successfully.\n\n", new_record->id);

    return head;
}
