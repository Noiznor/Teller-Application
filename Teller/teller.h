#ifndef TELLER_H_INCLUDED
#define TELLER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct PaymentRecord {
    int id, termios, old_term, new_term;;
    char* payee_name;
    char* payee_id;
    char* pay_date;
    float pay_amount;
    struct PaymentRecord* next;
    struct PaymentRecord* prev;

} PaymentRecord;


PaymentRecord* add_payment_record(PaymentRecord* head, int* record_count);
PaymentRecord* delete_payment_record(PaymentRecord* head, int* record_count);
void display_payment_records(PaymentRecord* head, int record_count);


#endif // TELLER_H_INCLUDED
