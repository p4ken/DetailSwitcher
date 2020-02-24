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
	std::vector<bool> enables_; // dllの有効・無効リスト
	std::queue<int> waiting_enable_; // 次回立ち上がりで有効になるdll
	std::queue<int> waiting_disable_; // 次回立ち上がりで無効になるdll
};
