// Online C compiler to run C program online
#include<stdio.h>

int main() {
    int arr[10];
    int ch, i, val, pos=-1;
    
    do{
        printf("\n1. Insert \n2. Delete \n3. Traverse \nEnter you choice:");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                printf("\n1. Insert at end \n2. Insert at beginning \n3. Insert at position \nEnter you choice:");
                scanf("%d", &ch);
                switch (ch){
                    case 1:
                        // insert at end
                        printf("Enter value:");
                        scanf("%d", &val);
                        pos++;
                        arr[pos]=val;
                        break;

                    case 2:
                        //insert at beginning
                        printf("Enter value:");
                        scanf("%d", &val);
                        for(i=pos;i>=0;i--){
                            arr[i+1]=arr[i];
                        }
                        arr[0]=val;
                        pos++;
                        break;
                }

            
                
               break;
                
            case 2:
                // delete from end
                pos--;
                break;

            case 3:
                // traverse
                printf("\nTraverse Values: \n");
                for(i=0;i<=pos;i++){
                    printf("%d ", arr[i]);
                }
                break;
        }
    }while(ch!=4);
    
    printf("Exit Loop");
    return 0;
}