#pragma once
#include <queue>
#include <vector>

class switcher
{
public:
	switcher();
	
	void enable(int detail_index);

	void enable_when_rise(int detail_index);

	void rise();

	bool is_enable(int detail_index);
	
private:
	std::vector<bool> enables_; // dll�̗L���E�������X�g
	std::queue<int> waiting_enable_; // ���񗧂��オ��ŗL���ɂȂ�dll
	std::queue<int> waiting_disable_; // ���񗧂��オ��Ŗ����ɂȂ�dll
};
