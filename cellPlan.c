/**
 * Author: Sifat Syed
 *
 * This program calculates the average daily usage
 * of their mobile data plan. It tell the costumer
 * whether they are over, under or right on the
 * average daily usage if their plan.
 */

 #include<stdlib.h>
 #include<stdio.h>
 #include<math.h>

 int main(int argc, char **argv) {

  int dayNumber, daysLeft;
  double numberOfGBPlan, totalGBUsed, averageDailyUse, averageUsePerDay, planExceededCalculation, planExceeded,
        warningGBUse, totalGBLeft, atLeastUse, planDeceeded, warningShortGBUse;

  if(argc!=4){
    printf("Error:Provide the correct number of data\n");
    exit(1);
  }
  numberOfGBPlan = atof(argv[1]);
  dayNumber = atoi(argv[2]);
  totalGBUsed = atof(argv[3]);

   daysLeft = 30 - dayNumber;
   averageUsePerDay = totalGBUsed/dayNumber;
   averageDailyUse = numberOfGBPlan/30 ;
   planExceededCalculation = numberOfGBPlan - totalGBUsed + (daysLeft*averageUsePerDay);
   planExceeded = planExceededCalculation - numberOfGBPlan;
   totalGBLeft = numberOfGBPlan- totalGBUsed;
   warningGBUse = totalGBLeft/daysLeft;

  printf("%d days used, %d days remaining.\n",dayNumber, daysLeft);
  printf("Average daily use: %f GB/day\n", averageUsePerDay);

  if(averageUsePerDay>averageDailyUse) {
    printf("You are EXCEEDING your average daily use (%.2f GB/day).\n", averageDailyUse);
    printf("Continuing this high usage, you will exceed your data plan by .2%f GB.\n", planExceeded);
    printf("To stay below your data plan use no more than %.2f GB per day\n",warningGBUse);
}
 /*else if(averageUsePerDay<averageDailyUse) {
    printf("You are DECEEDING your average daily use (%.2f GB/day).\n", averageDailyUse);
    printf("Continuing this low usage, you will deceed your data plan by %.2f GB.\n", planDeceeded);
    printf("To stay at right limit of your data plan, use atleast %.2f GB per day\n",warningShortGBUse);

}*/ else {
  printf("You are using your plan at the right average daily use, so no need to worry.\n");
}
}
