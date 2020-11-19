#include<stdio.h>
#include<stdlib.h>
#include"../hDirectory/global.h"

int main(){
	
//	struct Dessert* head = CreateDessertNodes((char *) "testing name", 10000,  (char*) "top pign", 25.5, 20);
//	struct Dessert* tail = head;
//	
//	
//	struct Dessert* temp = CreateDessertNodes((char *) "testing name", 10000,  (char*) "top pign", 25.5, 20);
//	
//	DessertPushBack(&head, &tail, temp);
//	
//	temp = CreateDessertNodes((char *) "testing name", 10000,  (char*) "top pign", 25.5, 20);
//	DessertPushBack(&head, &tail, temp);
//	temp = CreateDessertNodes((char *) "testing name", 10000,  (char*) "top pign", 25.5, 20);
//	DessertPushBack(&head, &tail, temp);
//	temp = CreateDessertNodes((char *) "testing name", 10000,  (char*) "top pign", 25.5, 20);
//	DessertPushBack(&head, &tail, temp);
//	
//	int count = 0;
//	while(head != NULL){
//		
//		printf("%s\n%d\n%f\n%d\n%s\n%s\n", head->food_name, head->food_price, head->dessert_calories, head->dessert_cooking_time, head->dessert_topping, head->created_at);
//		
//		head = head->next;
//		count++;
//	}
	
	struct Dessert *temp = CreateDessertNodes((char *) "testing name", 10000,  (char*) "top pign", 25.5, 20);
	DessertPushBack(temp);
	temp = CreateDessertNodes((char *) "testing name", 10000,  (char*) "top pign", 25.5, 20);
	DessertPushBack(temp);
	temp = CreateDessertNodes((char *) "testing name", 10000,  (char*) "top pign", 25.5, 20);
	DessertPushBack(temp);
	
	
	while(ArrayDessertHead != NULL){
		
		printf("%s\n%d\n%f\n%d\n%s\n%s\n", ArrayDessertHead->food_name, ArrayDessertHead->food_price, ArrayDessertHead->dessert_calories, ArrayDessertHead->dessert_cooking_time, ArrayDessertHead->dessert_topping, ArrayDessertHead->created_at);
		ArrayDessertHead = ArrayDessertHead->next;
	}
	

	
}
