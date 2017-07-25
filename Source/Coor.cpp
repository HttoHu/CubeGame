#include "../Head/Coor.hpp"
#include <iostream>
double Coor::distance(const Coor & args)const
{
  double ret;
  ret=sqrt((x-args.x)*(x-args.x)+(y-args.y)*(y-args.y)+(z-args.z)*(z-args.z));
  return ret;
}
Coor Coor::make_vector(const Coor & a,const Coor & b)
{
   Coor ret(b.x-a.x,b.y-a.y,b.z-a.z);
   return ret;
}
bool Coor::InALine(const Coor & a,const Coor & b,const Coor & c)
{
  Coor v1=make_vector(a,b);
  Coor v2=make_vector(a,c);
  double d1=v1.distance(Coor(0,0,0));
  double d2=v2.distance(Coor(0,0,0));
  double m=v1*v2;
  double n=d1*d2;
  int asn=m/n;
  if(asn==1||asn==-1)
    return true;
  return false;
}
double Coor::operator* (const Coor & c)const
{
  return x*c.x+y*c.y+z*c.z;
}
Coor Coor::operator+ (const Coor & c)const
{
  Coor ret(x+c.x,y+c.y,z+c.z);
  return ret;
}
Coor Coor::operator- (const Coor & c)const
{
  Coor ret(x-c.x,y-c.y,z-c.z);
  return ret;
}
std::string Coor::to_string()const
{
  std::string ret;
  ret+="(";
  ret+=std::to_string(x)+","+std::to_string(y)+","+std::to_string(z)+")";
  return ret;
}
