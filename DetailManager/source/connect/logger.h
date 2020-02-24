#pragma once
#include <fstream>

class logger
{
public:
	// �V���O���g��
	static logger& get_logger();

	// �R���X�g���N�^
	logger();

	// �G���[�o��
	void write_error(const std::string& text);

	// �f�o�b�O���o��
	void write_debug(const std::string& text);

private:
	std::ofstream log_file_;
};
