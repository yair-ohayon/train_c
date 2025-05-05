#include <stdio.h>
#include <stdlib.h>



#include <stdio.h>
#include <math.h>


int trap(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int left_max = 0;
    int right_max = 0;
    int total_water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max)
                left_max = height[left];
            else
                total_water += left_max - height[left];
            left++;
        } else {
            if (height[right] >= right_max)
                right_max = height[right];
            else
                total_water += right_max - height[right];
            right--;
        }
    }

    return total_water;
}


int main() {
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int heightSize = 12;
    int count =0;

    for (int i=0; i<sizeof(height) / sizeof(int); i++){
        int maxRight = 0;
        int maxLeft = 0;


        for (int j = i; j >= 0; j--) {
            if (height[j] > maxLeft)
                maxLeft = height[j];
        }

        // Find the tallest bar on the right of i (including i)
        for (int j = i; j < heightSize; j++) {
            if (height[j] > maxRight)
                maxRight = height[j];
        }

        int waterAtI = (maxLeft < maxRight ? maxLeft : maxRight) - height[i]; 

        count+=waterAtI;


    }
    printf("%d",trap(height,11));




}
