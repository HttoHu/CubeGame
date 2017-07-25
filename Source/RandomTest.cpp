#include "../Head/RandomTest.hpp"
#include <time.h>
std::vector<int> random_array_make(int begin, int end)
{
	std::vector<int> ret;
	std::set<int> dic;
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> range(begin, end);
	int current;
	int count = end - begin+1;
	for (int i = begin;i<= end; i++)
	{
		dic.insert(i);
	}
	for (int i = begin; i <= end; i++)
	{
		current = range(e);
		e.seed(clock());
		if (dic.find(current) == dic.end())
		{
			i--;
			continue;
		}
		ret.push_back(current);
		dic.erase(current);
	}
	return ret;
}

void random_test()
{
	std::vector<int> present = random_array_make(0, 26);
	for (const auto & a : present)
	{
		switch (player_state())
		{
		case State::Black:
			push(get_coor_by_array_pos(a));
#ifndef HIDE_PROCESS
			std::cout << "Black:";
			std::cout << get_coor_by_array_pos(a).to_string() << std::endl;
#endif
			if (judge(State::Black))
			{
				std::cout << "Black Win.\n";
				mark(State::Black);
				return;
			}
			break;
		case State::Red:
			push(get_coor_by_array_pos(a));
#ifndef HIDE_PROCESS
			std::cout << "Red:";
			std::cout << get_coor_by_array_pos(a).to_string() << std::endl;
#endif
			if (judge(State::Red))
			{
				std::cout << "Red Win.\n";
				mark(State::Red);
				return;
			}
			break;
		case State::Gray:
			push(get_coor_by_array_pos(a));
#ifndef HIDE_PROCESS
			std::cout << "Gray:";
			std::cout << get_coor_by_array_pos(a).to_string() << std::endl;
#endif
			if (judge(State::Gray))
			{
				std::cout << "Gray Win.\n";
				mark(State::Gray);
				return;
			}
			break;
		default:
			break;
		}
	}
}
