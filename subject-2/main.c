#include "stdio.h"
#include "string.h"

struct
{
    float min;
    char *result;
} rank[] = {
    {
        min : 9.0,
        result : "Xuat sac"
    },
    {
        min : 8.0,
        result : "Gioi"
    },
    {
        min : 6.5,
        result : "Kha"
    },
    {
        min : 5.0,
        result : "Trung binh"
    },
    {
        min : 0.0,
        result : "Yeu"
    },
};
int length = sizeof(rank) / sizeof(rank[0]);

char *findScoreRank2(float score)
{
    printf("Score 2: %f\n", score);

    for (int i = 0; i < length; i++)
    {
        printf("Rank: %f\n", rank[i].min);
        if (score > rank[i].min)
            return rank[i].result;
    }
}

void findScoreRank(float score)
{

    if (score > 9.0)
    {
        printf("Xuat sac\n");
    }
    else if (score > 8.0)
    {
        printf("Gioi\n");
    }
    else if (score > 6.5)
    {
        printf("Kha\n");
    }
    else if (score > 5.0)
    {
        printf("Trung binh\n");
    }
    else
    {
        printf("Yeu\n");
    }
}

void main()
{
    float score = 0.0;

    printf("Nhap diem:\n");
    scanf("%f", &score);

    findScoreRank(score);

    char *result2 = findScoreRank2(score);
    printf("%s\n", result2);
}