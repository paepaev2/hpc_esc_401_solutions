#include <iostream>

int ii(int x, int y) {
    int x_stride = 1;
    int y_stride = 14;

    return (x * x_stride) + (y * y_stride);
}

int main() {
    int x, y;
    for (y=0; y<6; ++y) {
	for (x=0; x<14; ++x) {
	    printf("(%d, %d) %d\n", y, x, ii(x , y)); // use the notation (row index, column index)
	}	
    }
}
