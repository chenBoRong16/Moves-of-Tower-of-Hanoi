#include <stdio.h>

// ��ơG�ѨM�e������D
int solveHanoi(int numDisks, char sourcePeg, char auxiliaryPeg, char targetPeg) {
    int moveCount = 0;

    // �򥻱��p�G�u���@�ӽL�l�ݭn����
    if (numDisks == 1) {
        printf("�N�L�l %d �q %c ���� %c\n", numDisks, sourcePeg, targetPeg);
        return 1;
    }

    // �N n-1 �ӽL�l�q���W���ʨ컲�U�W�A�ϥΥؼЬW�@�����U
    moveCount += solveHanoi(numDisks - 1, sourcePeg, targetPeg, auxiliaryPeg);

    // �N�� n �ӽL�l�q���W���ʨ�ؼЬW
    printf("�N�L�l %d �q %c ���� %c\n", numDisks, sourcePeg, targetPeg);
    moveCount++;

    // �N n-1 �ӽL�l�q���U�W���ʨ�ؼЬW�A�ϥη��W�@�����U
    moveCount += solveHanoi(numDisks - 1, auxiliaryPeg, sourcePeg, targetPeg);

    return moveCount;
}

int main() {
    while (1) {
        printf("�п�J�L�l���ƶq�]��J 0 �����^�G");
        int numDisks;
        scanf(" %d", &numDisks);

        // ��������
        if (numDisks == 0) {
            return 0;
        }

        // �ѨM�e������D�å��L�`�@�����ʦ���
        printf("�`�@���ʦ��ơG%d\n", solveHanoi(numDisks, 'A', 'B', 'C'));
    }

    return 0;
}
