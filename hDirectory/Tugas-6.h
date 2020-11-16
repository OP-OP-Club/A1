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
		printf("| %-4d| %-21s| %-7d| %-11s| %-11.2f| -          | -     |\n", index , ArrayDessertMenu[i].food_name , ArrayDessertMenu[i].food_price , ArrayDessertMenu[i].dessert_topping , ArrayDessertMenu[i].dessert_calories);
        index++;
	}
	
	for(int i = 0; i<DrinkMenuLen; i++){
		printf("| %-4d| %-21s| %-7d| -          |-           | %-11s| %c     |\n", index , ArrayDrinkMenu[i].food_name , ArrayDrinkMenu[i].food_price , ArrayDrinkMenu[i].drink_flavor , ArrayDrinkMenu[i].drink_size);
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
		scanf("%d", &orderMenu);
		puts("");
		
		printf("order menu : %d\n", orderMenu);
	}while(orderMenu<1||orderMenu>(DessertMenuLen+DrinkMenuLen));
	
	char created_at_now[100];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(created_at_now, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	//strcpy
	if(orderMenu<=DessertMenuLen){
		orderMenu--;
		strCpy(ArrayDessert[DessertLen].food_name , ArrayDessertMenu[orderMenu].food_name);
		ArrayDessert[DessertLen].food_price = ArrayDessertMenu[orderMenu].food_price;
		strCpy(ArrayDessert[DessertLen].dessert_topping , ArrayDessertMenu[orderMenu].dessert_topping);
    	ArrayDessert[DessertLen].dessert_calories = ArrayDessertMenu[orderMenu].dessert_calories;
    	ArrayDessert[DessertLen].dessert_cooking_time = ArrayDessertMenu[orderMenu].dessert_cooking_time;
		strCpy(ArrayDessert[DessertLen].created_at, created_at_now);
    	DessertLen++;
	}
	
	else {
		orderMenu--;
		orderMenu-=DessertMenuLen;
		strCpy(ArrayDrink[DrinkLen].food_name , ArrayDrinkMenu[orderMenu].food_name);
   		ArrayDrink[DrinkLen].food_price = ArrayDrinkMenu[orderMenu].food_price;
    	strCpy(ArrayDrink[DrinkLen].drink_flavor , ArrayDrinkMenu[orderMenu].drink_flavor);
    	ArrayDrink[DrinkLen].drink_size = ArrayDrinkMenu[orderMenu].drink_size;
    	ArrayDrink[DrinkMenuLen].drink_cooking_time = ArrayDrinkMenu[orderMenu].drink_cooking_time;
    	strCpy(ArrayDrink[DrinkMenuLen].created_at, created_at_now);
		DrinkLen++;
	}
	
	
	puts("");
	printf("Succesfully add to order list!\n\n");
	printf("Please Enter to Continue");
	getchar();
	return;
}
