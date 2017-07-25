#include "../Head/Umpire.hpp"
enum State& player_state()
{
  static enum State present=Black;
  return present;
}
std::array<State,27>& Data()
{
  static std::array<State,27> arr={Empty};
  return arr;
}
Coor get_coor_by_array_pos(int pos)
{
  if(pos<0||pos>26)
    throw std::runtime_error("over the range sir!");
  Coor ret;
  ret.z=pos/9+1;
  pos=pos%9;
  ret.y=pos/3+1;
  pos=pos%3;
  ret.x=pos+1;
  return ret;
}
int get_pos_by_coor(const Coor & c)
{
  int pos=(c.x-1)+(c.y-1)*3+(c.z-1)*9;
  if(pos<0||pos>26)
    throw std::out_of_range("sir your step out of range!");
  return pos;
}
void push(const Coor & c)
{
  if(c.x==99)
    std::abort();
  int pos=get_pos_by_coor(c);
  if(Data()[pos]!=Empty)
    throw 2;
  Data()[pos]=player_state();
  player_state()=next_player(player_state());
}
bool judge(const State & s)
{
  std::vector<Coor> v;
  for (int i=0;i<27;i++)
  {
    if(Data()[i]==s)
      v.push_back(get_coor_by_array_pos(i));
  }
  if(v.size()<3)
    return false;
  for (int i=0;i<v.size();i++)
    for (int j=0;j<v.size();j++)
      for (int k=0;k<v.size();k++)
      {
        if(i==j||i==k||j==k)
          continue;
        else if(Coor::InALine(v[i],v[j],v[k]))
            return true;
      }
  return false;
}
