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

    char arr[100];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(arr, "%d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    strCpy(ArrayDessert[DessertLen].food_name, foodName);
    ArrayDessert[DessertLen] = foodPrice;
    strCpy(ArrayDessert[DessertLen].dessert_topping, topping);
    ArrayDessert[DessertLen].dessert_calories = calories;
    ArrayDessert[DessertLen].dessert_cooking_time = cookTime;
    strCpy(ArrayDessert[DessertLen].created_at, arr);
    DessertLen++;

  }else{
    char flavor[105];
    int same = 0, idx = 0;
    do{
        char flav[3][20] = {"Mint", "Mix Berry", "Cheese"}
        printf("Input the flavor ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
        getchar();
        scanf("%[^\n]", flavor);
        for (int i = 0 ; i < 3; i++){
            same = strcmp(flav[i], flavor);
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
        char sizes[5] = {'S', 'M', 'L'};
        printf("Input the size [S | M | L](Case Sensitive): ");
        getchar();
        scanf("%c", &size);
        for (int i = 0; i < 3; i++){
            sizeFlag = strCmp(sizes[i], size);
            if (sizeFlag)
                break;
        }
    } while (sizeFlag == 0);

    cookTime = (rand() % 41) + 10;
    if (idx == 0)
        cookTime += 10;
    else if (idx == 1)
        cookTime += 20;
    else if (idx == 2)
        cookTime += 30;

    char arr[100];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(arr, "%d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    strCpy(ArrayDrink[DrinkLen].food_name, foodName);
    ArrayDrink[DrinkLen] = foodPrice;
    strCpy(ArrayDrink[DrinkLen].drink_flavor, flavor);
    ArrayDrink[DrinkLen].drink_size = size;
    ArrayDrink[DrinkLen].drink_cooking_time = cookTime;
    strCpy(ArrayDrink[DrinkLen].created_at, arr);
    DrinkLen++;
  }
  printf("Succesfully added a new menu!");
  getchar();
}
