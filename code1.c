
/* 
Name: Sina Asheghalishahi
KUID: 3127403
LAB Session: Wednesday 9 a.m.
LAB Assignment: 05
Description: 
Collaborators: None
*/

#include <stdio.h>

int main(){

    FILE* file_ptr;
    char string[100];
    char filename[100];

    do{
        printf("Enter file name: \n");
        scanf("%s", &filename);
        file_ptr = fopen(filename, "r");

        if(NULL == file_ptr){
            printf("File not found.\n");
        }

    } while (NULL == file_ptr);


    float salesArray[12];
    char monthArray[12][10] = {
        "January", "February", "March",
        "April", "May", "June", 
        "July", "August", "September", 
        "October", "November", "December"};
    

    for(int i = 0; i < 12; i++){
        fscanf(file_ptr, "%f", &(salesArray[i]));
    }

    fclose(file_ptr);
    
    //Monthly Sales Report
    printf("\nMonthly Sales Report: \n\n");
    printf("Month       Sales\n");

     for(int i = 0; i < 12; i++){
        printf("%-12s%.2f\n", monthArray[i], salesArray[i]);
    }
    
    //Sales Summary Report
    printf("\n\nSales Summary Report: \n\n");
    
    float minVal = salesArray[0];
    int minInd;

    float maxVal = salesArray[0];
    int maxInd;

    float sum;
    float avg;

    for(int i = 0; i < 12; i++){
        sum += salesArray[i];

        if(salesArray[i] < minVal){
            minVal = salesArray[i];
            minInd = i;
        }

        if(salesArray[i] > maxVal){
            maxVal = salesArray[i];
            maxInd = i;
        }
    }

    avg = sum/12;

    printf("Minimum Sales: %.2f (%s)\n", minVal, monthArray[minInd]);
    printf("Maximum Sales: %.2f (%s)\n", maxVal, monthArray[maxInd]);
    printf("Average Sales: %.2f\n", avg);


    //Six-Month Moving Average Report
    printf("\n\nSix-Month Moving Average Report: \n\n");

    sum = 0;
    for(int i = 0; i < 6; i++){
        sum += salesArray[i];
    }
    printf("%s-%-10s%.2f\n", monthArray[0], monthArray[5], sum/6);

    sum = 0;
    for(int i = 1; i < 7; i++){
        sum += salesArray[i];
    }
    printf("%s-%-9s%.2f\n", monthArray[1], monthArray[6], sum/6);

    sum = 0;
    for(int i = 2; i < 8; i++){
        sum += salesArray[i];
    }
    printf("%s-%-12s%.2f\n", monthArray[2], monthArray[7], sum/6);

    sum = 0;
    for(int i = 3; i < 9; i++){
        sum += salesArray[i];
    }
    printf("%s-%-12s%.2f\n", monthArray[3], monthArray[8], sum/6);

    sum = 0;
    for(int i = 4; i < 10; i++){
        sum += salesArray[i];
    }
    printf("%s-%-14s%.2f\n", monthArray[4], monthArray[9], sum/6);

    sum = 0;
    for(int i = 5; i < 11; i++){
        sum += salesArray[i];
    }
    printf("%s-%-13s%.2f\n", monthArray[5], monthArray[10], sum/6);
    
    sum = 0;
    for(int i = 6; i < 12; i++){
        sum += salesArray[i];
    }
    printf("%s-%-13s%.2f\n", monthArray[6], monthArray[11], sum/6);
    
    
     //Sales Report (highest to lowest)
    printf("\n\nSales Report (highest to lowest): \n\n");
    printf("Month       Sales\n");

    float salesArray2[12];
    for(int i = 0; i < 12; i++){
        salesArray2[i] = salesArray[i];
    }


    for(int i = 0; i < 12; i++){
        maxVal = salesArray2[0];
        maxInd = 0;
        for(int j = 0; j < 12; j++){
            if(salesArray2[j] > maxVal){
                maxVal = salesArray2[j];
                maxInd = j;
            }
        }
        printf("%-12s$%.2f\n", monthArray[maxInd], maxVal);
        salesArray2[maxInd] = -1;
    }
    
    return 0;
}