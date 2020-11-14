#include <stdio.h>
#include "global.h"

void showCookingProcess(){

        ClearScreen();

        int flag = 0; //tanda apakah ada yang masih dimasak ato nggak (0 = tidak)
        int numberProcess=1;
        //cek apakah struct dessert/drink ada isinya ato nggak, kalo ga ada berarti ga ada yang dimasak --> flag = 0
        if(DessertLen != 0 || DrinkLen != 0){
            flag = 1;
        }

        int DessertFlag[500] = {};
        int DrinkFlag[500] = {};
        for(int i=0;i<DessertLen;i++){
            if(ArrayDessert[i].dessert_cooking_time == 0){
                DessertFlag[i] = 1;
             }
        }
        for(int i=0;i<DrinkLen;i++){
            if(ArrayDrink[i].drink_cooking_time == 0){
                DrinkFlag[i] = 1;
             }
        }

        //kalau ada yg udah ada isi, apakah lagi dimasak ato nggak (cooking time > 0)
        if(flag == 1){
            //bikin flag jadi 0 lagi karena bisa aja semua isinya cooking time == 0
            flag = 0;
            //cek dessert dan kurangi 10 detik
            if(DessertLen != 0){
                for(int i=0;i<DessertLen;i++){
                    ArrayDessert[i].dessert_cooking_time-=10;
                    if(ArrayDessert[i].dessert_cooking_time<=0) {
                        ArrayDessert[i].dessert_cooking_time=0;
                        if(DessertFlag[i] == 0){
                            PROFIT += ArrayDessert[i].food_price;
                        }
                    }
                    if(ArrayDessert[i].dessert_cooking_time > 0){
                        flag = 1;
                    }
                }
            }
            //cek drink dan kurangi 10 detik
            if(DrinkLen != 0){
                for(int i=0;i<DrinkLen;i++){
                    ArrayDrink[i].drink_cooking_time-=10;
                    if(ArrayDrink[i].drink_cooking_time<=0){
                        ArrayDrink[i].drink_cooking_time=0;
                        if(DrinkFlag[i] == 0){
                            PROFIT += ArrayDrink[i].food_price;
                        }
                    }
                    if(ArrayDrink[i].drink_cooking_time > 0){
                        flag = 1;
                    }
                }
            }   
        }

        //kalau misal flag==0 berarti ga ada yg lagi cooking progress/ga ada isi struct array nya
        if(flag == 0){
            //printf("Profit: $%d\n\n", PROFIT);
            printf("There is no Dessert or Drink on the list!\n\n");
            printf("Press Enter to continue");
            getchar();
        }else{
            //printf("Profit: $%d\n\n", PROFIT);
            //ini kalau misalkan ada cooking process
            puts("| No  | Type          | Name                    | Price  | Time Left |");
            puts("----------------------------------------------------------------------");
            for(int j=0;j<DessertLen;j++){
                if(ArrayDessert[j].dessert_cooking_time > 0){
                    printf("| %-3d | Dessert       | %-24s| $%-3d   | %-2d      s |\n", numberProcess, ArrayDessert[j].food_name , ArrayDessert[j].food_price, ArrayDessert[j].dessert_cooking_time);
                    numberProcess++;
                }
            }

            for(int j=0;j<DrinkLen;j++){
                if(ArrayDrink[j].drink_cooking_time > 0){
                    printf("| %-3d | Drink         | %-24s| $%-3d   | %-2d      s |\n", numberProcess, ArrayDrink[j].food_name , ArrayDrink[j].food_price, ArrayDrink[j].drink_cooking_time);
                    numberProcess++;
                }
            }
            printf("\n");
            printf("Press Enter to return to main menu\n");
            getchar();
        }
}
