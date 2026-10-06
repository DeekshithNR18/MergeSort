#include<stdio.h>
#define MAX 100
struct Student
{
    int rollNo;
    char name[30];
    float marks;
};
void merge(struct Student arr[],int left,int mid,int right){

    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    struct Student L[MAX], R[MAX];
    for(i=0;i<n1;i++){
        L[i] = arr[left + i];
    }
    for(j=0;j<n2;j++){
        R[j] = arr[mid + 1 + j];
    }
    i=0;
    j=0;
    k=left;
    while(i<n1 && j<n2){
        if(L[i].marks <= R[j].marks){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(struct Student arr[],int left,int right){
    if(left<right){
        int mid = left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
void display(struct Student arr[],int n){
    int i;
    printf("%-10s %-20s %-10s\n","Roll No","Name","Marks");
    for(i=0;i<n;i++){
        printf("%-10d %-20s%-10.2f\n",
             arr[i].rollNo,
             arr[i].name,
             arr[i].marks);
    }
}
int main(){
    struct Student student[MAX];
    int n,i;
    printf("Enter number of students:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nStudent %d\n",i+1);
        printf("Roll Number:");
        scanf("%d",&student[i].rollNo);
        printf("Name:");
        scanf("%s",student[i].name);
        printf("Marks:");
        scanf("%f",&student[i].marks);
    }
    printf("\nOriginal Student Records");
    display(student, n);
    mergeSort(student, 0,n-1);
    printf("\n\nStudent Merit List(Ascending Order of Marks)");
    display(student,n);
    return 0;
}
