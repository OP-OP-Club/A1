#include "global.h"

void orderHistory() {
	
    system("@cls||clear");

	int ordered_flag=0;
	Dessert *curr = ArrayDessertHead;
	while (curr) {
		if(curr->dessert_cooking_time<=0){
			ordered_flag = 1;
			break;
		}
		curr = curr->next;
	}
	Drink *temp = ArrayDrinkHead;
	while (temp) {
		if(temp->drink_cooking_time<=0){
			ordered_flag = 1;
			break;
		}
		temp = temp->next;
	}
	
	if(ordered_flag==0) {
		printf("There is no Order History!\n\n");
		getchar();
		printf("Press enter to continue...");
		getchar();
		return;
	}
    puts("| No  | Name                 | Price  | Topping    | Callories  | Flavor     | size  | Order Time           |");
    puts(" -----------------------------------------------------------------------------------------------------------");
    int index = 1;
	curr = ArrayDessertHead;
    while(curr) {
        if(curr->dessert_cooking_time<=0){
			printf("| %-4d| %-21s| %-7d| %-11s| %-11.2f| -          | -     | %-20s |\n", index, curr->food_name, curr->food_price, curr->dessert_topping, curr->dessert_calories, curr->created_at);
        	index++;
		}
		curr = curr->next;
    }
	temp = ArrayDrinkHead;
    while(temp) {
        if(temp->drink_cooking_time<=0){
			printf("| %-4d| %-21s| %-7d| -          |-           | %-11s| %c     | %-20s |", index, temp->food_name, temp->food_price, temp->drink_flavor, temp->drink_size, temp->created_at);
			index++;
		}
	}
    puts("");
    printf("Press Enter to continue");
    getchar();
}
