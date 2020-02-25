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

	// 立ち下がり
	void fall();

	// 立ち下がりを発生させるべきか
	bool should_fall();

	// 有効ならtrue
	bool is_enable(int detail_index);

private:
	struct waiting
	{
		int detail_index;
		bool enable;

		waiting(const int detail_index, const bool enable) : detail_index(detail_index), enable(enable) {}
	};

	std::vector<bool> enables_; // dllの有効・無効リスト
	std::queue<waiting> waitings_; // 次回立ち上がりで有効・無効になるdll
	bool should_fall_; // 立ち下りを発生させるべきか
};
