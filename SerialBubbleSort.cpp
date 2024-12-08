#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include "SerialBubbleSortTest.cpp"

using namespace std;

const double RandomDataMultiplier = 1000.0;


// Function for simple setting the initial data
void DummyDataInitialization(double*& pData, int& DataSize) {
    for(int i = 0; i < DataSize; i++)
        pData[i] = DataSize - i;
}

// Function for initializing the data by the random generator
void RandomDataInitialization(double *&pData, int& DataSize) {
    srand((unsigned)time(0));
    for(int i = 0; i < DataSize; i++)
        pData[i] = double(rand()) / RAND_MAX * RandomDataMultiplier;
}

// Function for allocating the memory and setting the initial values
void ProcessInitialization(double *&pData, int& DataSize) {
    while(DataSize <= 0) {
        printf("Enter the size of data to be sorted: ");
        scanf("%d", &DataSize);
        if(DataSize <= 0)
            printf("Data size should be greater than zero\n");
    }

    printf("Sorting %d data items\n", DataSize);
    pData = new double[DataSize];

    // Simple setting the data
    //DummyDataInitialization(pData, DataSize);

    // Setting the data by the random generator
    RandomDataInitialization(pData, DataSize);
}

// Function for the serial bubble sort algorithm
void SerialBubble(double *pData, int DataSize) {
    double Tmp;
    for(int i = 1; i < DataSize; i++)
        for(int j = 0; j < DataSize - i; j++)
            if(pData[j] > pData[j + 1]) {
                Tmp = pData[j];
                pData[j] = pData[j + 1];
                pData[j + 1] = Tmp;
            }
}


// Function for computational process termination
void ProcessTermination(double *pData) {
    delete []pData;
}

void test() {
    double *pData = 0;
    int DataSize = 0;
    time_t start, finish;
    double duration = 0.0;
    int sizes[] = {10, 100, 10000, 20000, 30000, 40000, 50000};

    printf("\nSerial bubble sort program\n");
    for (int i = 0; i < 7; i++) {
        DataSize = sizes[i];
        printf("Data size: %d\n", sizes[i]);

        ProcessInitialization(pData, sizes[i]);

        start = clock();
        SerialBubble(pData, DataSize);
        finish = clock();

        duration = (finish - start) / double(CLOCKS_PER_SEC);
        printf("Time of execution: %f\n", duration);

        ProcessTermination(pData);
    }

    printf("\nSerial standard sort\n");
    for (int i = 0; i < 7; i++) {
        DataSize = sizes[i];
        DataSize = sizes[i];
        printf("Data size: %d\n", sizes[i]);

        ProcessInitialization(pData, sizes[i]);

        start = clock();
        SerialStdSort(pData, DataSize);
        finish = clock();

        duration = (finish - start) / double(CLOCKS_PER_SEC);
        printf("Time of execution: %f\n", duration);

        ProcessTermination(pData);
    }
}

int main(int argc, char *argv[]) {
    // double *pData = 0;
    // int DataSize = 0;
    // time_t start, finish;
    // double duration = 0.0;

    // printf("Serial bubble sort program\n");

    // // Process initialization
    // ProcessInitialization(pData, DataSize);

    // printf("Data before sorting\n");
    // PrintData(pData, DataSize);

    // // Serial bubble sort
    // start = clock();
    // SerialBubble(pData, DataSize);
    // finish = clock();

    // printf("Data after sorting\n");
    // PrintData(pData, DataSize);

    // duration = (finish - start) / double(CLOCKS_PER_SEC);
    // printf("Time of execution: %f\n", duration);

    // // Process termination
    // ProcessTermination(pData);

    test();

    return 0;
}