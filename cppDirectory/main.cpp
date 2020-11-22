#include<stdio.h>
#include<time.h>
#include "../hDirectory/Tugas-2.h"

int main(){
    //ini buat testing di branch Tugas-4 
    struct Dessert *temp = CreateDessertNodes((char *) "Lime Ball", 20,  (char*) "Honey", 15.50, 62);
	DessertPushBack(temp);
	temp = CreateDessertNodes((char *) "ChocoLava", 15,  (char*) "Caramel", 2.50, 64);
	DessertPushBack(temp);

    struct Drink *drink = CreateDrinkNodes((char*) "Mojito", 15, (char*) "Mint", 'M', 10);
    DrinkPushBack(drink);
    drink = CreateDrinkNodes((char*) "Coca Cola", 10, (char*) "Mix Berry2", 'S', 20);
    DrinkPushBack(drink);

	operCookedMainMenu();

    return 0;
}
