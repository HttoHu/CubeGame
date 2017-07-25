#ifndef COOR_H
#define COOR_H
#include <cmath>
#include <string>
class Coor{
public:
  Coor()=default;
  Coor(double a,double b,double c):x(a),y(b),z(c){}
  double distance(const Coor & args)const;
  Coor operator+ (const Coor & c)const;
  Coor operator- (const Coor & c)const;
  double operator* (const Coor & c)const;
  Coor operator*(double d)const;
  void resetX(double a){x=a;}
  void resetY(double a){y=a;}
  void resetZ(double a){z=a;}
  void resetAll(double a,double b,double c){x=a;y=b;z=c;}

  std::string to_string()const;
  //=====================some static method==================
  static bool InALine(const Coor & a,const Coor & b,const Coor & c);
  static Coor make_vector(const Coor & a,const Coor & b);
  double x;
  double y;
  double z;
};

#endif
