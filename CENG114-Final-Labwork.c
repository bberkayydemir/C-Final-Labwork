#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item{
    int itemID;
    char itemType[10];
    int decade;
    char color[10];
    double price; 
};

struct item readFile(struct item items[], int n);

struct item listItems(struct item items[], int n);

struct item showItem(struct item items[], int n);

struct item insertItem(struct item items[], int n);  

struct item removeItem(struct item items[], int n);

struct item updateItem(struct item items[], int n);

struct item sortDecade(struct item items[], int n);

struct item sortPrice(struct item items[], int n);

struct item listType(struct item items[], int n);

struct item newcomers(struct item items[], int n);

int sira = 0;

int main()
{
    int choice, n = 50;                    
    struct item items[n]; 
    printf("Enter your choice: "); 
    scanf("%d", &choice); 
    while(choice != 10){
        if(choice == 0){  
            readFile(items, n); 
        } 
        else if(choice == 1){
            listItems(items, n);
        }
        else if(choice == 2){
            showItem(items, n); 
        }
        else if(choice == 3){
            insertItem(items, n);
        }
        else if(choice == 4){
            removeItem(items, n);
        }
        else if(choice == 5){
            updateItem(items, n);
        }
        else if(choice == 6){
            sortDecade(items, n);
        }
        else if(choice == 7){
            sortPrice(items, n);
        }
        else if(choice == 8){
          //  listType(items, n);  // Actually I don't understand clearly this function because of its logic, so I didn't do it. I'm sorry about that.
        }
        else if(choice == 9){
            newcomers(items, n); 
        }
        else{
            printf("Wrong choice."); 
        }
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    }
    
    return 0;
}  

struct item readFile(struct item items[], int n){
    FILE *fptr;
    fptr = fopen("items.txt", "r"); 
    sira++;
    int i = 0;    
    while(!feof(fptr)){
        fscanf(fptr, "%d / %s / %d / %s / %lf", &items[i].itemID, items[i].itemType, &items[i].decade, items[i].color, &items[i].price);
        printf("%d %s %d %s %.2lf \n", items[i].itemID, items[i].itemType, items[i].decade, items[i].color, items[i].price);
        i++;
    } 
  /*   for(int i = 0; i < sira; i++){ 
        fscanf(fptr, "%d / %s / %d / %s / %lf", &items[i].itemID, items[i].itemType, &items[i].decade, items[i].color, &items[i].price);
        printf("%d %s %d %s %.2lf \n", items[i].itemID, items[i].itemType, items[i].decade, items[i].color, items[i].price);
    } */ 
    fclose(fptr); 
} 

struct item insertItem(struct item items[], int n){
    int itid, same = 0, bug = 0;
    FILE *fptr;
    fptr = fopen("items.txt", "a+");
    if (fptr == NULL) {
        printf("File error!\n");
        bug = 1;    
    }
    printf("Enter item id: ");
    scanf("%d", &itid);
    if(bug != 1){
        for(int i = 0; i < sira; i++){
            fscanf(fptr, "%d / %s / %d / %s / %lf", &items[i].itemID, items[i].itemType, &items[i].decade, items[i].color, &items[i].price);
            if(items[i].itemID == itid){
                printf("The item already listed."); 
                same = 1;
                break;     
            }
        }
        if(same == 0){
            items[sira].itemID = itid; 
            printf("Enter item type: ");
            scanf("%s", items[sira].itemType);
            printf("Enter decade: ");
            scanf("%d", &items[sira].decade);
            printf("Enter color: ");
            scanf("%s", items[sira].color);
            printf("Enter price: ");
            scanf("%lf", &items[sira].price);
            fprintf(fptr, "%d / %s / %d / %s / %.2lf \n", items[sira].itemID, items[sira].itemType, items[sira].decade, items[sira].color, items[sira].price);
            printf("The item added successfully.");
            sira++;
        } 
    }
    fclose(fptr); 
} 

struct item removeItem(struct item items[], int n){
    int itid, bug = 0, same = 0;
    FILE *fptr, *f2ptr;
    f2ptr = fopen("items.txt","r");
    fptr = fopen("items.txt", "w");
    if (fptr == NULL) {
        printf("File error!\n");
        bug = 1;
    }                  
    printf("Enter item id: ");
    scanf("%d", &itid);
    if(bug != 1){
        for(int i = 0; i < sira; i++){
            fscanf(f2ptr, "%d / %s / %d / %s / %lf", &items[i].itemID, items[i].itemType, &items[i].decade, items[i].color, &items[i].price);
            if(items[i].itemID != itid){
                fprintf(fptr, "%d / %s / %d / %s / %.2lf \n", items[i].itemID, items[i].itemType, items[i].decade, items[i].color, items[i].price);
            }
            else{
                same = 1; 
            }
        }
        if(same == 1){
            printf("The item removed.");            
        } 
        else{
            printf("The item couldn't found.");  
        }
    }
    fclose(fptr); 
}

struct item updateItem(struct item items[], int n){
    int bug = 0, same = 0, itid;
    FILE *fptr;
    fptr = fopen("items.txt", "w");
    if (fptr == NULL) {
        printf("File error!\n");
        bug = 1;    
    }
    printf("Enter for updating item id: ");
    scanf("%d", &itid);
    if(bug != 1){                
        for(int i = 0; i < sira; i++){
            fscanf(fptr, "%d / %s / %d / %s / %lf", &items[i].itemID, items[i].itemType, &items[i].decade, items[i].color, &items[i].price);
            if(items[i].itemID != itid){
                fprintf(fptr, "%d / %s / %d / %s / %.2lf \n", items[i].itemID, items[i].itemType, items[i].decade, items[i].color, items[i].price);
            }
            else{
                items[i].itemID = itid; 
                printf("Enter item type: ");
                scanf("%s", items[i].itemType);
                printf("Enter decade: ");
                scanf("%d", &items[i].decade);
                printf("Enter color: ");
                scanf("%s", items[i].color); 
                printf("Enter price: ");
                scanf("%lf", &items[i].price); 
                fprintf(fptr, "%d / %s / %d / %s / %.2lf \n", items[i].itemID, items[i].itemType, items[i].decade, items[i].color, items[i].price);
                same = 1;
            }
        }
        if(same == 1){
            printf("The item updated.");
        } 
        else{
            printf("The item couldn't found.");  
        }
    }
        fclose(fptr);
}

struct item sortDecade(struct item items[], int n){
    int bug = 0;
    FILE *fptr;
    fptr = fopen("items.txt", "w");
    if (fptr == NULL) {
        printf("File error!\n");
        bug = 1;    
    }   
    if(bug != 1){                
        for(int i = 0; i < sira; i++){     
            fscanf(fptr, "%d / %s / %d / %s / %lf", &items[i].itemID, items[i].itemType, &items[i].decade, items[i].color, &items[i].price);
        }
        int c, d, temp;
        for (c = 0 ; c < sira - 1 ; c++) {
            for (d = 0 ; d < sira - c - 1; d++) {
                if (items[d].decade > items[d+1].decade) {
                // Swapping                                      
                temp = items[d].decade;
                items[d].decade = items[d+1].decade;
                items[d+1].decade = temp;
                }
            }
        }
        printf("Sorted for a decade: ");
        for(int i = 0; i < sira; i++)
        {
            fprintf(fptr, "%d / %s / %d / %s / %.2lf \n", items[i].itemID, items[i].itemType, items[i].decade, items[i].color, items[i].price);
        }
    }
}

struct item sortPrice(struct item items[], int n){
    int bug = 0;
    FILE *fptr;
    fptr = fopen("items.txt", "w"); 
    if (fptr == NULL) {
        printf("File error!\n");
        bug = 1;    
    }
    if(bug != 1){                
        for(int i = 0; i < sira; i++){     
            fscanf(fptr, "%d / %s / %d / %s / %lf", &items[i].itemID, items[i].itemType, &items[i].decade, items[i].color, &items[i].price);
        }
        int c, d, temp;
        for (c = 0 ; c < sira - 1 ; c++) {
            for (d = 0 ; d < sira - c - 1; d++) {
                if (items[d].price > items[d+1].price) {
                // Swapping                                      
                temp = items[d].price;
                items[d].price = items[d+1].price;
                items[d+1].price = temp;
                }
            }
        }
        printf("Sorted for a price: ");
        for(int i = 0; i < sira; i++)
        {
            fprintf(fptr, "%d / %s / %d / %s / %.2lf \n", items[i].itemID, items[i].itemType, items[i].decade, items[i].color, items[i].price);
        }
    }
}

struct item listItems(struct item items[], int n){
    FILE *fptr;
    fptr = fopen("items.txt", "r"); 
    sira++;       
    int i = 0;   
    while(!feof(fptr)){         
        fscanf(fptr, "%d / %s / %d / %s / %lf", &items[i].itemID, items[i].itemType, &items[i].decade, items[i].color, &items[i].price);
        fprintf(fptr, "%d / %s / %d / %s / %.2lf \n", items[i].itemID, items[i].itemType, items[i].decade, items[i].color, items[i].price);
        i++;
    }  
    fclose(fptr);
}

struct item showItem(struct item items[], int n){
    int itid, bug = 0; 
    FILE *fptr;
    fptr = fopen("items.txt", "r"); 
    if (fptr == NULL) {
        printf("File error!\n");
        bug = 1;    
    }                  
    printf("Enter item id: ");
    scanf("%d", &itid);
    if(bug != 1){
        for(int i = 0; i < sira; i++){
            fscanf(fptr, "%d / %s / %d / %s / %lf", &items[i].itemID, items[i].itemType, &items[i].decade, items[i].color, &items[i].price);
            if(items[i].itemID == itid){
                fprintf(fptr, "%d / %s / %d / %s / %.2lf \n", items[i].itemID, items[i].itemType, items[i].decade, items[i].color, items[i].price);
            }
        }
    } 
    fclose(fptr);
}

struct item newcomers(struct item items[], int n){
    int bug = 0, bug2 = 0; 
    FILE *fptr;
    fptr = fopen("items.txt", "r"); 
    if (fptr == NULL) {
        printf("File error!\n");
        bug = 1;
    } 
    FILE *f2ptr;
    f2ptr = fopen("newcomer.txt", "w"); 
    if (f2ptr == NULL) {
        printf("File error!\n");
        bug2 = 1;       
    } 
    if(bug != 1 && bug2 != 1){
        for(int i = 0; i < sira; i++){          
            if(i >= sira-3){  
            fscanf(fptr, "%d / %s / %d / %s / %lf", &items[i].itemID, items[i].itemType, &items[i].decade, items[i].color, &items[i].price);
            fprintf(f2ptr, "%d / %s / %d / %s / %.2lf \n", items[i].itemID, items[i].itemType, items[i].decade, items[i].color, items[i].price);
            }
        }
    } 
}
