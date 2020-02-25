#pragma once

class trigger
{
public:
	// if this...
	void set_time(int ms);
	void set_distance(double distance);
	void set_door_open();

	// then that...
	bool is_enable(int detail_index);
	void output_company(int* p_panel);
};
