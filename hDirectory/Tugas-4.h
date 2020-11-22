//mau ganti linked list, testing push
#include <stdio.h>
#include "global.h"

//bikin linked list buat flagging.. karena ini cara yg pertama kali gw kepikiran wkwkwk -Gerson
//intinya gw ga ngubah banyak sih, beneran cuma ganti array jadi linked list :v
//jangan lupa free abis selesai jalanin ni fungsi, ntar kyk di video orang turki yg main drum sambil nyanyi ievan polkka
struct FlagNode{
    int flag;
    FlagNode *next;
};

struct FlagNode *FlagDessertHead = NULL;
struct FlagNode *FlagDessertTail = NULL;
struct FlagNode *FlagDrinkHead = NULL;
struct FlagNode *FlagDrinkTail = NULL;

FlagNode *createFlag(int flag){
    FlagNode *newFlag = (FlagNode*) malloc(sizeof(FlagNode));
    newFlag->flag = flag;
    newFlag->next = NULL;
    return newFlag;
}

//semua flag nanti pushTail
void AddFlagDessert(int flag){
    FlagNode *newFlag = createFlag(flag);
    if(FlagDessertHead == NULL){
        FlagDessertHead = FlagDessertTail = newFlag;
    }
    else{
        FlagDessertTail->next = newFlag;
        FlagDessertTail = newFlag;
    }
}

void AddFlagDrink(int flag){
    FlagNode *newFlag = createFlag(flag);
    if(FlagDrinkHead == NULL){
        FlagDrinkHead = FlagDrinkTail = newFlag;
    }
    else{
        FlagDrinkTail->next = newFlag;
        FlagDrinkTail = newFlag;
    }
}


//fungsi buat free semua flag (popAll)
void clearFlag(){
    //popALl dessert
    FlagNode *curr = FlagDessertHead;
    while(curr){
        //popHead dessert
        if(FlagDessertHead == FlagDessertTail){
            FlagDessertHead = FlagDessertTail = NULL;
            free(FlagDessertHead);
        }
        else{
            FlagNode *del = FlagDessertHead;
            FlagDessertHead = FlagDessertHead->next;
            del = NULL;
            free(del);
        }
        //next
        curr = curr->next;
    }
    //popAll drink
    curr = FlagDrinkHead;
    while(curr){
        //popHead drink
        if(FlagDrinkHead == FlagDrinkTail){
            FlagDrinkHead = FlagDrinkTail = NULL;
            free(FlagDrinkHead);
        }
        else{
            FlagNode *del = FlagDrinkHead;
            FlagDrinkHead = FlagDrinkHead->next;
            del = NULL;
            free(del);
        }
        //next
        curr = curr->next;
    }
}

//baru masuk proses sebenernya
void showCookingProcess(){

        Dessert *currDessert;
        Drink *currDrink;
        FlagNode *currFlag;

        ClearScreen();

        int flag = 0; //tanda apakah ada yang masih dimasak ato nggak (0 = tidak)
        int numberProcess=1;
        //cek apakah struct dessert/drink ada isinya ato nggak, kalo ga ada berarti ga ada yang dimasak --> flag = 0
        if(ArrayDessertHead != NULL || ArrayDrinkHead != NULL){
            flag = 1;
        }

        currDessert = ArrayDessertHead;
        while(currDessert){
            currDessert->dessert_cooking_time == 0 ? AddFlagDessert(1) : AddFlagDessert(0);
            currDessert = currDessert->next;
        }
        
        currDrink = ArrayDrinkHead;
        while(currDrink){
            currDrink->drink_cooking_time == 0 ? AddFlagDrink(1) : AddFlagDrink(0);
            currDrink = currDrink->next;
        }

        //kalau ada yg udah ada isi, apakah lagi dimasak ato nggak (cooking time > 0)
        if(flag == 1){
            //bikin flag jadi 0 lagi karena bisa aja semua isinya cooking time == 0
            flag = 0;
            //cek dessert dan kurangi 10 detik
            if(ArrayDessertHead != NULL){
                currDessert = ArrayDessertHead;
                while(currDessert){
                    if(currDessert->dessert_cooking_time > 0){
                        flag = 1;
                        break;
                    }
                    currDessert = currDessert->next;
                }
            }
            //cek drink dan kurangi 10 detik
            if(flag == 0 && ArrayDrinkHead != NULL){
                currDrink = ArrayDrinkHead;
                while(currDrink){
                    if(currDrink->drink_cooking_time > 0){
                        flag = 1;
                        break;
                    }
                    currDrink = currDrink->next;
                }
            }
        }

        //kalau misal flag==0 berarti ga ada yg lagi cooking progress/ga ada isi struct array nya
        if(flag == 0){
            printf("Profit: $%d\n\n", PROFIT);
            printf("There is no Dessert or Drink on the list!\n\n");
            printf("Press Enter to continue");
            getchar();
        }else{
            printf("Profit: $%d\n\n", PROFIT);
            //ini kalau misalkan ada cooking process
            puts("| No  | Type          | Name                    | Price  | Time Left |");
            puts("----------------------------------------------------------------------");

            currDessert = ArrayDessertHead;
            currFlag = FlagDessertHead;
            while(currDessert && currFlag){
                if(currDessert->dessert_cooking_time>0){
                    printf("| %-3d | Dessert       | %-24s| $%-3d   | %-2d      s |\n", numberProcess, currDessert->food_name , currDessert->food_price, currDessert->dessert_cooking_time);
                    numberProcess++;
                    currDessert->dessert_cooking_time-=10;
                    if(currDessert->dessert_cooking_time<=0) {
                        currDessert->dessert_cooking_time=0;
                        if(currFlag->flag == 0){
                            PROFIT += currDessert->food_price;
                        }
                    }
                }
                currDessert = currDessert->next;
                currFlag = currFlag->next;
            }

            currDrink = ArrayDrinkHead;
            currFlag = FlagDrinkHead;
            while(currDrink && currFlag){
                if(currDrink->drink_cooking_time>0){
                    printf("| %-3d | Drink         | %-24s| $%-3d   | %-2d      s |\n", numberProcess, currDrink->food_name , currDrink->food_price, currDrink->drink_cooking_time);
                    numberProcess++;
                    currDrink->drink_cooking_time-=10;
                    if(currDrink->drink_cooking_time<=0) {
                        currDrink->drink_cooking_time=0;
                        if(currFlag->flag == 0){
                            PROFIT += currDrink->food_price;
                        }
                    }
                }
                currDrink = currDrink->next;
                currFlag = currFlag->next;
            }

            printf("\n");
            printf("Press Enter to return to main menu\n");
            getchar();
        }
        clearFlag();
}
