#include <stdio.h>
#include "global.h"

void showCookingProcess(){
        ClearScreen();
        int flag = 0; //tanda apakah ada yang masih dimasak ato nggak (0 = tidak)

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
        }
}