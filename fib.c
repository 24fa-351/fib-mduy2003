#include <stdio.h>

int fibRecursive(int fibValue)
{
    if (fibValue == 0 || fibValue == 1) {
        return fibValue;
    }
    return fibRecursive(fibValue - 1) + fibRecursive(fibValue - 2);
}

int fibIterative(int fibValue)
{
    int fibSum = 0;
    int prevNum = 0;
    int currentNum = 1;
    for (size_t ix = 1; ix < fibValue; ++ix) {
        fibSum = prevNum + currentNum;
        prevNum = currentNum;
        currentNum = fibSum;
    }
    return fibSum;
}

int main(int argc, char* argv[])
{
    int firstNum;
    int input = sscanf(argv[1], "%d", &firstNum);
    int secondNum = 0;
    char fibType = *argv[2];
    char* fileName = argv[3];

    FILE* file = fopen(fileName, "r");
    fscanf(file, "%d", &secondNum);
    fclose(file);
    int nthNum = firstNum + secondNum - 1;

    if (fibType == 'r') {
        int result = fibRecursive(nthNum);
        printf("%d", result);
    } else if (fibType == 'i') {
        int result = fibIterative(nthNum);
        printf("%d", result);
    }
    return 0;
}