//
//  main.c
//  BinaryTree2
//
//  Created by Arsalan Vakili on 2015-08-05.
//  Copyright (c) 2015 Arsalan Vakili. All rights reserved.
//

#include <stdio.h>

typedef struct{
    int firstoccurence;
    int numberofoccurence;
} Range;
Range targetValueoccurence (int array[], int target, int targetIndex);

int MidPoint (int min, int max);
Range binarysearch( int array[], int targetvalue, int midPointindex, int maxpointindex );

int main(int argc, const char * argv[]) {
    
    int numbers[] = {2, 3 ,5 ,7 ,7 ,3 ,7, 14, 17};
    
    Range key = binarysearch(numbers, 7, 0, 8);
    Range key2 = binarysearch(numbers, 18, 0, 8);
    Range key3 = binarysearch(numbers, 7, 0, 8);
    if( key.firstoccurence == -1){
        printf("the target value is not in the list of array");
    }
    else {
        printf("the value of key is %d ,%d\n ",key.firstoccurence, key.numberofoccurence);
        printf("the value of key is %d ,%d\n ",key2.firstoccurence, key2.numberofoccurence);
        printf("the value of key is %d ,%d ",key3.firstoccurence, key3.numberofoccurence);
        
    }
    
    return 0;
}


Range binarysearch( int *array, int targetvalue, int minPointindex, int maxpointindex ){
    
    
   // Range range;
    
    if (maxpointindex < minPointindex){
        Range nullrange = {-1, 0};
        return  nullrange;
    }
    
    else{
        
        int midpoint = MidPoint(minPointindex, maxpointindex);
        
        
        if (array[midpoint] < targetvalue){
            return binarysearch(array, targetvalue, minPointindex + 1,maxpointindex);
        }
        if (array[midpoint] > targetvalue){
            return binarysearch(array, targetvalue, minPointindex , maxpointindex - 1);
        }
        
        return  targetValueoccurence( array,targetvalue, midpoint);
        
    }
    
}



Range targetValueoccurence (int *array, int target, int targetIndex){
    int add;
    int intitialindex;
    int nextindex= targetIndex +1;
    int previousindex= targetIndex -1 ;
    int arraysize= sizeof(array) + 1;
    int counterleft;
    int counterright;
    
    
    while (nextindex < arraysize) {
        if (array[nextindex] == target){
            counterright += 1;
        }

            nextindex++;
       // break;
    }
    while(previousindex >= 0){
        if (array[previousindex] == target){
            
            counterleft += 1;
        }
       // break;
            previousindex--;
        
    }
    
    
    add= counterleft + counterright + 1;
    intitialindex= targetIndex - counterleft;
    
    Range range1= {intitialindex,add};
    return  range1;
}

int MidPoint (int min, int max){
    int value= (min + max)/2;
    return value;
}


