#include <stdio.h>
#include <limits.h>

// 矩阵维度：A[i]的维度是p[i-1]×p[i]（i从1开始）
int p[10];  // 最多支持9个矩阵（p[0]~p[9]）
int n;      // 矩阵数量

// 递归计算A[i]~A[j]连乘的乘法次数（暴力枚举所有拆分）
int matrix_chain_brute(int i, int j) {
    // 终止条件：单个矩阵，乘法次数为0
    if (i == j) {
        return 0;
    }

    int min_cost = INT_MAX;  // 记录当前区间的最小代价

    // 枚举所有可能的拆分点k（i ≤ k < j）
    for (int k = i; k < j; k++) {
        // 递归计算左半部分 + 右半部分 + 两部分相乘的代价
        int cost = matrix_chain_brute(i, k) + matrix_chain_brute(k+1, j) + p[i-1]*p[k]*p[j];
        // 更新最小值
        if (cost < min_cost) {
            min_cost = cost;
        }
    }

    return min_cost;
}

int main() {
    printf("请输入矩阵数量n：");
    scanf("%d", &n);

    printf("请输入%d+1个维度值（空格分隔）：", n);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int min_times = matrix_chain_brute(1, n);
    printf("最少乘法次数：%d\n", min_times);

    return 0;
}