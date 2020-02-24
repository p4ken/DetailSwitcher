#pragma once
#include "source/connect/setting.h"
#include "source/detail/switcher.h"

class beacon
{
public:
	explicit beacon(switcher& switcher);
	
	enum class command
	{
		enable_when_rise = 1, // ����}�X�R���L�[�����オ��ŗL��
		disable_when_rise = 2, // ����}�X�R���L�[�����オ��Ŗ���
		enable_immediately = 5, // �����L��
		disable_immediately = 6, // ��������
	};

	void set_setting(const setting& setting);

	void set_beacon(int type, int option);

private:
	switcher& switcher_;
	int beacon_type_;
};
