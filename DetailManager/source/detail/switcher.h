#pragma once
#include <queue>
#include <vector>

class switcher
{
public:
	// コンストラクタ
	switcher();

	// 即時有効
	void enable(int detail_index);

	// 即時無効
	void disable(int detail_index);

	// 次回立ち上がりで有効
	void enable_when_rise(int detail_index);

	// 次回立ち上がりで無効
	void disable_when_rise(int detail_index);

	// 立ち上がり
	void rise();

	// 有効ならtrue
	bool is_enable(int detail_index);
	
private:
	std::vector<bool> enables_; // dllの有効・無効リスト
	std::queue<int> waiting_enable_; // 次回立ち上がりで有効になるdll
	std::queue<int> waiting_disable_; // 次回立ち上がりで無効になるdll
};
