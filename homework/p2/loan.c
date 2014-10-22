// Helen Chac

#include <stdio.h>
#include <math.h>

void get_loans(int *loan, double *interest, int *months_start_payment, int *months_will_pay);
double calc_payments(int loan, double interest, int months_start_payment, int months_will_pay);
void show_totals(double total, int payments);

int main()
{
  int loan = 0, months_strt_payment = 0, num_payments_will_make = 0;
  double interest = 0.0, total;
  
  get_loans(&loan, &interest, &months_strt_payment, &num_payments_will_make);
  total = calc_payments(loan, interest, months_strt_payment, num_payments_will_make);
  show_totals(total, num_payments_will_make);

  return 0;

}//main()

void get_loans(int *loan, double *interest, int *months_start_payment, int *months_will_pay)
{
  printf("Please enter the loan, and interest: ");
  scanf("%d %lf", loan, interest);
  printf("Please enter the number of months until you start payments: ");
  scanf("%d", months_start_payment);
  printf("Please enter the number of payments you wish to make: ");
  scanf("%d", months_will_pay);
}//get_loans()

double calc_payments(int loan, double interest, int months_start_payment, int months_will_pay)
{
  
  double final_principal = loan * pow(( 1 + (interest / 12 )), 12 * months_start_payment / 12 );
  double monthly_payment = ( final_principal * (interest / 12 ) ) / ( 1 - exp ( - months_will_pay * (log ( 1 + interest / 12 ) ) ));
  return monthly_payment;
}//calc_payments()

void show_totals(double total, int payments)
{
  printf("For that loan, your monthly payment will be $%.2lf, for a total of $%.2lf.\n", total, total * payments);
} //show_total()
