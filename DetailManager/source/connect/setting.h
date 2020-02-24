#pragma once

#include <string>
#include <vector>
#include <memory>


class setting
{
public:
	// �������g��DLL�̐�΃p�X
	void set_module_directory(const wchar_t* module_dir);

	// �I����Ԃ̏o�͂Ɏg���p�l���̓Y��
	int get_state_output_panel_index() const;

	// �ؑւ̃g���K�[�ɂȂ�n��q�̎��
	int get_beacon_type() const;

	// DLL�ւ̃p�X
	std::vector<std::string> get_detail_paths() const;
};

using setting_ptr = std::shared_ptr<setting>;
