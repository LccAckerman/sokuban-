#include <iostream>
#include<conio.h>

bool Isgameover(int* map, int Rbox ,int q )     //Rbox  为了方便拓展，此参数为目的地个数
{
	int n = 0;
	

	for (int i = 0; i < 100; i++)
	{
		if ((*((map + q*100) + i)) == 6) {
			n++; 
		}
	}
		
	
	if (Rbox == n)
	{
		std::cout << "恭喜通关！！！\n";
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int input;						//输入常数
	/*int nowpoint[p] = 31;
	int nowpoint2 = 21;
	int nowpoint3 = 36;*///玩家现在的地点
	int nowpoint[3] = { 31,21,36 };
	int shift;                       //玩家目标点
	const int w = 10;                  //地图宽度
	int p = 0;
	int map[3][100] = {
	{
		1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,3,0,4,0,0,1,
		1,2,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,3,0,4,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,3,0,0,0,0,1,
		1,0,0,0,0,0,0,4,0,1,
		1,1,1,1,1,1,1,1,1,1
	},
		{
		0,0,1,1,1,1,1,1,1,1,
		1,1,1,0,0,0,0,0,0,1,
		1,2,1,0,3,0,4,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,1,0,3,0,4,0,0,0,1,
		0,1,0,0,0,0,0,0,0,1,
		0,1,0,0,3,0,0,0,1,1,
		0,1,0,0,0,0,0,4,1,1,
		0,1,1,1,1,1,1,1,1,1
	},
		{
		0,0,0,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,1,1,
		0,1,0,0,3,0,4,1,1,1,
		1,1,0,0,1,0,2,1,1,1,
		1,1,0,0,0,0,0,1,1,1,
		1,1,1,3,0,4,0,0,1,1,
		1,1,1,0,0,0,0,0,1,1,
		1,1,0,0,3,0,0,0,1,1,
		0,1,0,0,0,0,0,4,1,1,
		0,1,1,1,1,1,1,1,1,1

	}
	};  //玩家地图
	

	


	flag:
	while (true)
	{
		system("cls");
		for (int i = 0; i < 100; i++)
		{
			switch (map[p][i])
			{
			case 1:std::cout << "□"; break;     //墙壁
			case 0:std::cout << "  "; break;     //空地
			case 2:std::cout << "Pe"; break;     //人
			case 3:std::cout << "■"; break;    //箱子
			case 4:std::cout << "**"; break;    //箱子目的地
			case 5:std::cout << "×"; break;    //和人重合
			case 6:std::cout << "√"; break;    //和箱子重合
			}
			if (i % w == 9)
				std::cout << '\n';
		}
		if (Isgameover(*map, 3, p))          //判断游戏是否满足结束的条件，*MAP为数组第一个元素，3为目的地的个数
		{
			break;                        //如果满足条件，游戏结束
		}
		input = _getch();


		//往上
		if (input == 'w' || input == 'W' || input == 72)
		{
			shift = map[p][nowpoint[p] - w];         //下一个移动的目标点设置给shift
			if (shift == 0)                    //当下一个目标是空地的时候
			{
				if (map[p][nowpoint[p]] == 5)       //当和箱子目标点重合的时候且需要移动到空地
				{
					map[p][nowpoint[p]] = 2;               //当前坐标设置为玩家
					map[p][nowpoint[p] - w] = map[p][nowpoint[p]];    //下一个坐标为玩家
					map[p][nowpoint[p]] = 4;              //当前坐标为箱子目标点
					nowpoint[p] -= w;                  //移动当前坐标
				}
				else                        //如果没有和箱子目标点重合，则正常移动
				{
					map[p][nowpoint[p] - w] = map[p][nowpoint[p]];
					map[p][nowpoint[p]] = shift;
					nowpoint[p] -= w;
				}
			}
			else if (shift == 4)                  //当下一个个目标点为箱子目标点时
			{
				map[p][nowpoint[p] - w] = 5;            //目标点变为人和箱子重合的图案
				map[p][nowpoint[p]] = 0;                //当前点变为空地
				nowpoint[p] -= w;                    //移动人物的坐标
			}
			else if (shift == 6 && map[p][nowpoint[p] - 2 * w] != 1)                  //如果下一个点为箱子和箱子的目标点重合
			{
				map[p][nowpoint[p] - 2 * w] = 3;                     //目标点的下一个点变为箱子
				map[p][nowpoint[p] - w] = 5;                       //下一个点变为和人重合
				map[p][nowpoint[p]] = 0;                           //人物当前点变为空地
				nowpoint[p] -= w;
			}
			else if (shift == 3)                    //目标点为箱子
			{
				if (map[p][nowpoint[p] - 2 * w] != 1 && map[p][nowpoint[p] - 2 * w] != 3 && map[p][nowpoint[p] - 2 * w] != 6)         //箱子的下一个目标点不能是墙壁，或者箱子
				{
					if (map[p][nowpoint[p] - 2 * w] == 4)                     //箱子的下一个目标点是箱子目的地
					{
						map[p][nowpoint[p] - 2 * w] = 6;                       //箱子的下一个目标点变为和箱子重合
						map[p][nowpoint[p] - w] = map[p][nowpoint[p]];             //箱子的位置变为玩家位置
						map[p][nowpoint[p]] = 0;                             //玩家为之变为空地
						nowpoint[p] -= w;                                 //移动玩家坐标
					}
					else if (map[p][nowpoint[p]] == 5)                       //目标点为箱子，并且玩家处在箱子目标点里面
					{
						map[p][nowpoint[p] - w] = map[p][nowpoint[p] - 2 * w];         //箱子向上
						map[p][nowpoint[p] - 2 * w] = shift;                  // 箱子目标点变为人物目标点
						map[p][nowpoint[p] - w] = 2;                        //箱子位置变为玩家
						map[p][nowpoint[p]] = 4;							//玩家上一个点变为箱子目的地
						nowpoint[p] -= w;
					}
					else                                          //其他情况自由移动
					{
						map[p][nowpoint[p] - 2 * w] = shift;             //箱子的目标点变为箱子
						map[p][nowpoint[p] - w] = map[p][nowpoint[p]];       //玩家目标点变为玩家
						map[p][nowpoint[p]] = 0;						//玩家下面的点变为空地
						nowpoint[p] -= w;							//移动玩家点
					}
				}
			}


		}
		//往下
		else if (input == 's' || input == 'S' || input == 80)
		{
			shift = map[p][nowpoint[p] + w];
			if (shift == 0)
			{
				if (map[p][nowpoint[p]] == 5)
				{
					map[p][nowpoint[p]] = 2;
					map[p][nowpoint[p] + w] = map[p][nowpoint[p]];
					map[p][nowpoint[p]] = 4;
					nowpoint[p] += w;
				}
				else
				{
					map[p][nowpoint[p] + w] = map[p][nowpoint[p]];
					map[p][nowpoint[p]] = shift;
					nowpoint[p] += w;
				}

			}
			else if (shift == 4)
			{
				map[p][nowpoint[p] + w] = 5;
				map[p][nowpoint[p]] = 0;
				nowpoint[p] += w;
			}
			else if (shift == 6 && map[p][nowpoint[p] + 2 * w] != 1)
			{
				map[p][nowpoint[p] + 2 * w] = 3;
				map[p][nowpoint[p] + w] = 5;
				map[p][nowpoint[p]] = 0;
				nowpoint[p] += w;
			}
			else if (shift == 3)
			{
				if (map[p][nowpoint[p] + 2 * w] != 1 && map[p][nowpoint[p] + 2 * w] != 3 && map[p][nowpoint[p] + 2 * w] != 6)
				{
					if (map[p][nowpoint[p] + 2 * w] == 4)
					{
						map[p][nowpoint[p] + 2 * w] = 6;
						map[p][nowpoint[p] + w] = map[p][nowpoint[p]];
						map[p][nowpoint[p]] = 0;
						nowpoint[p] += w;
					}
					else if (map[p][nowpoint[p]] == 5)
					{
						map[p][nowpoint[p] + w] = map[p][nowpoint[p] + 2 * w];
						map[p][nowpoint[p] + 2 * w] = shift;
						map[p][nowpoint[p] + w] = 2;
						map[p][nowpoint[p]] = 4;
						nowpoint[p] += w;
					}
					else
					{
						map[p][nowpoint[p] + 2 * w] = shift;
						map[p][nowpoint[p] + w] = map[p][nowpoint[p]];
						map[p][nowpoint[p]] = 0;
						nowpoint[p] += w;
					}
				}

			}
		}


		//往左
		else if (input == 'a' || input == 'A' || input == 75)
		{
			shift = map[p][nowpoint[p] - 1];
			if (shift == 0)
			{
				if (map[p][nowpoint[p]] == 5)
				{
					map[p][nowpoint[p]] = 2;
					map[p][nowpoint[p] - 1] = map[p][nowpoint[p]];
					map[p][nowpoint[p]] = 4;
					nowpoint[p] -= 1;
				}
				else
				{
					map[p][nowpoint[p] - 1] = map[p][nowpoint[p]];
					map[p][nowpoint[p]] = shift;
					nowpoint[p] -= 1;
				}
			}
			else if (shift == 4)
			{
				map[p][nowpoint[p] - 1] = 5;
				map[p][nowpoint[p]] = 0;
				nowpoint[p] -= 1;
			}
			else if (shift == 6 && map[p][nowpoint[p] - 2] != 1)
			{
				map[p][nowpoint[p] - 2] = 3;
				map[p][nowpoint[p] - 1] = 5;
				map[p][nowpoint[p]] = 0;
				nowpoint[p] -= 1;
			}
			else if (shift == 3)
			{
				if (map[p][nowpoint[p] - 2] != 1 && map[p][nowpoint[p] - 2] != 3 && map[p][nowpoint[p] - 2] != 6)
				{
					if (map[p][nowpoint[p] - 2] == 4)
					{
						map[p][nowpoint[p] - 1] = map[p][nowpoint[p] - 2];
						map[p][nowpoint[p] - 2] = 6;
						map[p][nowpoint[p] - 1] = map[p][nowpoint[p]];
						map[p][nowpoint[p]] = 0;
						nowpoint[p] -= 1;
					}
					else if (map[p][nowpoint[p]] == 5)
					{
						map[p][nowpoint[p] - 1] = map[p][nowpoint[p] - 2];
						map[p][nowpoint[p] - 2] = shift;
						map[p][nowpoint[p] - 1] = 2;
						map[p][nowpoint[p]] = 4;
						nowpoint[p] -= 1;
					}
					else
					{
						map[p][nowpoint[p] - 2] = shift;
						map[p][nowpoint[p] - 1] = map[p][nowpoint[p]];
						map[p][nowpoint[p]] = 0;
						nowpoint[p] -= 1;
					}

				}

			}

		}

		//往右
		else if (input == 'd' || input == 'D' || input == 77)
		{
			shift = map[p][nowpoint[p] + 1];
			if (shift == 0)
			{
				if (map[p][nowpoint[p]] == 5)
				{

					map[p][nowpoint[p]] = 2;
					map[p][nowpoint[p] + 1] = map[p][nowpoint[p]];
					map[p][nowpoint[p]] = 4;
					nowpoint[p] += 1;
				}
				else
				{
					map[p][nowpoint[p] + 1] = map[p][nowpoint[p]];
					map[p][nowpoint[p]] = shift;
					nowpoint[p] += 1;
				}
			}
			else if (shift == 4)
			{
				map[p][nowpoint[p] + 1] = 5;
				map[p][nowpoint[p]] = 0;
				nowpoint[p] += 1;
			}
			else if (shift == 6 && map[p][nowpoint[p] + 2] != 1)
			{
				map[p][nowpoint[p] + 2] = 3;
				map[p][nowpoint[p] + 1] = 5;
				map[p][nowpoint[p]] = 0;
				nowpoint[p] += 1;
			}
			else if (shift == 3)
			{
				if (map[p][nowpoint[p] + 2] != 1 && map[p][nowpoint[p] + 2] != 3 && map[p][nowpoint[p] + 2] != 6)
				{
					if (map[p][nowpoint[p] + 2] == 4)
					{
						map[p][nowpoint[p] + 1] = map[p][nowpoint[p] + 2];
						map[p][nowpoint[p] + 2] = 6;
						map[p][nowpoint[p] + 1] = map[p][nowpoint[p]];
						map[p][nowpoint[p]] = 0;
						nowpoint[p] += 1;
						std::cout << "!!!";
					}
					else if (map[p][nowpoint[p]] == 5)
					{
						map[p][nowpoint[p] + 1] = map[p][nowpoint[p] + 2];
						map[p][nowpoint[p] + 2] = shift;
						map[p][nowpoint[p] + 1] = 2;
						map[p][nowpoint[p]] = 4;
						nowpoint[p] += 1;
						std::cout << "!!";
					}
					else
					{
						map[p][nowpoint[p] + 2] = shift;
						map[p][nowpoint[p] + 1] = map[p][nowpoint[p]];
						map[p][nowpoint[p]] = 0;
						nowpoint[p] += 1;
						std::cout << "!";
					}
				}
			}
		}
	}
	if (p < 3)
	{
		p++;
		goto flag;
	}
	else
	{

		system("pause");
		return 0;
	}



	

}
