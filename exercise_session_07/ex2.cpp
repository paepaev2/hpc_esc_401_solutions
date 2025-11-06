#include <iostream>

int** swap(int** M) {
    int** M2 = new int*[2];
    *(M2 + 0) = new int[5];
    *(M2 + 1) = new int[5];

    for (int i=0; i<5; i++) {
	*(*(M2 + 0) + i) = *(*(M + 1) + (4 - i));
	*(*(M2 +1) + i) = *(*(M + 0) + (4 - i));
    }

    return M2;
}

void printMatrix(int** M) {
    for (int i=0; i<2; i++) {
	std::cout << i << ": ";
	for (int j=0; j<5; j++) {
	    std::cout << *(*(M + i) + j);
	    if (j<4) std::cout << ", ";
	    else std::cout << "" << std::endl;
	}
    }
}

int main() {	
    int ** M = new int *[2];
    *(M + 0) = new int [5]{0 ,1 ,2 ,3 ,4};
    *(M + 1) = new int [5]{5 ,6 ,7 ,8 ,9};

    std::cout << "M" << std::endl;
    printMatrix(M);

    int** M2 = swap(M);
    std::cout << "M2" << std::endl;
    printMatrix(M2);

    delete[] *(M + 0);
    delete[] *(M + 1);
    delete[] M;

    delete[] *(M2 + 0);
    delete[] *(M2 + 1);
    delete[] M2;

    return 0;
}

