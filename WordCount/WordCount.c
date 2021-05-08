#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 3)//对命令行参数数量进行检查
    {
        printf("请输入两个参数第一个为-c或-w，第二个为目标文件");
        return 0;
    }
    FILE* fp;
    char buffer[1003];
    int bufferLen;
    int c = 0, w = 0;//c为字符数，w为单词数，
    char z = "";
    if ((fp = fopen(argv[2], "rb")) == NULL) {//检查文件是否打开成功
        perror(argv[2]);
        return NULL;
    }
    while (fgets(buffer, 1003, fp) != NULL) {//逐行读取文件，如果没有则终止循环
        bufferLen = strlen(buffer);
        for (int i = 0; i < bufferLen; i++) {
            z = buffer[i];
            ++c;//所有字符都算字符
            if (z == ',' || z == ' ') {//由于单词以逗号和空格分割所以据此计数
                ++w;
            }
            if (i == 0 && (z == ',' || z == ' '|| z == '，')) {//如果第一个字符是逗号或者空格则单词数目减一
                --w;
            }
            if (z == '\n') {//回车符会变成两个字符，所有每次要减一
                --c;
            }
        }
        if (z == ',' || z == ' ' || z == '，')//每行如果是以“，”、空格结尾，字符数要减1
            --w;
    }
    if (!strcmp(argv[1], &("-c")))//根据输入-c还是-w来输出字符数还是单词数
        printf("字符数：%d", c);
    if (!strcmp(argv[1], &("-w")))
        printf("单词数：%d", w);
    return 0;
}
