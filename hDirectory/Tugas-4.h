#include <stdio.h>
#include "global.h"

void showCookingProcess(){

        //buat debug nambahin 4 makanan:
        strCpy(ArrayDessert[0].food_name,"Lime Ball");
        ArrayDessert[0].food_price = 20;
        strCpy(ArrayDessert[0].dessert_topping, "Honey");
        ArrayDessert[0].dessert_calories = 15.50;
        ArrayDessert[0].dessert_cooking_time = 62;

        strCpy(ArrayDessert[1].food_name,"ChocoLava");
        ArrayDessert[1].food_price = 15;
        strCpy(ArrayDessert[1].dessert_topping, "Caramel");
        ArrayDessert[1].dessert_calories = 2.50;
        ArrayDessert[1].dessert_cooking_time = 64;

        DessertLen = 2;

        strCpy(ArrayDrink[0].food_name, "Mojito");
        ArrayDrink[0].food_price = 15;
        strCpy(ArrayDrink[0].drink_flavor, "Mint");
        ArrayDrink[0].drink_size = 'M';
        ArrayDrink[0].drink_cooking_time = 10;

        strCpy(ArrayDrink[1].food_name, "Coca Cola");
        ArrayDrink[1].food_price = 10;
        strCpy(ArrayDrink[1].drink_flavor, "Mix Berry");
        ArrayDrink[1].drink_size = 'S';
        ArrayDrink[1].drink_cooking_time = 20;

        DrinkLen = 2;

        ClearScreen();
        int flag = 0; //tanda apakah ada yang masih dimasak ato nggak (0 = tidak)
        int numberProcess=0;
        //cek apakah struct dessert/drink ada isinya ato nggak, kalo ga ada berarti ga ada yang dimasak --> flag = 0
        if(DessertLen != 0 || DrinkLen != 0){
            flag = 1;
        }

        //kalau ada yg udah ada isi, apakah lagi dimasak ato nggak (cooking time > 0)
        if(flag == 1){
            //bikin flag jadi 0 lagi karena bisa aja semua isinya cooking time == 0
            flag = 0;
            //cek dessert
            if(DessertLen != 0){
                for(int i=0;i<DessertLen;i++){
                    if(ArrayDessert[i].dessert_cooking_time > 0){
                        flag = 1;
                        break;
                    }
                }
            }
            //hanya cek drink apabila flag masih 0, krn kan kalau udh ada yg in progress di dessert, pasti flag tetep akan 1
            if(flag == 0 && DrinkLen != 0){
                for(int i=0;i<DrinkLen;i++){
                    if(ArrayDrink[i].drink_cooking_time > 0){
                        flag = 1;
                        break;
                    }
                }
            }
            
        }
        //kalau misal flag==0 berarti ga ada yg lagi cooking progress/ga ada isi struct array nya
        if(flag == 0){
            printf("There is no Dessert or Drink on the list!\n\n");
            printf("Press Enter to continue");
            getchar();
        }else{
            //ini kalau misalkan ada cooking process
            puts("| No  | Type          | Name                    | Price  | Time Left |");
            puts(" ---------------------------------------------------------------------");
            for(int j=0;j<DessertLen;j++)
            {
                printf("| %-2d| Dessert          | %-20s| $%-2d| %-2d         s\n", numberProcess, ArrayDessert[j].food_name , ArrayDessert[j].food_price, ArrayDessert[j].dessert_cooking_time);
                numberProcess++;
            }

            for(int j=0;j<DrinkLen;j++)
            {
                printf("| %-2d| Dessert          | %-20s| $%-2d| %-2d         s\n", numberProcess, ArrayDrink[j].food_name , ArrayDrink[j].food_price, ArrayDrink[j].drink_cooking_time);
                numberProcess++;
            }

            printf("Press Enter to return to main menu");
            getchar();
        }
}
