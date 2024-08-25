#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Calculator
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    return a / b;
}

// String

int str_len(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int str_cmp(char *str1, char *str2) {
    int len1 = str_len(str1);
    int len2 = str_len(str2);
    if (len1 != len2) {
        return 0;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

char *str_cat(char *str1, char *str2) {
    int len1 = str_len(str1);
    int len2 = str_len(str2);
    char *result = (char *)malloc(len1 + len2 + 1);
    for (int i = 0; i < len1; i++) {
        result[i] = str1[i];
    }
    for (int i = 0; i < len2; i++) {
        result[len1 + i] = str2[i];
    }
    result[len1 + len2] = '\0';
    return result;
}

// Array

int *array_create(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    return arr;
}

void array_free(int *arr) {
    free(arr);
}

void array_set(int *arr, int index, int value) {
    arr[index] = value;
}

int array_get(int *arr, int index) {
    return arr[index];
}

int array_size(int *arr) {
    return sizeof(arr) / sizeof(int);
}

int array_sum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int array_max(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int array_min(int *arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int array_avg(int *arr, int size) {
    return array_sum(arr, size) / size;
}

// Test

void test_add() {
    assert(add(1, 2) == 3);
    assert(add(0, 0) == 0);
    assert(add(-1, 1) == 0);
    assert(add(-1, -1) == -2);
    printf("add() passed\n");
}

void test_sub() {
    assert(sub(1, 2) == -1);
    assert(sub(0, 0) == 0);
    assert(sub(-1, 1) == -2);
    assert(sub(-1, -1) == 0);
    printf("sub() passed\n");
}

void test_mul() {
    assert(mul(1, 2) == 2);
    assert(mul(0, 0) == 0);
    assert(mul(-1, 1) == -1);
    assert(mul(-1, -1) == 1);
    printf("mul() passed\n");
}

void test_div() {
    assert(division(1, 2) == 0);
    assert(division(0, 1) == 0);
    assert(division(1, 1) == 1);
    assert(division(2, 1) == 2);
    printf("div() passed\n");
}

void test_str_len() {
    assert(str_len("hello") == 5);
    assert(str_len("") == 0);
    assert(str_len("a") == 1);
    assert(str_len("ab") == 2);
    printf("str_len() passed\n");
}

void test_str_cmp() {
    assert(str_cmp("hello", "hello") == 1);
    assert(str_cmp("hello", "world") == 0);
    assert(str_cmp("world", "hello") == 0);
    assert(str_cmp("", "") == 1);
    printf("str_cmp() passed\n");
}

void test_str_cat() {
    char *result = str_cat("hello", "world");
    assert(str_cmp(result, "helloworld") == 1);
    free(result);
    result = str_cat("", "world");
    assert(str_cmp(result, "world") == 1);
    free(result);
    result = str_cat("hello", "");
    assert(str_cmp(result, "hello") == 1);
    free(result);
    result = str_cat("", "");
    assert(str_cmp(result, "") == 1);
    free(result);
    printf("str_cat() passed\n");
}

void test_array_create() {
    int *arr = array_create(5);
    assert(arr != NULL);
    array_free(arr);
    printf("array_create() passed\n");
}

void test_array_set() {
    int *arr = array_create(5);
    array_set(arr, 0, 1);
    array_set(arr, 1, 2);
    array_set(arr, 2, 3);
    array_set(arr, 3, 4);
    array_set(arr, 4, 5);
    assert(array_get(arr, 0) == 1);
    assert(array_get(arr, 1) == 2);
    assert(array_get(arr, 2) == 3);
    assert(array_get(arr, 3) == 4);
    assert(array_get(arr, 4) == 5);
    array_free(arr);
    printf("array_set() passed\n");
}

void test_array_sum() {
    int *arr = array_create(5);
    array_set(arr, 0, 1);
    array_set(arr, 1, 2);
    array_set(arr, 2, 3);
    array_set(arr, 3, 4);
    array_set(arr, 4, 5);
    assert(array_sum(arr, 5) == 15);
    array_free(arr);
    printf("array_sum() passed\n");
}

void test_array_max() {
    int *arr = array_create(5);
    array_set(arr, 0, 1);
    array_set(arr, 1, 2);
    array_set(arr, 2, 3);
    array_set(arr, 3, 4);
    array_set(arr, 4, 5);
    assert(array_max(arr, 5) == 5);
    array_free(arr);
    printf("array_max() passed\n");
}

void test_array_min() {
    int *arr = array_create(5);
    array_set(arr, 0, 1);
    array_set(arr, 1, 2);
    array_set(arr, 2, 3);
    array_set(arr, 3, 4);
    array_set(arr, 4, 5);
    assert(array_min(arr, 5) == 1);
    array_free(arr);
    printf("array_min() passed\n");
}

void test_array_avg() {
    int *arr = array_create(5);
    array_set(arr, 0, 1);
    array_set(arr, 1, 2);
    array_set(arr, 2, 3);
    array_set(arr, 3, 4);
    array_set(arr, 4, 5);
    assert(array_avg(arr, 5) == 3);
    array_free(arr);
    printf("array_avg() passed\n");
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Perform calculations using the input numbers
    int sum = add(num1, num2);
    int difference = sub(num1, num2);
    int product = mul(num1, num2);
    int quotient = division(num1, num2);
    
    // Print the results
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %d\n", quotient);
    
    return 0;
}

