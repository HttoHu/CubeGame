#include "../Head/Player.hpp"
enum State next_player(const State &s)
{
  switch (s)
   {
    case Black:
      return Red;
    case Red:
      return Gray;
    case Gray:
      return Black;
  }
}
