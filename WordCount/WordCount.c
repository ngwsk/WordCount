#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("请输入两个参数第一个为-c或-w，第二个为目标文件");
        return 0;
    }
    FILE* fp;
    char buffer[1003];
    int bufferLen;
    int c = 0, w = 0, n = 0;
    char z;
    if ((fp = fopen(argv[2], "rb")) == NULL) {
        perror(argv[2]);
        return NULL;
    }
    while (fgets(buffer, 1003, fp) != NULL) {
        ++n;
        bufferLen = strlen(buffer);
        for (int i = 0; i < bufferLen; i++) {
            z = buffer[i];
            ++c;//所有字符都算字符
            if (z == ',' || z == ' ') {
                ++w;
            }
            if (i == 0 && (z == ',' || z == ' ')) {
                --w;
            }
            if (z == '\n') {//回车符会变成两个字符，所有每次要减一
                --c;
            }
        }
    }
    if (z != '，' && z != ',' && z != ' ')//如果不是以”，“、空格结尾，字符数要加1
        ++w;
    if (!strcmp(argv[1], &("-c")))
        printf("字符数：%d", c);
    if (!strcmp(argv[1], &("-w")))
        printf("单词数：%d", w);
    return 0;
}
