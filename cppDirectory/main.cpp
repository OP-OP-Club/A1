#include<stdio.h>
#include "../hDirectory/global.h"
#include "../hDirectory/Tugas-4.h"

int main(){

    //buat debug nambahin 4 makanan:
        strcpy(ArrayDessert[0].food_name, "Lime Ball");
        ArrayDessert[0].food_price = 20;
        strcpy(ArrayDessert[0].dessert_topping,  "Honey");
        ArrayDessert[0].dessert_calories = 15.50;
        ArrayDessert[0].dessert_cooking_time = 62;

        strcpy(ArrayDessert[1].food_name, "ChocoLava");
        ArrayDessert[1].food_price = 15;
        strcpy(ArrayDessert[1].dessert_topping,  "Caramel");
        ArrayDessert[1].dessert_calories = 2.50;
        ArrayDessert[1].dessert_cooking_time = 64;

        DessertLen = 2;

        strcpy(ArrayDrink[0].food_name, "Mojito");
        ArrayDrink[0].food_price = 15;
        strcpy(ArrayDrink[0].drink_flavor, "Mint");
        ArrayDrink[0].drink_size = 'M';
        ArrayDrink[0].drink_cooking_time = 10;

        strcpy(ArrayDrink[1].food_name, "Coca Cola");
        ArrayDrink[1].food_price = 10;
        strcpy(ArrayDrink[1].drink_flavor, "Mix Berry");
        ArrayDrink[1].drink_size = 'S';
        ArrayDrink[1].drink_cooking_time = 20;

        DrinkLen = 2;

    for(int i=0;i<8;i++){
        showCookingProcess();
    }
    return 0;
}
