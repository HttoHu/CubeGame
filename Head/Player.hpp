#ifndef PALYER_H
#define PALYER_H
enum State
{
  Black=1,Red=2,Gray=3,Empty=0
};
enum State next_player(const State &s);
#endif
