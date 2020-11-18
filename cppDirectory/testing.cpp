#include<stdio.h>
#include<stdlib.h>
#include"../hDirectory/global.h"

int main(){
	
	struct Dessert* head = CreateDessertNodes((char *) "testing name", 10000,  (char*) "top pign", 25.5, 20);
	
	while(head != NULL){
		printf("%s\n%d\n%f\n%d\n%s\n%s\n", head->food_name, head->food_price, head->dessert_calories, head->dessert_cooking_time, head->dessert_topping, head->created_at);
		
		head = head->next;
	}
	
}
