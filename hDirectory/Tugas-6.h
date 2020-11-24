#include "global.h"
 
#include<stdio.h>
 
void order(){
 
	system("@cls||clear");
 
	if(ArrayDessertMenuHead == NULL && ArrayDrinkMenuHead==NULL){
		printf("There is no Dessert or Drink on the list!\n\n");
		printf("Press Enter to continue");
		getchar();
		return;
	}
	//print menu 
	int CtrDessertMenu=0,CtrDrinkMenu=0;
	int index = 1;
	puts("| No  | Name                 | Price  | Topping    | Callories  | Flavor     | size  |");
	puts(" -------------------------------------------------------------------------------------");
	struct MenuDessert *curr = ArrayDessertMenuHead;
	while(curr!=NULL){
		printf("| %-4d| %-21s| %-7d| %-11s| %-11.2f| -          | -     |\n", index , curr->food_name , curr->food_price , curr->dessert_topping , curr->dessert_calories);
        index++;
        CtrDessertMenu++;
        curr=curr->next;
	}
 
	struct MenuDrink  *curr2 = ArrayDrinkMenuHead;
	while(curr2!=NULL){
		printf("| %-4d| %-21s| %-7d| -          |-           | %-11s| %c     |\n", index , curr2->food_name , curr2->food_price , curr2->drink_flavor , curr2->drink_size);
		index++;
		CtrDrinkMenu++;
		curr2=curr2->next;
	}
 
	//scan order
	int orderMenu;
 
	do{
		if((CtrDessertMenu+CtrDrinkMenu)==1){
			printf("Choose a menu to order:");
		}
		else {
			printf("Choose a menu to order [ 1 - %d ]:",CtrDessertMenu+CtrDrinkMenu);	
		}
		scanf("%d", &orderMenu);
		puts("");
 
		printf("order menu : %d\n", orderMenu);
	}while(orderMenu<1||orderMenu>(CtrDessertMenu+CtrDrinkMenu));
 
	char created_at_now[100];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(created_at_now, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
 
	//strcpy
	if(orderMenu<=CtrDessertMenu){
		orderMenu--;
 
		curr = ArrayDessertMenuHead;
		while(orderMenu--){
			curr = curr->next;
		}
 
		//Aku udah sampai sini
		Dessert *temp= CreateDessertNodes(curr->food_name,curr->food_price,curr->dessert_topping,curr->dessert_calories,curr->dessert_cooking_time);
 		DessertPushBack(temp);
	}
 
	else {
		orderMenu--;
		orderMenu-=CtrDessertMenu;
		
		curr2 = ArrayDrinkMenuHead;
		while(orderMenu--){
			curr2 = curr2->next;
		}
		
		Drink *temp2= CreateDrinkNodes(curr2->food_name,curr2->food_price,curr2->drink_flavor,curr2->drink_size,curr2->drink_cooking_time);
		DrinkPushBack(temp2);
	
	}
 
 
	puts("");
	printf("Succesfully add to order list!\n\n");
	printf("Please Enter to Continue");
	getchar();
	return;
}
