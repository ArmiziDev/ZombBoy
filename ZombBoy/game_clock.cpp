#include "game_clock.h"

Clock::Clock()
{
	time = 0;
	start = 0;
	end = 0;
	timer_on = false;

}

int Clock::get_current_time()
{
	return time;
}

void Clock::update()
{
	time += 1;
	if (timer_on)
	{
		end += 1;
	}
}

void Clock::set_time(int _time)
{
	time = _time;
}

int Clock::start_timer()
{
	timer_on = true;
	start = time;
	end = time;

	// returns the current time that it started on
	return time;
}

int Clock::end_timer()
{
	timer_on = false;

	return time;
}

int Clock::ticks() 
{
	return end - start;
}

