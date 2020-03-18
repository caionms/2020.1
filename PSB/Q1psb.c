#include <stdio.h>
#include <stdlib.h>

int main(){
    float f;
    int v[16];
    int count=0;
    scanf("%f",&f);
    printf("0,");
    for(int i=0; ;i++){
    	count++;
        if(f*2 == 1){
            v[i] = 1;
            break;
        }
        else if((f*2) < 1){
        	f = f * 2;
        	v[i] = 0;
        }
        else{
        	f = f * 2;
        	f = f - 1;
        	v[i] = 1;
        }
    }
    for(int i=0;i<count;i++){
    	printf("%d",v[i]);
    }
    printf("\n");
    return 0;
}
