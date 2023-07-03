#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct Room
{
    int RoomID;
    int status;
    char customerName[20];
};
struct Room hotel[MAX];
int checkHotel(){
    int empty = 1, full = 1;
    for (int i = 0; i < 5; i++){
        if (hotel[i].status == 1) empty = 0;
        if (hotel[i].status ==0)full = 0;}
    if(empty == 1)return 0;
    if(full == 1)return 1;
    return 2; }
void listOccupiedRooms(){
    printf("listOccupiedRooms():\n");
    if(checkHotel()==0){
            puts("The hotel is empty");
            return;}
    for (int i = 0; i < 5; i++){
        if (hotel[i].status == 1){
            printf("roomID: %d\n", hotel[i].RoomID);
            printf("customer name: %s\n", hotel[i].customerName);}}
    return;
};
void assignRoom(){
    int select = 0;
    char name[20];
    puts("assignRoom():");
    if(checkHotel() == 1){
        puts("The hotel is full");
        return; }
    do{
    puts("Enter a roomID between 1 and 5:");
    scanf("%d", &select);
    if(select >= 1 && select <= 5){
        if (hotel[select-1].status == 1){
            puts("Occupied! Enter another roomID");}
        else {break;}}
    }while(1);
    puts("Enter customer name:");
    scanf(" %19[^\n]", &name);
    hotel[select-1].status = 1;
    strcpy(hotel[select-1].customerName, name);
    puts("The room has been assigned successfully");
    return;
};
void removeRoom(){
    int select, valid;
    valid = select = 0;
    puts("removeRoom():");
    if(checkHotel()==0){
        puts("All the rooms are empty");
        return;}
    do{
    puts("Enter a roomID between 1 and 5:");
    scanf("%d",&select );
    if(select >= 1 && select <= 5){
        if (hotel[select-1].status == 1) {
            break; }
        else{puts("Empty! Enter another roomID for removal");}}
    }while(1);
    hotel[select-1].status = 0;
    puts("Removal is successful");
    return;
};
void findCustomer(){
    char name[20];
    int match = -1, j = 0;
    puts("findCustomer():");
    puts("Enter customer name:");
    scanf(" %19[^\n]",&name);
    for(int i = 0; i < MAX; i++){
        if (match == -1){
        if (hotel[i].status == 1){
            for(j=0; hotel[i].customerName[j]!=0; j++){
                if(name[j]-hotel[i].customerName[j]!=32 && hotel[i].customerName[j]-name[j]!=32 &&name[j]!=hotel[i].customerName[j]
                   ||(name[j]==0&& hotel[i].customerName[j]!=0)){
                       break; }
        if(hotel[i].customerName[j+1]==0 && name[j+1]==0 ){
            match = i;break;}}}}}
    if(match!=-1){
        puts("The target customer name is found");
        printf("roomID: %d\n", match+1);
        printf("customer name: %s\n", hotel[match].customerName);}
    else{puts("The target customer name is not found");}
    return;
};
int main(){
    for (int i=0;i<MAX; i++){
    hotel[i].RoomID = i+1;}
    int choice;
    puts("NTU HOTEL ROOM RESERVATION PROGRAM: ");
    puts("1: listOccupiedRooms()");
    puts("2: assignRoom()");
    puts("3: removeRoom()");
    puts("4: findCustomer()");
    puts("5: quit");
    do{
    puts("Enter your choice:");
    scanf("%d", &choice);
    switch (choice){
    case 1:
        listOccupiedRooms();
        break;
    case 2:assignRoom();break;
    case 3:removeRoom();break;
    case 4:
        findCustomer();
        break;
    default: break;}
    }while (choice!=5);
    return 0;
}
