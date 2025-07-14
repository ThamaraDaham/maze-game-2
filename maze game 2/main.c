#include <stdio.h>
#include <stdlib.h>
#include "headerFile.h"
#include "map.h"
#include <string.h>
#include <termios.h>
#include "terminal.h"






int main(int argc, char *argv[]){

	disableBuffer();

    
    int ***metadataTable=(int ***)malloc(sizeof(int*)*17);

    int metadataAmot;   
    int mapRw;            
    int mapCl;
    

    int *metadataAmount = &metadataAmot;   
    int *mapRow = &mapRw;            
    int *mapCol = &mapCl;  
    

    
    
    
    
    
    getMetadata(metadataTable,metadataAmount,mapRow,mapCol);
    

    int z;
    int j;
    int k;
    int ** mazeTable = (int **) malloc (sizeof(int*)*(*mapRow));
        for(z=0 ; z< *mapRow ; z++){
            mazeTable[z]= (int*)malloc(sizeof(int*)*(*mapCol));
        }
    int c;
    int d;
    for(c=0; c<*mapRow; c++){
        for(d=0; d<*mapCol; d++){
            mazeTable[c][d]=32;
        }
    }
    
    
    
    int m;
    int n;
    for(m=0; m < *mapRow; m++){
        mazeTable[m][0]= 124;
        mazeTable[m][(*mapCol)-1]=124;
    }
    for(n=0; n < *mapCol; n++){
        mazeTable[0][n] = 124;
        mazeTable[(*mapRow)-1][n] =124;
    }

    mazeTable[0][0]=35;
    mazeTable[0][(*mapCol)-1]=35;
    mazeTable[(*mapRow)-1][0]=35;
    mazeTable[(*mapRow)-1][(*mapCol)-1] =35;  

    unsigned char *actionPtr=(unsigned char *) malloc(sizeof(unsigned char));
    int *rowPositionPtr = (int*)malloc(sizeof(int));
    
    int *columnPositionPtr= (int*)malloc(sizeof(int));
    

    int *playerCharacterPtr=(int *) malloc(sizeof(int));
    *playerCharacterPtr=94;

    int argumentValue = atoi(argv[1]);
    int *argumentValuePtr =&argumentValue;
     
        for(j=0 ; j < *metadataAmount ; j++){
             
            if((*metadataTable)[j][2] ==0){
                mazeTable[ (*metadataTable)[j][0] ] [ (*metadataTable)[j][1] ]  = 94;
                *rowPositionPtr = (*metadataTable)[j][0];
                *columnPositionPtr = (*metadataTable)[j][1];
            }
            if((*metadataTable)[j][2] ==1){
                mazeTable[ (*metadataTable)[j][0] ] [ (*metadataTable)[j][1] ]  = 88;
            }
            if((*metadataTable)[j][2] ==2){
                mazeTable[ (*metadataTable)[j][0] ] [ (*metadataTable)[j][1] ]  = 79;
            }
            
        }
    
      
   #ifndef DARK
        while (*actionPtr !='q'){
        
        
            printf("\ncontrol your playr using W A S D\n");
            printf("row:%i, col:%i",*rowPositionPtr,*columnPositionPtr);

            mazeTable[*rowPositionPtr][*columnPositionPtr] =*playerCharacterPtr;

            int y;
            int x;
            for(y = 0 ; y < *mapRow; y++){
                printf("\n");
                for(x = 0 ; x < *mapCol ; x++ ){
                    printf("%c",mazeTable[y][x]);
                    }
            }
            
            Control(mazeTable,actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr);
            }
       
	#endif
 
    #ifdef DARK
        while (*actionPtr !='q'){
            printf("\ncontrol your playr using W A S D\n");
            printf("row:%i, col:%i",*rowPositionPtr,*columnPositionPtr);
            mazeTable[*rowPositionPtr][*columnPositionPtr] =*playerCharacterPtr;

            int y;
            int x;
            
            
                    if(*rowPositionPtr >=argumentValue && *rowPositionPtr<=*mapRow && *columnPositionPtr>=argumentValue && *columnPositionPtr <= *mapCol){
                        
                        for(y= (*rowPositionPtr)-argumentValue; y < (*rowPositionPtr)+argumentValue; y++){
                            printf("\n");
                            for(x = (*columnPositionPtr)-argumentValue ; x < (*columnPositionPtr)+argumentValue ; x++ ){
                                printf("%c",mazeTable[y][x]);
                            }
                        }
                    }
                    else{
                        system("clear");
                         printf("\ncontrol your playr using W A S D\n");
                            printf("row:%i, col:%i",*rowPositionPtr,*columnPositionPtr);
                        int e;
                        int f;
                        for(e=(*rowPositionPtr)-(argumentValue-1); e<=(*rowPositionPtr)+(argumentValue-1);e++){
                            printf("\n");
                            for(f=(*columnPositionPtr)-(argumentValue-1) ; f <= (*columnPositionPtr)+(argumentValue-1) ; f++ ){
                                printf("%c",mazeTable[e][f]);
                            }
                        }
                    }
                     Control(mazeTable,actionPtr,rowPositionPtr,columnPositionPtr,playerCharacterPtr); 
                    }
        #endif
            
           
            
        
    enableBuffer();
    free(metadataTable);
    free(actionPtr);
    free(rowPositionPtr);
    free(columnPositionPtr);   
    return 0;
}


