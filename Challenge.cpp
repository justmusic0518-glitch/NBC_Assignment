#include <iostream>

void SetStatus(int& num1, int& num2, int Min)
{
	while (1)
	{
		if (num1 <= Min || num2 <= Min)
		{
			std::cout << "Try again. Pless typing : ";
			std::cin >> num1 >> num2;
		}
		else {
			// std::cout << num1 << "/" << num2;
			break;
		}
	}
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	if (p_HPPotion != nullptr)
	{
		*p_HPPotion = *p_HPPotion + 20;
	}
	if (p_MPPotion != nullptr)
	{
		*p_MPPotion = *p_MPPotion + 20;
	}
	std::cout << " * HP 20 + Potion - 1\n";
}

void addPotion(int& HP_Potion, int& MP_Potion)
{
	++HP_Potion;
	++MP_Potion;
}

int main()
{
	int status[] = { 0, 0, 0, 0 , 0};  // HP, MP , Power , Defense, intelligence
	int level = 0;
	int MP_count = 5;
	int HP_count = 5;
	int num = -1;
	int HM_Min = 50; // HP, MP 최솟값
	int PD_Min = 0; // Power, Defense 최솟값 
	// 지금 이 코드에는 필요 없지만 나중에 실무에서 쓸때는 올바르지않은 코드라 생각 돼 선언했음

	std::cout << " * Requirements : HP / MP > " << HM_Min << "\nPless typing HP | MP : ";
	std::cin >> status[0] >> status[1]; // HP , MP
	SetStatus(status[0], status[1], HM_Min);
	std::cout << " * Set HP / MP : " << status[0] << " / " << status[1] << std::endl;
	// HP, MP 입력 끝

	std::cout << "\n * Requirements : Power / Defense > " << PD_Min << "\nPless typing Power, Defense : ";
	std::cin >> status[2] >> status[3];
	SetStatus(status[2], status[3], PD_Min);
	std::cout << " * Set Power/Defense : " << status[2] << " / " << status[3] << std::endl;
	// 스탯 입력 끝

	std::cout << "\n * Potion supply. (HP,MP Potion +5)" << std::endl;

	while (num != 0)
	{
		std::cout << "=========================================================\n";
		std::cout << "<Stat System> \n1. HP UP \n2. MP UP \n3. Power UP \n4. Defense UP \n5. Player Stat \n6. Level UP \n0. Exit" << std::endl;
		std::cout << "Pless select number : ";
		std::cin >> num;

		switch (num)
		{
		case 1:
			if (HP_count > 0)
			{
				setPotion(HP_count, &status[0], nullptr);
				--HP_count;
				std::cout << "Player HP : " << status[0] << std::endl;
				std::cout << "Player Potion : " << HP_count << std::endl;
			}
			else
				std::cout << "WARNNING! HP Potion 0\n";
			break;
		case 2:
			if (MP_count > 0)
			{
				setPotion(MP_count, nullptr, &status[1]);
				--MP_count;
				std::cout << "Player MP : " << status[1] << std::endl;
				std::cout << "Player Potion : " << MP_count << std::endl;
			}
			else
				std::cout << "WARNNING! MP Potion 0\n";
			break;
		case 3:
			status[2] = status[2] * 2;
			std::cout << " * Power has been doubled.\n";
			std::cout << "Player Power : " << status[2] << std::endl;
			break;
		case 4:
			status[3] = status[3] * 2;
			std::cout << " * Defense has been doubled.\n";
			std::cout << "Player Defense : " << status[3] << std::endl;
			break;
		case 5:
			std::cout << " * HP : " << status[0] << ", MP : " << status[1] << ", Power : " << status[2] << 
				", Defense : " << status[3] << ", intelligence : " << status[4] << "\n * Level : " << level << ", HP / MP Potion remaining : " << HP_count << " / " << MP_count << std::endl;
			break;
		case 6:
			++level;
			addPotion(HP_count, MP_count);
			std::cout << " * Level UP! HP/MP Potion +1\n";
			break;
		}
	}
	std::cout << "Exit Program.";
}