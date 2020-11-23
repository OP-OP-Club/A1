#include "global.h"

void order(){

	ClearScreen();
	
	if(ArrayDessertMenuHead == NULL && ArrayDrinkMenuHead==NULL){
		printf("There is no Dessert or Drink on the list!\n\n");
		printf("Press Enter to continue");
		getchar();
		return;
	}
	//print menu 
	int CtrDessertMenu=0,CtrDrinkmenu=0;
	int index = 1;
	puts("| No  | Name                 | Price  | Topping    | Callories  | Flavor     | size  |");
	puts(" -------------------------------------------------------------------------------------");
	curr = ArrayDessertMenuHead;
	while(curr!=NULL){
		printf("| %-4d| %-21s| %-7d| %-11s| %-11.2f| -          | -     |\n", index , curr->food_name , curr->food_price , curr->dessert_topping , curr->dessert_calories);
        index++;
        CtrDessertMenu++;
        curr=curr->next;
	}
	curr2=ArrayDrinkMenuhead
	while(curr2!=NULL){
		printf("| %-4d| %-21s| %-7d| -          |-           | %-11s| %c     |\n", index , curr2->food_name , curr2->food_price , curr2->drink_flavor , curr2->drink_size);
		index++;
		CtrDrinkMenu++;
		curr2=curr->next;
	}
	
	//scan order
	int orderMenu;
	
	do{
		if((CtrDessertMenu+CtrDrinkmenu)==1){
			printf("Choose a menu to order:");
		}
		else {
			printf("Choose a menu to order [ 1 - %d ]:",CtrDessertMenu+CtrDrinkmenu);	
		}
		scanf("%d", &orderMenu);
		puts("");
		
		printf("order menu : %d\n", orderMenu);
	}while(orderMenu<1||orderMenu>(CtrDessertMenu+CtrDrinkmenu));
	
	char created_at_now[100];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(created_at_now, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	//strcpy
	//belum kuubah sama sekali
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
