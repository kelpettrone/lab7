#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
        char stateAbbrev[3];
        char name[20];
        char capital[20];
        int  yearUnion;
}state;
int readin(FILE *fp, state data[MAX]);
void dataList(state data[MAX], int count);
void abbrevInfo(int count, state data[MAX]);
void ordernew(state data[MAX], int count);

int main(){
        state data[MAX];
        FILE *fp;
        char infile[20];
        int size;
        printf("enter a file name: ");

        scanf("%s", infile);
        fp = fopen(infile,"r");
        int choice;
        int flag = 1;
        int count;
        count = readin(fp,data);


        while(flag = 1) {
        printf("1: list all data\n 2: list a states info based on abbreviation\n"
                "3: list a states capital based on it's abbreviation\n"
                "4: list states who joined during a given year\n"
                "5 list states in the order of joining the union\n"
                "6: quit\n"
                "enter a choice:");
                scanf("%d", choice);
                switch (choice) {
                case 1: {
                dataList(data,count);
                }
                break;
                case 2: {
                abbrevInfo(count,data);
                }
                break;
                case 3:{
                     break;
                }
                case 4:{
                break;
                }
                case 5:{
                ordernew(data, count);
                break;
                }
                case 6: {
                printf("goodbye");
                flag =0;
                break;
                }
                default:
                printf("didnt enter an option");
                }
        }

//int count;
//count = readin(fp,data);
//abbrevInfo(count, data);
//order(data, count);
        return 0;
}
int readin(FILE *fp, state data[MAX]){
state p;

int count =0;
char line[300];
while(1) {
 //     data[count]=fscanf(fp,"%s,%s,%s,%d", p.stateAbbrev, p.name, p.capital, &p.yearUnion)
        fgets(line, 300, fp);
//      printf("%s,%s,%s,%d", p.stateAbbrev, p.name, p.capital, p.yearUnion);
        //printf("%s\n", line);
        if (feof(fp)) break;
        strcpy(data[count].stateAbbrev, strtok(line,","));
        strcpy(data[count].name, strtok(NULL,","));
        strcpy(data[count].capital, strtok(NULL,","));
        data[count].yearUnion= atoi(strtok(NULL,"\n"));
        //printf("%s, %s, %s, %d \n", data[count].stateAbbrev, data[count].name, data[count].capital, data[count].yearUnion);
        count++;

}
return count;
}

void dataList(state data[MAX], int count){
        int i;
        for (i=0;i<count-1;i++){
                printf("%s, %s, %s, %d \n", data[i].stateAbbrev, data[i].name, data[i].capital, data[i].yearUnion);
        }
}




void abbrevInfo(int count, state data[MAX]){
        char userAbbrev[3];
        printf("Enter the states Abbreviation: ");
        scanf("%s", userAbbrev);
        int i;
        for(i=0; i<count; i++) {
                if(strstr(data[i].stateAbbrev, userAbbrev))
                printf("%s, %s, %s, %d\n", data[i].stateAbbrev, data[i].name, data[i].capital, data[i].yearUnion);
        }
}


void ordernew(state data[MAX], int count) {

//qsort(data.yearUnion, count, sizeof(int), compare)
int i, j;
state temp;
for(i=0; i<count-1; i++) {
        for(j=0; j< (count-1-i);j++)
        {
                if (data[j].yearUnion < data[j+1].yearUnion)
                {
                        temp=data[j];
                        data[j]=data[j+1];
                        data[j+1]=temp;
                }
        }
for(i=0; i<count; i++) {
        printf("%s, %d\n", data[i].name, data[i].yearUnion);
        }


}
}
void order(state data[MAX], int count) {
        int temp;
        int arr[count];
        int i;
        state p;
         for(i=0; i<count; i++){
                arr[i]=data[i].yearUnion;
        }
        int j;
        for(i=0;i<count-1;i++){
                        for(j=0;j<count-1;j++){
                                if(arr[j]>arr[j+1]){
                                temp = arr[j+1];
                                arr[j+1]=arr[j];
                                arr[j]=temp;

                                }
                        }
        }
        for(i=0;i<count;i++){
                printf("%d\n", arr[i]);
        }

}
                                             
                             
                                    
