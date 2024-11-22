#include <stdio.h>

// 函數：解決河內塔問題
int solveHanoi(int numDisks, char sourcePeg, char auxiliaryPeg, char targetPeg) {
    int moveCount = 0;

    // 基本情況：只有一個盤子需要移動
    if (numDisks == 1) {
        printf("將盤子 %d 從 %c 移到 %c\n", numDisks, sourcePeg, targetPeg);
        return 1;
    }

    // 將 n-1 個盤子從源柱移動到輔助柱，使用目標柱作為輔助
    moveCount += solveHanoi(numDisks - 1, sourcePeg, targetPeg, auxiliaryPeg);

    // 將第 n 個盤子從源柱移動到目標柱
    printf("將盤子 %d 從 %c 移到 %c\n", numDisks, sourcePeg, targetPeg);
    moveCount++;

    // 將 n-1 個盤子從輔助柱移動到目標柱，使用源柱作為輔助
    moveCount += solveHanoi(numDisks - 1, auxiliaryPeg, sourcePeg, targetPeg);

    return moveCount;
}

int main() {
    while (1) {
        printf("請輸入盤子的數量（輸入 0 結束）：");
        int numDisks;
        scanf(" %d", &numDisks);

        // 結束條件
        if (numDisks == 0) {
            return 0;
        }

        // 解決河內塔問題並打印總共的移動次數
        printf("總共移動次數：%d\n", solveHanoi(numDisks, 'A', 'B', 'C'));
    }

    return 0;
}
