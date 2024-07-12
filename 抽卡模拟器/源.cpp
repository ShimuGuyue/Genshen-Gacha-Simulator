#include <iostream>
#include <ctime>

int A(0);
bool AA(false);
int S(0);
bool SS(false);

int countB(0);
int countA(0);
int countAA(0);
int countS(0);
int countSS(0);

void showMenu(void);
void cardDraw(void);

int main(void)
{
	srand(time(0));
	showMenu();
	return 0;
}

void showMenu(void)
{
	std::cout << "**********欢迎使用抽卡模拟器！！！**********" << std::endl;
	std::cout << "\n说明 ：B - 蓝色  A - 紫色（歪） AA - 紫色（UP） S - 金色（歪） SS - 金色（UP）\n" << std::endl;
	std::cout << "----------按下ENTER键继续:----------" << std::endl;
	getchar();

	while (1)
	{
		std::cout << "*****请选择你要抽卡的次数：" << std::endl;
		std::cout << "     A)单抽     B)十连     C)查看当前保底情况     D)查看当前抽卡情况统计     Q)结束抽卡" << std::endl;
		char mod;
		std::cin >> mod;
		std::cout << "------------------------------" << std::endl;;
		if (mod == 'A' || mod == 'a')
			cardDraw();
		else if (mod == 'B' || mod == 'b')
			for (int i(1); i <= 10; ++i)
				cardDraw();
		else if (mod == 'C' || mod == 'c')
		{
			std::cout << "距离下次出 A 至多还差" << 10 - A << "抽" << std::endl;
			if(AA)
				std::cout << "当前 A 级拥有大保底" << std::endl;
			else
				std::cout << "当前 A 级不拥有大保底" << std::endl;

			std::cout << "距离下次出 S 至多还差" << 90 - S << "抽" << std::endl;
			if (SS)
				std::cout << "当前 S 级拥有大保底" << std::endl;
			else
				std::cout << "当前 S 级不拥有大保底" << std::endl;
		}
		else if (mod == 'D' || mod == 'd')
		{
			std::cout << "当前抽卡数量统计：" << std::endl;
			std::cout << "总抽数：" << countA + countAA + countS + countSS + countB << "抽" << std::endl;
			std::cout << "B总数：" << countB << "个" << std::endl;
			std::cout << "A总数：" << countA << "个" << std::endl;
			std::cout << "AA总数：" << countAA << "个" << std::endl;
			std::cout << "S总数：" << countS << "个" << std::endl;
			std::cout << "SS总数：" << countSS << "个" << std::endl;
		}
		else if (mod == 'Q' || mod == 'q')
		{
			std::cout << "**********再见，感谢您的使用！！！**********";
			break;
		}
		else
			std::cout << "*****错误的选项！！！请重新输入：";

		//std::cout << "----------按下ENTER键继续:----------" << std::endl;
		//getchar();
		//getchar();
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	getchar();
	getchar();
	return;
}

void cardDraw(void)
{
	bool ifS(false);
	if (S <= 72)
	{
		int randNum(rand() % 10000 + 1);
		if (randNum <= 60)
			ifS = true;
	}
	else if (73 <= S && S <= 88)
	{
		int randNum(rand() % 10000 + 1);
		if (randNum <= 60 + 600 * (S - 73))
			ifS = true;
	}
	else if (S == 89)
	{
		ifS = true;
	}

	if (ifS)//出金
	{
		if (SS)//大保底
		{
			++countSS;
			std::cout << "SS!!!!!!!!!!" << std::endl;
			A = 0;
			AA = false;
			S = 0;
			SS = false;
		}
		else//小保底
		{
			bool ifSS(false);
			int randNum(rand() % 100 + 1);
			if (randNum <= 50)
				ifSS = true;

			if (ifSS)//UP
			{
				++countSS;
				std::cout << "SS!!!!!!!!!!" << std::endl;
				A = 0;
				AA = false;
				S = 0;
				SS = false;
			}
			else//歪
			{
				++countS;
				std::cout << "S!!!!!" << std::endl;
				A = 0;
				AA = false;
				S = 0;
				SS = true;
			}
		}
	}
	else//没出金
	{
		++S;

		bool ifA(false);
		if (A <= 7)
		{
			int randNum(rand() % 10000 + 1);
			if (randNum <= 510)
				ifA = true;
		}
		else if (A == 8)
		{
			int randNum(rand() % 10000 + 1);
			if (randNum <= 5610)
				ifA = true;
		}
		else if (A == 9)
		{
			ifA = true;
		}

		if (ifA)//出紫
		{
			if (AA)//大保底
			{
				++countAA;
				std::cout << "AA!!!" << std::endl;
				A = 0;
				AA = false;
			}
			else//小保底
			{
				bool ifAA(false);
				int randNum(rand() % 100 + 1);
				if (randNum <= 50)
					ifAA = true;

				if (ifAA)//UP
				{
					++countAA;
					std::cout << "AA!!!" << std::endl;
					A = 0;
					AA = false;
				}
				else//歪
				{
					++countA;
					std::cout << "A!" << std::endl;
					A = 0;
					AA = true;
				}
			}
		}
		else//不出紫
		{
			++A;
			++countB;
			std::cout << "B" << std::endl;
		}
	}
	return;
}

#if NULL
*****************************
*                           *
*     Written               *
*          by               *
*          Shimu Guyue      *
*                           *
***************************** 
#endif