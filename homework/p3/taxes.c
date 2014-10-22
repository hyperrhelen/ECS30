// Helen Chac

#include <stdio.h>

int main()
{
  double gross_income, tax_income;
  int standard_deduction = 5950;
  
  printf("Please enter your gross taxable_income for 2012: ");
  scanf("%lf", &gross_income);
  tax_income = gross_income - standard_deduction;
  
  if (tax_income < 0 ) // if tax income is less than 0, print
    printf("The tax on $%.2lf is $%.2lf.\n", gross_income, -tax_income * 0);
  else 
    if (tax_income >= 0 &&tax_income < 8700) // if tax income is less than 8700, print
      printf("The tax on $%.2lf is $%.2lf.\n", gross_income, (tax_income * .1));
    else // if tax is not less than 8700
      if (tax_income >= 8700 && tax_income < 35350) // if tax income is between 8700 and 35350, print
        printf("The tax on $%.2lf is $%.2lf.\n", gross_income, ((tax_income - 8700) * .15 ) + 870);
      else // if tax isn't less than 35350
        if (tax_income >= 35350 && tax_income < 85650) // if tax income is between 35350 and 85650, print
          printf("The tax on $%.2lf is $%.2lf.\n", gross_income, ((tax_income - 35350) * .25 ) + 4867.50);
        else // if tax income is not less than 85650
          if (tax_income >= 85650 && tax_income < 178650) // if tax income is between 85650 and 178650, print
	    printf("The tax on $%.2lf is $%.2lf.\n", gross_income, (tax_income - 85650) * .28 + 17422.50);
	  else // if tax income is not less than 178650
	    if (tax_income >= 178650 && tax_income < 388350) // if tax income is between 178650 and 388350, print
	      printf("The tax on $%.2lf is $%.2lf.\n", gross_income, ((tax_income - 178650) * .33 ) + 43482.50);
	    else // if tax income is not less than 388350
	      if (tax_income >= 388350) // if tax income is greater than 388350
                printf("The tax on $%.2lf is $%.2lf.\n", gross_income, ((tax_income - 388350) * .35 ) + 112683.50);
    
  return 0;
}//main()
