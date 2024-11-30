#include<stdio.h>
#include<stdlib.h>

struct Day
{
    char *dayName;
    int date;
    char *activiyt;
};
{
    day -> dayName = (char *) malloc (sizeof(char)*20);
    day -> activiyt = (char *) malloc (sizeof(char)*100);

    printf("Enter the Day Name: ");
    scanf("%s",day ->dayName);

    printf("Enter the Date: ");
    scanf("%d",&day->date);

    printf("Enter the activity for the day :");
    scanf("%s", day->activiyt);
    
}

void read(struct Day *calender,int size)
{
    for(int i=0; i<size; i++)
    {
        printf("Enter details for the day %d:\n",i+1);
        create(&calender[i]);
    }
}

void display(struct Day *calender,int size)
{
    printf("\nWeek's Activity Details: ");
    for(int i=0; i<size; i++)
    {
        printf("Day %d:\n",i+1);
        printf("Day Name: %s\n",calender[i].dayName);
        printf("Date : %d\n",calender[i].date);
        printf("Activity: %s\n",calender[i].activiyt);
        printf("\n");
    }
}

void freeMemory(struct Day *calender, int size)
{
    for(int i =0; i<size; i++)
    {
        free(calender[i].dayName);
        free(calender[i].activiyt);
    }
    free(calender);
}

int main()
{

    int size;
    printf("Enter the name of the days in the week: ");
    scanf("%d",&size);

    struct Day *calender = (struct Day*)malloc(sizeof(struct Day) śś*size);

    if(calender == NULL)
    {
        printf("Memory allocation failed.exiting program");

        return 1;
    }

    read(calender,size);
    display(calender,size);

    freeMemory(calender,size);
    // free(calender);

    return 0;
}

