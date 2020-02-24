#pragma once
#include <fstream>

class logger
{
public:
	// シングルトン
	static logger& get_logger();

	// コンストラクタ
	logger();

	// エラー出力
	void write_error(const std::string& text);

	// デバッグ情報出力
	void write_debug(const std::string& text);

private:
	std::ofstream log_file_;
};
