#include <stdio.h>

int main(){
    int n,frames;
    
    printf("Enter number for pages:-\n");
    scanf("%d",&n);
    int pages[n];
    printf("Page Stream - \n");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }   
    printf("Enter number for frames:-\n");
    scanf("%d",&frames);
    int buffer[frames] ;
    for (int i = 0; i < frames; i++) {
        buffer[i] = -1;
    }
    int j = 0,faults;
    printf("Calculating....\n");
    printf("Page\tFrames\t\tFaults\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t",pages[i]);
        int pageFound =0;
        for (int x = 0; x < frames; x++) {
            if (buffer[x]==pages[i])
            {    
                pageFound=1;
                break;
            }
        }

       
        if(!pageFound){
            buffer[j] = pages[i];
            j = (j+1)%frames;   
            faults++; 
        }
        for (int i = 0; i < frames; i++) {
            printf("%d ",buffer[i]);
        }
        printf("\t\t");
        printf("%d\n",faults);
    }
    printf("Done bhai the faults are - %d\n",faults);
}