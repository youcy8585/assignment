#include <stdio.h>
#include <stdint.h>

// 32비트 숫자를 읽어들이는 함수
int32_t read_32bit_int(FILE *file) {
    uint8_t buffer[4];
    if (fread(buffer, sizeof(uint8_t), 4, file) == 4) {
        // 빅 엔디안 순서로 변환
        int32_t number = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
        return number;
    }
    return 0; // 파일을 읽지 못한 경우 또는 EOF일 경우 0 반환
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("사용법: %s <파일1> <파일2>\n", argv[0]);
        return 1;
    }

    FILE *file1, *file2;
    file1 = fopen(argv[1], "rb");
    file2 = fopen(argv[2], "rb");

    if (file1 == NULL || file2 == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    int32_t number1 = read_32bit_int(file1);
    int32_t number2 = read_32bit_int(file2);

    int32_t sum = number1 + number2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", number1, number1, number2, number2, sum, sum);


    fclose(file1);
    fclose(file2);

    return 0;
}
