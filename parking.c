#include <stdio.h>
#include <string.h>
#include <time.h>


// input vehicle type, subcategory, model, vehicle no, owner name, contact no

struct vehicle{
    int type;
    int subcategory;
    char model[20];
    char vehicle_no[15];
    char name[20];
    char contact_no[15];
    int hour;
    int min;
    int sec;
    int cost;
};

struct vehicle user;
struct vehicle user_rewrite[1000];
int user_counter = 0;

int entry();
int entry_receipt();
int two_wheeler();
int four_wheeler();
int commercial();
int user_Details();
int exiter();
int time_difference();
FILE *data;
FILE *backlog;
int global_hour;
int global_min;
int global_sec;
int global_cost;



int main() {
    int start;
    printf("\t\t***WELCOME TO GRAND LEVEL PARKING***\n\n");
    printf("What do you want to do?\n");
    printf("1. Entry\n");
    printf("2. Exit: ");
    scanf("%d",&start);
    printf("\n");
    if (start==1) {
        entry();
    }
    else if (start==2) {
        //searcher();
        exiter();
    }
    return 0;
}

int entry() {
    //int type;
    int total=10;
    printf("Select vehicle type\n");
    printf("1. Two wheeler\n");
    printf("2. Four wheeler\n");
    printf("3. Commercial Transport Vehicle: ");
    scanf("%d",&user.type);
    printf("\n");
    if (user.type==1){
        two_wheeler();
    }
    else if (user.type==2) {
        four_wheeler();
    }
    else if (user.type==3) {
        commercial();
    }
    user_counter+=1;
    //printf("Spaces left = %d",user_counter);
}

int two_wheeler() {
    int sub;
    printf("Select sub-category\n");
    printf("1. Cylce (Rs. 5/hr)\n");
    printf("2. Scooty (Rs. 10/hr)\n");
    printf("3. Bike (Rs. 10/hr): ");
    scanf("%d",&sub);

    if (sub==1) {
        user.cost=5;
    }
    else {
        user.cost=10;
    }

    user_Details();
    printf("Here is your Entry receipt...\n\n");
    entry_receipt();
}

int four_wheeler() {
    int sub;
    printf("Select sub-category\n");
    printf("1. Mirco (Rs. 20/hr)\n");
    printf("2. Sedan (Rs. 25/hr)\n");
    printf("3. SUV (Rs. 30/hr): ");
    scanf("%d",&sub);

    if (sub==1) {
        user.cost=20;
    }
    else if (sub==2) {
        user.cost=25;
    }
    else {
        user.cost=30;
    }

    user_Details();
    printf("Here is your Entry receipt...\n\n");
    entry_receipt();
}

int commercial() {
    int sub;
    printf("Select sub-category\n");
    printf("1. Tempo (Rs. 15/hr)\n");
    printf("2. Truck (Rs. 35/hr)\n");
    printf("3. Bus (Rs. 35/hr): ");
    scanf("%d",&sub);

    if (sub==1) {
        user.cost=15;
    }
    else {
        user.cost=35;
    }

    user_Details();
    printf("Here is your Entry receipt...\n\n");
    entry_receipt();
}

int user_Details() {
    data = fopen("D:\\Temp. Folder\\Programming\\C\\ok\\Entry_details2.txt","a");
    printf("\nEnter name: ");
    scanf("%s",user.name);
    printf("Enter contact no: ");
    scanf("%s",user.contact_no);
    printf("Enter vehicle no: ");
    scanf("%s",user.vehicle_no);
    printf("Enter model: ");
    scanf("%s",user.model);
    /*
    fprintf(data,"Owner name: %s\n",user.name);
    fprintf(data,"Owner contact no: %s\n",user.contact_no);
    fprintf(data,"Vehicle no: %s\n",user.vehicle_no);
    fprintf(data,"Vehicle model: %s\n",user.model);
    */
    time_difference();
    user.hour=global_hour;
    user.min=global_min;
    user.sec=global_sec;
    fwrite(&user, sizeof(struct vehicle), 1, data);
}

int entry_receipt() {
    time_t t;
    time(&t);
    printf("***************************************\n");
    printf("%s\n", ctime(&t));
    printf("Owner name: %s\n",user.name);
    printf("Owner contact no: %s\n",user.contact_no);
    printf("Vehicle no: %s\n",user.vehicle_no);
    printf("Vehicle model: %s\n",user.model);
    printf("***************************************");
}

int searcher(char vehicle_details_matcher[100]) {
    data = fopen("D:\\Temp. Folder\\Programming\\C\\ok\\Entry_details2.txt","r");
    backlog = fopen("D:\\Temp. Folder\\Programming\\C\\ok\\backlog.txt","a");
    time_t t;
    time(&t);
    //time_t seconds;
    //struct tm *timeStruct;
    //seconds = time(NULL);
    //timeStruct = localtime(&seconds);

    //fscanf(data,"%s",&num);
    //printf("the value is %s",num);
    time_difference();
    while(fread(&user, sizeof(struct vehicle), 1, data)) {
        if (strcmp(user.vehicle_no,vehicle_details_matcher)==0) {
            int difference=global_hour-user.hour;
            if (difference<1) {
                global_cost=user.cost*1;
            }
            else {
                global_cost=user.cost*difference;
            }
            printf("***************************************\n");
            printf("%s\n", ctime(&t));
            printf("Owner name: %s\n",user.name);
            printf("Owner contact no: %s\n",user.contact_no);
            printf("Vehicle no: %s\n",user.vehicle_no);
            printf("Vehicle model: %s\n",user.model);
            printf("You have to pay Rs.%d\n",global_cost);
            printf("THANKYOU! PLEASE VISIT AGAIN.\n");
            printf("***************************************");
            fwrite(&user, sizeof(struct vehicle), 1, backlog);
            deletespecific(vehicle_details_matcher);
            break;
        }
    }
}

int exiter() {
    char vehicle[100];
    printf("Enter vehicle no: ");
    scanf("%s",vehicle);
    searcher(vehicle);
}

int time_difference() {
    time_t seconds;
    struct tm *timeStruct;

    seconds = time(NULL);

    timeStruct = localtime(&seconds);

    global_hour=timeStruct->tm_hour;
    global_min=timeStruct->tm_min;
    global_sec=timeStruct->tm_sec;
}

int t=0;
void readdata()
{
    int i=0;

    data=fopen("D:\\Temp. Folder\\Programming\\C\\ok\\Entry_details2.txt","r");
    while(fread(&user_rewrite[i],sizeof(struct vehicle),1,data)==1)
    {
        i++;
        t++;
    }
    fclose(data);
}
void deletespecific(char vehicle_details_matcher[100])
{
    readdata();
    data=fopen("D:\\Temp. Folder\\Programming\\C\\ok\\Entry_details2.txt","w");
    for (int w=0;w<t;w++)
    {
        if(strcmp(user_rewrite[w].vehicle_no, vehicle_details_matcher)==1)
        {
            fwrite(&user_rewrite[w],sizeof(user_rewrite[w]),1,data);
        }
    }
    fclose(data);
 }
