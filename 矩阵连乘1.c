#include <stdio.h>
#include <limits.h>

#define MAX_N 100
int m[MAX_N+1][MAX_N+1];
int p[MAX_N+1];         

int main() {
    int n;
    printf("输入矩阵数量n：");
    scanf("%d", &n);
    printf("输入%d+1个维度值：", n);
    for (int i=0; i<=n; i++) scanf("%d", &p[i]);

    
    for (int i=1; i<=n; i++) {
        m[i][i] = 0; 
    }

    // 步骤2：按区间长度递增计算（从长度2到n）
    for (int len=2; len<=n; len++) { // len=区间长度（2个、3个...矩阵）
        // 枚举所有长度为len的区间起点i
        for (int i=1; i<=n - len + 1; i++) { 
            int j = i + len - 1; // 区间终点j（i+长度-1）
            m[i][j] = INT_MAX;   // 初始化：设为极大值，方便找最小值

            // 步骤3：枚举所有拆分点k，计算当前拆分的总代价
            for (int k=i; k<j; k++) {
                // 核心公式：左半段次数 + 右半段次数 + 两段相乘次数
                int cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                // 如果当前拆分更优，更新m[i][j]
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    printf("最少乘法次数：%d\n", m[1][n]);
    return 0;
}