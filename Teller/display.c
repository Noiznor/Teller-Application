#include "teller.h"

void display_payment_records(PaymentRecord* head, int record_count) {
    printf("\n==================== PAYMENT RECORDS ====================\n");
    printf("| Record # | Pay Date   | Pay Amt | Payee Name               | Payee ID |\n");
    printf("|----------|------------|---------|--------------------------|----------|\n");

    // Display current record
    PaymentRecord* record = head;
    float total_amount = 0;
    while (record != NULL) {
        printf("| %8d | %10s | $%6.2f | %-20s | %8d |\n", record->id, record->pay_date, record->pay_amount, record->payee_name, record->payee_id);
        total_amount += record->pay_amount;
        record = record->next;
    }
    printf("|---------------------------------------------------------|\n");
    printf("| Grand Total:             | $%6.2f |                   |\n", total_amount);
    printf("| Total Records: %8d                                 |\n", record_count);
    printf("===========================================================\n\n");
}
