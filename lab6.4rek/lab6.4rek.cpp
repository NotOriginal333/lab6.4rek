#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>

using namespace std;

int CountElementsLessThanC(double* r, int size, double C, int index = 0) {
    if (index == size) {
        return 0;
    }

    int count = CountElementsLessThanC(r, size, C, index + 1);
    if (r[index] < C) {
        count++;
    }

    return count;
}

int FindLastNegativeIndex(double* r, int size, int index, int& lastNegativeIndex) {
    if (index >= size) {
        return lastNegativeIndex;
    }

    if (r[index] < 0) {
        lastNegativeIndex = index;
    }

    return FindLastNegativeIndex(r, size, index + 1, lastNegativeIndex);
}


int SumIntPartsAfterLastNegativeRec(double r[], int size, int lastNegativeIndex, int currentIndex) {
    if (currentIndex >= size) {
        return 0;
    }

    if (currentIndex > lastNegativeIndex) {
        return static_cast<int>(r[currentIndex]) + SumIntPartsAfterLastNegativeRec(r, size, lastNegativeIndex, currentIndex + 1);
    }

    return SumIntPartsAfterLastNegativeRec(r, size, lastNegativeIndex, currentIndex + 1);
}

int FindMaxIndex(double r[], int size, int index = 0, int maxIndex = 0) {
    if (index == size) {
        return maxIndex;
    }

    if (r[index] > r[maxIndex]) {
        maxIndex = index;
    }

    return FindMaxIndex(r, size, index + 1, maxIndex);
}

void TransformArray(double r[], int size, int index = 0, int maxIndex = 0, int lessThan20PercentCount = 0, int pos = 0) {
    if (index == size) {
        return;
    }

    if (index != maxIndex && abs(r[index] - r[maxIndex]) / r[maxIndex] <= 0.2) {
        lessThan20PercentCount++;
    }

    if (index != maxIndex && abs(r[index] - r[maxIndex]) / r[maxIndex] <= 0.2) {
        double temp = r[index];
        r[index] = r[pos];
        r[pos] = temp;
        pos++;
    }

    TransformArray(r, size, index + 1, maxIndex, lessThan20PercentCount, pos);
}

void Input(double* r, int size, int index = 0) {
    if (index == size) {
        return;
    }

    cout << "a[" << index << "] = ";
    cin >> r[index];
    Input(r, size, index + 1);
}

void Print(double* r, int size, int index = 0) {
    if (index == size) {
        cout << endl;
        return;
    }

    cout << setw(4) << r[index] << " ";
    Print(r, size, index + 1);
}

int main() {
    srand((unsigned)time(NULL));
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    double C;
    cout << "Enter the value of C: ";
    cin >> C;

    double* r = new double[n];

    int lastNegativeIndex=-1;

    Input(r, n);
    Print(r, n);

    int count = CountElementsLessThanC(r, n, C);
    cout << "Less than C: " << count << endl;

    int negIn = FindLastNegativeIndex(r, n, 0, lastNegativeIndex);

    int sum = SumIntPartsAfterLastNegativeRec(r, n, negIn, 0);
    cout << "Sum: " << sum << endl;

    int maxIndex = FindMaxIndex(r, n);
    TransformArray(r, n, 0, maxIndex);

    Print(r, n);

    delete[] r;

    return 0;
}
