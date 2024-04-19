#include <iostream>
using namespace std;
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int year, int month) {
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4: 
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}

int daysBetweenDates(int year1, int month1, int day1, int year2, int month2, int day2) {
    int days = 0;

    while (year1 != year2 || month1 != month2) {
        days += daysInMonth(year1, month1);
        month1++;
        if (month1 > 12) {
            month1 = 1;
            year1++;
        }
    }

    days += day2 - day1;

    return days;
}
double average(int array[], int size) {
    if (size == 0) {
        return 0.0;
    }

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    double average = static_cast<double>(sum) / size;

    return average;
}

int main() {
    int year1 = 2024, month1 = 4, day1 = 15;
    int year2 = 2024, month2 = 5, day2 = 10;

    int difference = daysBetweenDates(year1, month1, day1, year2, month2, day2);
    cout << "Difference in days between dates: " << difference <<endl;

    int numbers[] = { 10, 20, 30, 40, 50 };

    int size = sizeof(numbers) / sizeof(numbers[0]);

    double result = average(numbers, size);

    cout << "Arithmetic mean: " << result <<endl;
}