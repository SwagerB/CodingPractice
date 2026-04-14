#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    
    *returnSize = 0;
    free(result);
    return NULL;
}

int main() {
    char line[1000];
    int nums[100];  // 假设最多100个数字
    int size = 0;
    
    // 读取一行输入
    printf("请输入数字（用空格分隔）：");
    fgets(line, sizeof(line), stdin);
    
    // 解析数字
    char* token = strtok(line, " ");
    while (token != NULL && size < 100) {
        nums[size++] = atoi(token);
        token = strtok(NULL, " ");
    }
    
    // 读取目标值
    int target;
    printf("请输入目标值：");
    scanf("%d", &target);
    
    // 调用函数
    int returnSize;
    int* result = twoSum(nums, size, target, &returnSize);
    
    // 输出结果
    if (result != NULL && returnSize == 2) {
        printf("[%d,%d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("[]\n");
    }
    
    return 0;
}