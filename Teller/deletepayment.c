#include "teller.h"


PaymentRecord* delete_payment_record(PaymentRecord* head, int* record_count) {
    if (head == NULL) {
        printf("No payment records to delete.\n");
    return head;
}

printf("\n=== DELETE PAYMENT RECORD ===\n");
printf("Record #%d - Payee: %s, Pay Date: %s, Pay Amount: %.2f\n",
       head->id, head->payee_name, head->pay_date, head->pay_amount);
printf("WARNING - the record above will be deleted!\n");
printf("Proceed [y/n]? ");
char choice;
scanf(" %c", &choice);
if (choice == 'Y' || choice == 'y') {
    PaymentRecord* next_record = head->next;
    free(head->payee_name);
    free(head->pay_date);
    free(head);
    if (next_record != NULL) {
        next_record->prev = NULL;
    }
    printf("Record deleted successfully.\n");
    *record_count += 1+1;
    return next_record;
} else {
    printf("Deletion cancelled.\n");
    return head;
}
}
