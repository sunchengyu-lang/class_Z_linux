#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char suit[4][10] = {"spades", "hearts", "clubs", "diamonds"};
char face[13][10] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

struct Card
{

	char suit[10];
	char face[10];
};

struct Card cards[52];

void init()
{
	int t = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
		{

			strcpy(cards[t].suit, suit[i]);
			strcpy(cards[t].face, face[j]);
			t++;
		}
}

void shuffleDeck()
{

	// Fisher-Yates洗牌算法
	srand(time(NULL)); // 初始化随机数种子
	for (int i = 51; i > 0; i--)
	{
		int j = rand() % (i + 1); // 生成0到i之间的随机数
		// 交换cards[i]和cards[j]
		struct Card temp = cards[i];
		cards[i] = cards[j];
		cards[j] = temp;
	}
}

void dealCards()
{
	int p = 1; // 假设有三个人玩牌
	for (int i = 0; i < 52; i++)
	{
		printf("%s %s发给%d号玩家\n", cards[i].suit, cards[i].face, p);
		if (p == 3)
			p = 1;
		else
			p++;
	}
}
int main()
{
	init();
	shuffleDeck();
	dealCards();
	return 0;
}
