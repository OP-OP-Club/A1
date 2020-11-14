#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "hDirectory/global.h"


void addDesertAndBeverage(){
  int choice = 0, foodPrice = 0;
  char foodName[105];

  printf("What do you want to add?\n");
  printf("1. Dessert\n");
  printf("2. Drinks\n");
  do{
    printf("Choose: ");
    scanf("%d", &choice);
  }while (choice < 1 || choice > 2);

  do{
    getchar();
    printf("Input the name [at least 5 characters]: ");
    scanf("%[^\n]", foodName);
  }while (strlen(foodName) < 5);

  do{
    getchar();
    printf("Input the price [10 - 500]: $");
    scanf("%d", &foodPrice);
  }while(foodPrice < 10 || foodPrice > 500);

  srand(time(NULL));
  if (choice == 1){
    char topping[105];
    float calories = 0;
    int cookTime = 0;
    int same = 0, idx = 0;
    do{
        char top[3][20] = {"Caramel", "Honey", "Syrup"};
        same = 0, idx = 0;
        printf("Input the topping ['Caramel' | 'Honey' | 'Syrup'(Case insensitive): ");
        scanf("%s", topping);
        

        for (int i = 0; i < 3; i++)  {
            same = strCaseCmp(topping, top[i]);
            if (same){
                idx = i;
                break;
            }
        }  
    } while (same == 0);

    do{
        printf("Insert Calories [1.00 - 99.00]: ");
        scanf("%f", calories);
    } while (calories < 1.00 || calories > 99.00);
    
    cookTime = (rand() % 41) + 50;
    if (idx == 0)
        cookTime += 10;
    else if (idx == 1)
        cookTime += 15;
    else if (idx == 2)
        cookTime += 20;

    strCpy(ArrayDessertMenu[DessertMenuLen].food_name, foodName);
    ArrayDessertMenu[DessertMenuLen].food_price = foodPrice;
    strCpy(ArrayDessertMenu[DessertMenuLen].dessert_topping, topping);
    ArrayDessertMenu[DessertMenuLen].dessert_calories = calories;
    ArrayDessertMenu[DessertMenuLen].dessert_cooking_time = cookTime;
    DessertLen++;

  }else{
    char flavor[105];
    int same = 0, idx = 0;
    int cookTime = 0;
    do{
        char flav[3][20] = {"Mint", "Mix Berry", "Cheese"};
        printf("Input the flavor ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
        getchar();
        scanf("%[^\n]", flavor);
        for (int i = 0 ; i < 3; i++){
            same = strCmp(flav[i], flavor);
            if (same)
            {
                idx = i;
                break;
            }
        }
    } while (same == 0);
    
    char size;
    int sizeFlag = 0;
    do{
        printf("Input the size [S | M | L](Case Sensitive): ");
        getchar();
        scanf("%c", &size);
        if (size == 'S' || size == 'M' || size == 'L'){
            sizeFlag = 1;
        }
    } while (sizeFlag == 0);

    cookTime = (rand() % 41) + 10;
    if (idx == 0)
        cookTime += 10;
    else if (idx == 1)
        cookTime += 20;
    else if (idx == 2)
        cookTime += 30;

    strCpy(ArrayDrinkMenu[DrinkMenuLen].food_name, foodName);
    ArrayDrinkMenu[DrinkMenuLen].food_price = foodPrice;
    strCpy(ArrayDrinkMenu[DrinkMenuLen].drink_flavor, flavor);
    ArrayDrinkMenu[DrinkMenuLen].drink_size = size;
    ArrayDrinkMenu[DrinkMenuLen].drink_cooking_time = cookTime;
    DrinkMenuLen++;
  }
  printf("Succesfully added a new menu!");
  getchar();
}