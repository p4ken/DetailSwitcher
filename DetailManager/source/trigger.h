#pragma once

class trigger
{
public:
	trigger();
	void reset();

	// if this...
	void set_time(int ms);
	void set_distance(double distance);
	void set_door_open();
	void set_door_close();

	// then that...
	bool is_enable(const int detail_index) const;
	void output_company(int* p_panel);

private:
	int company_;
	double distance_; // [m]
	bool door_opened_;
	int countdown_; // [ms]
	int last_time_; // [ms]
};
