#include<stdio.h>
#include "global.h"

void orderHistory() {
	system("cls");
	int ordered_flag=0;
	for(int i=0;i<DessertLen;i++){
		if(ArrayDessert[i].dessert_cooking_time<=0){
			ordered_flag = 1;
		}
	}
	for(int i=0;i<DrinkLen;i++){
		if(ArrayDrink[i].drink_cooking_time<=0){
			ordered_flag = 1;
		}
	}
	if(ordered_flag==0){
		printf("There is no Order History!\n\n");
		getchar();
		printf("Press enter to continue...");
		getchar();
		return;
	}
    puts("| No  | Name                 | Price  | Topping    | Callories  | Flavor     | size  | Order Time           |");
    puts(" -----------------------------------------------------------------------------------------------------------");
    int index = 1;
    for(int i = 0; i<DessertLen; i++){
        if(ArrayDessert[i].dessert_cooking_time<=0){
			printf("| %-4d| %-21s| %-7d| %-11s| %-11.2f| -          | -     | %s  |\n", index, ArrayDessert[i].food_name, ArrayDessert[i].food_price, ArrayDessert[i].dessert_topping, ArrayDessert[i].dessert_calories, ArrayDessert[i].created_at);
        	index++;
		}
    }
    for(int i = 0; i<DrinkLen; i++){
        if(ArrayDrink[i].drink_cooking_time<=0){
			printf("| %-4d| %-21s| %-7d| -          |-           | %-11s| %c     | %s  |\n", index, ArrayDrink[i].food_name, ArrayDrink[i].food_price, ArrayDrink[i].drink_flavor, ArrayDrink[i].drink_size, ArrayDrink[i].created_at);
			index++;
		}
	}
    puts("");
    printf("Press Enter to continue");
    getchar();
}
