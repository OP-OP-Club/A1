#ifndef GLOBAL_VARIABLE
#define GLOBAL_VARIABLE 1

#include<stdlib.h>

//Variabel Global Profit
int PROFIT = 0;

//Struct Global & Counter Struct Global
struct Dessert {
    char food_name[500];
    int food_price;
    char dessert_topping[20];
    float dessert_calories;
    int dessert_cooking_time;

    // struct Dessert *next;
};

struct Drink {
    char food_name[500];
    int food_price;
    char drink_flavor[20];
    char drink_size;
    int drink_cooking_time;

    // struct Drink *next;
};

struct Dessert ArrayDessert[500];
struct Drink ArrayDrink[500];

int DessertLen = 0;
int DrinkLen = 0;

//ClearScreen
void ClearScreen(){
    for(int i = 0; i < 50; i++){
        puts("");
    }
}

//Pengganti Strlen pada string.h
int strlen(char arr[]){
    int count = 0;

    for(int i = 0; arr[i] != '\0'; i++){
        count++;
    }

    return count;
}

// 0 -> not same, 1 -> Same , case SENSTIVIE
int strCmp(char string1[], char string2[]){
    if(strlen(string1) != strlen(string2)){
        return 0;
    }

    int stringlen = strlen(string1);
    for(int i = 0; i < stringlen; i++){
        if(string1[i] != string2[i]){
            return 0;
        }
    }

    return 1;
}

// 0 -> not same, 1 -> Same , case INSENSITIVE
int strCaseCmp(char string1[], char string2[]){
    if(strlen(string1) != strlen(string2)){
        return 0;
    }

    int stringlen = strlen(string1);
    for(int i = 0; i < stringlen; i++){
        if(string2[i] >= 'A' && string2[i] <= 'Z'){
            string1[i] += 32;
        }
        
        if(string2[i] >= 'A' && string2[i] <= 'Z'){
            string1[i] += 32;
        }

        if(string1[i] != string2[i]){
            return 0;
        }
    }

    return 1;
}

void strCpy(char arr1[], char arr2[]){
    int arr2len = strlen(arr2);

    int index = 0;

    for(int i = 0; i < arr2len; i++){
        arr1[i] = arr2[i];
        index++;
    }

    arr1[index] = '\0';
}


// struct Dessert* InitializeDessertLinkedList(){
//     return (struct Dessert*) malloc (sizeof(struct Dessert));
// }

// struct Drink* InitializeDrinkLinkedList(){
//     return(struct Drink*) malloc(sizeof(struct Drink));
// }

// struct Dessert* CreateDessertNodes(char food_name[500], int food_price, char dessert_topping[20], float dessert_calories, int dessert_cooking_time){
//     struct Dessert *temp = InitializeDessertLinkedList();
    
//     strcpy(&temp->food_name, food_name);
//     // temp->food_name = food_name;
//     temp->food_price = food_price;
//     temp->dessert_topping = dessert_topping;
//     temp->dessert_calories = dessert_calories;
//     temp->dessert_cooking_time = dessert_cooking_time;
//     temp->next = NULL;
    
//     return temp;
// }

// struct Drink* CreateDrinkNodes(char food_name[500], int food_price, char drink_flavor[20], float drink_size, int drink_cooking_time){
//     struct Drink *temp = InitializeDrinkLinkedList();
//     temp->food_name = food_name;
//     temp->food_price = food_price;
//     temp->drink_flavor = drink_flavor;
//     temp->drink_size = drink_size;
//     temp->drink_cooking_time = drink_cooking_time;
//     temp->next = NULL;
    
//     return temp;
// }

// void DessertPushBack(struct Dessert **head , struct Dessert **tail, struct Dessert* add){
//     if((*head) != NULL){
//         *head = *tail = add;
//     }
//     else{
//         (*tail)->next = add;
//         (*tail) = (*tail)->next;
//     }
// }

// void DrinkPushBack(struct Drink **head, struct Drink **tail, struct Drink* add){
//     if((*head) != NULL){
//         *head = *tail = add;
//     }
//     else{
//         (*tail)->next = add;
//         (*tail) = (*tail)->next;
//     }
// }

#endif