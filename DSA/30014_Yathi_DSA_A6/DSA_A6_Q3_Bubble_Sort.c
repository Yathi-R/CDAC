//Implement Bubble sort
 #include<stdio.h>

 int main(){
    
    int n;
    
    printf("Enter the size: ");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter the elements: ");
    for(int k=0;k<n;k++){
        scanf("%d",&arr[k]);
    }
    
    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-i-1;j++){

            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("Sorted by Bubble sort: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
 }