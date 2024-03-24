#pragma once

class Clock
{
public:
	Clock();

	int time = 0;

	int get_current_time();

	void update();

	void set_time(int _time);

	int start_timer();
	int end_timer();

	int ticks();

	int get_difference;

	bool timer_on;

private:
	int start;
	int end;

};