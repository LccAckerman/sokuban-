#include <iostream>
#include<conio.h>

bool Isgameover(int* map, int Rbox ,int q )     //Rbox  Ϊ�˷�����չ���˲���ΪĿ�ĵظ���
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
		std::cout << "��ϲͨ�أ�����\n";
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int input;						//���볣��
	/*int nowpoint[p] = 31;
	int nowpoint2 = 21;
	int nowpoint3 = 36;*///������ڵĵص�
	int nowpoint[3] = { 31,21,36 };
	int shift;                       //���Ŀ���
	const int w = 10;                  //��ͼ���
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
	};  //��ҵ�ͼ
	

	


	flag:
	while (true)
	{
		system("cls");
		for (int i = 0; i < 100; i++)
		{
			switch (map[p][i])
			{
			case 1:std::cout << "��"; break;     //ǽ��
			case 0:std::cout << "  "; break;     //�յ�
			case 2:std::cout << "Pe"; break;     //��
			case 3:std::cout << "��"; break;    //����
			case 4:std::cout << "**"; break;    //����Ŀ�ĵ�
			case 5:std::cout << "��"; break;    //�����غ�
			case 6:std::cout << "��"; break;    //�������غ�
			}
			if (i % w == 9)
				std::cout << '\n';
		}
		if (Isgameover(*map, 3, p))          //�ж���Ϸ�Ƿ����������������*MAPΪ�����һ��Ԫ�أ�3ΪĿ�ĵصĸ���
		{
			break;                        //���������������Ϸ����
		}
		input = _getch();


		//����
		if (input == 'w' || input == 'W' || input == 72)
		{
			shift = map[p][nowpoint[p] - w];         //��һ���ƶ���Ŀ������ø�shift
			if (shift == 0)                    //����һ��Ŀ���ǿյص�ʱ��
			{
				if (map[p][nowpoint[p]] == 5)       //��������Ŀ����غϵ�ʱ������Ҫ�ƶ����յ�
				{
					map[p][nowpoint[p]] = 2;               //��ǰ��������Ϊ���
					map[p][nowpoint[p] - w] = map[p][nowpoint[p]];    //��һ������Ϊ���
					map[p][nowpoint[p]] = 4;              //��ǰ����Ϊ����Ŀ���
					nowpoint[p] -= w;                  //�ƶ���ǰ����
				}
				else                        //���û�к�����Ŀ����غϣ��������ƶ�
				{
					map[p][nowpoint[p] - w] = map[p][nowpoint[p]];
					map[p][nowpoint[p]] = shift;
					nowpoint[p] -= w;
				}
			}
			else if (shift == 4)                  //����һ����Ŀ���Ϊ����Ŀ���ʱ
			{
				map[p][nowpoint[p] - w] = 5;            //Ŀ����Ϊ�˺������غϵ�ͼ��
				map[p][nowpoint[p]] = 0;                //��ǰ���Ϊ�յ�
				nowpoint[p] -= w;                    //�ƶ����������
			}
			else if (shift == 6 && map[p][nowpoint[p] - 2 * w] != 1)                  //�����һ����Ϊ���Ӻ����ӵ�Ŀ����غ�
			{
				map[p][nowpoint[p] - 2 * w] = 3;                     //Ŀ������һ�����Ϊ����
				map[p][nowpoint[p] - w] = 5;                       //��һ�����Ϊ�����غ�
				map[p][nowpoint[p]] = 0;                           //���ﵱǰ���Ϊ�յ�
				nowpoint[p] -= w;
			}
			else if (shift == 3)                    //Ŀ���Ϊ����
			{
				if (map[p][nowpoint[p] - 2 * w] != 1 && map[p][nowpoint[p] - 2 * w] != 3 && map[p][nowpoint[p] - 2 * w] != 6)         //���ӵ���һ��Ŀ��㲻����ǽ�ڣ���������
				{
					if (map[p][nowpoint[p] - 2 * w] == 4)                     //���ӵ���һ��Ŀ���������Ŀ�ĵ�
					{
						map[p][nowpoint[p] - 2 * w] = 6;                       //���ӵ���һ��Ŀ����Ϊ�������غ�
						map[p][nowpoint[p] - w] = map[p][nowpoint[p]];             //���ӵ�λ�ñ�Ϊ���λ��
						map[p][nowpoint[p]] = 0;                             //���Ϊ֮��Ϊ�յ�
						nowpoint[p] -= w;                                 //�ƶ��������
					}
					else if (map[p][nowpoint[p]] == 5)                       //Ŀ���Ϊ���ӣ�������Ҵ�������Ŀ�������
					{
						map[p][nowpoint[p] - w] = map[p][nowpoint[p] - 2 * w];         //��������
						map[p][nowpoint[p] - 2 * w] = shift;                  // ����Ŀ����Ϊ����Ŀ���
						map[p][nowpoint[p] - w] = 2;                        //����λ�ñ�Ϊ���
						map[p][nowpoint[p]] = 4;							//�����һ�����Ϊ����Ŀ�ĵ�
						nowpoint[p] -= w;
					}
					else                                          //������������ƶ�
					{
						map[p][nowpoint[p] - 2 * w] = shift;             //���ӵ�Ŀ����Ϊ����
						map[p][nowpoint[p] - w] = map[p][nowpoint[p]];       //���Ŀ����Ϊ���
						map[p][nowpoint[p]] = 0;						//�������ĵ��Ϊ�յ�
						nowpoint[p] -= w;							//�ƶ���ҵ�
					}
				}
			}


		}
		//����
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


		//����
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

		//����
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
