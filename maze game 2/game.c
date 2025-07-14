

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "terminal.h"

void Control(int (**maze),unsigned char *actionPtr,int *rowPositionPtr,int *columnPositionPtr,int *playerCharacterPtr){
    
/*

I have used ASCII values sometimes insted of char values

	 94 => ^
   	 88 => x
 	 79 => o
  	 124 => |
	
	60 => <
	62 => >
	118 => v
	
	

 */
    

   
    
    
    

    printf("\nAction;");
    scanf("%c",actionPtr);
    system("clear");
    int prevRowPosition = *rowPositionPtr;
    int prevColumnPosition= *columnPositionPtr;
    int space =32;
    int RowgonnaBePostition;
    int columngonnaBePosition;
   
    if(*actionPtr != 'q') {
        
            switch (*actionPtr){
                case 'a':
                    columngonnaBePosition=(*columnPositionPtr)-1;
                    if (maze[*rowPositionPtr][columngonnaBePosition] != 124 && maze[*rowPositionPtr][columngonnaBePosition] != 79){
                        (*columnPositionPtr)--;
                        
                        maze[prevRowPosition][prevColumnPosition] = space;
                        *playerCharacterPtr=60;
                        if(maze[*rowPositionPtr][*columnPositionPtr]==88){
                            printf("you won");
                            *actionPtr ='q';
                        }
                    }
                
                    
                    break;
            
                case 'd':
                    columngonnaBePosition=(*columnPositionPtr)+1;
                    if (maze[*rowPositionPtr][columngonnaBePosition] != 124 && maze[*rowPositionPtr][columngonnaBePosition] != 79){
                        (*columnPositionPtr)++;
                        
                        maze[prevRowPosition][prevColumnPosition] = space;
                        *playerCharacterPtr=62;
                        if(maze[*rowPositionPtr][*columnPositionPtr]==88){
                            printf("you won");
                            *actionPtr ='q';
                        }
                    }

                    
                    break;

                case 's':
                    RowgonnaBePostition=(*rowPositionPtr)+1;
                    if (maze[RowgonnaBePostition][*columnPositionPtr] != 124 && maze[RowgonnaBePostition][*columnPositionPtr] != 79){
                        (*rowPositionPtr)++;
                        
                        maze[prevRowPosition][prevColumnPosition] = space;
                         *playerCharacterPtr=118;
                         if(maze[*rowPositionPtr][*columnPositionPtr]==88){
                            printf("you won");
                            *actionPtr ='q';
                        }
                    }

                    
                    break;
                
                case 'w':
                
                    RowgonnaBePostition=(*rowPositionPtr)-1;
                    
                    if (maze[RowgonnaBePostition][*columnPositionPtr] != 124 && maze[RowgonnaBePostition][*columnPositionPtr] != 79){
                        (*rowPositionPtr)--;
                        
                        maze[prevRowPosition][prevColumnPosition] = space;
                        *playerCharacterPtr=94;
                        if(maze[*rowPositionPtr][*columnPositionPtr]==88){
                            printf("you won");
                            *actionPtr ='q';
                        }
                    }
                    
                    break;

                
                    
        
            }
    }
}


    

