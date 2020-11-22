#include"global.h"
//#include"Tugas-3.h"
//#include"Tugas-4.h"
//#include"Tugas-5.h"
//#include"Tugas-6.h"

void operCookedMainMenu(){
    
    while(1){
        ClearScreen();

        printf("Welcome to Opercooked\n");
        printf("Today Profit: $%d\n", PROFIT);
        printf("===========================\n");
        printf("1. Add Dessert or Beverage\n");
        printf("2. View Cooking Process\n");
        printf("3. View Order History\n");
        printf("4. Order Dessert or Beverage\n");
        printf("5. Exit\n");
        printf(">> ");

        int choice;
        scanf("%d", &choice);
        getchar();

        if(choice >= 1 && choice <= 5){
            
            if(choice == 1){
                //addDesertAndBeverage();
            }
            else if(choice == 2){
                //showCookingProcess();
            }
            else if(choice == 3){
                //orderHistory();
            }
            else if(choice == 4){
                //order();
            }
            else{
                break;
            }

        }
        else{
            printf("Not Valid!!!\n");
            printf("Press Enter To Continue\n");
            getchar();
        }

    }

}

    

