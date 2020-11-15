#include<stdio.h>
#include "global.h"

void order(){
	ClearScreen();
	
	if(DessertMenuLen==0&&DrinkMenuLen==0){
		printf("There is no Dessert or Drink on the list!\n\n");
		printf("Press Enter to continue");
		getchar();
		return;
	}
	
	//print menu 
	int index = 1;
	puts("| No  | Name                 | Price  | Topping    | Callories  | Flavor     | size  |");
	puts(" -------------------------------------------------------------------------------------");
	for(int i=0;i<DessertMenuLen;i++){
		printf("| %-4d| %-21s| %-7d| %-11s| %-11.2f| -          | -     |\n", index, ArrayDessert[i].food_name, ArrayDessert[i].food_price, ArrayDessert[i].dessert_topping, ArrayDessert[i].dessert_calories);
        index++;
	}
	
	for(int i = 0; i<DrinkMenuLen; i++){
		printf("| %-4d| %-21s| %-7d| -          |-           | %-11s| %c     |\n", index, ArrayDrink[i].food_name, ArrayDrink[i].food_price, ArrayDrink[i].drink_flavor, ArrayDrink[i].drink_size);
		index++;
	}
	
	//scan order
	int orderMenu;
	
	do{
		if((DessertMenuLen+DrinkMenuLen)==1){
			printf("Choose a menu to order:");
		}
		else {
			printf("Choose a menu to order [ 1 - %d ]:",DessertMenuLen+DrinkMenuLen);	
		}
		scanf("%d",orderMenu);
		puts("");
		
	}while(orderMenu<1||orderMenu>(DessertMenuLen+DrinkMenuLen));
	
	
	//strcpy
	if(orderMenu<=DessertMenuLen){
		orderMenu--;
		strCpy(ArrayDessert[DessertLen].food_name , ArrayDessertMenu[orderMenu].food_name);
		ArrayDessert[DessertLen].food_price = ArrayDessertMenu[orderMenu].food_price;
		strCpy(ArrayDessert[DessertLen].dessert_topping , ArrayDessertMenu[orderMenu].dessert_topping);
    	ArrayDessert[DessertLen].dessert_calories = ArrayDessertMenu[orderMenu].dessert_calories;
    	ArrayDessert[DessertLen].dessert_cooking_time = ArrayDessertMenu[orderMenu].dessert_cooking_time;
    	DessertLen++;
	}
	
	else {
		orderMenu--;
		orderMenu-=DessertMenuLen;
		strCpy(ArrayDrink[DrinkLen].food_name , ArrayDrinkMenu[orderMenu].food_name);
   		ArrayDrink[DrinkLen].food_price = ArrayDrinkMenu[orderMenu].food_price;
    	strCpy(ArrayDrink[DrinkLen].drink_flavor , ArrayDrinkMenu[orderMenu].drink_flavor);
    	ArrayDrink[DrinkLen].drink_size = ArrayDrinkMenu[orderMenu].drink_size;
    	ArrayDrinkMenu[DrinkMenuLen].drink_cooking_time = ArrayDrinkMenu[orderMenu].drink_cooking_time;
    	DrinkLen++;
	}
	
	
	puts("");
	printf("Succesfully add to order list!\n\n");
	printf("Please Enter to Continue");
	getchar();
	return;
}
