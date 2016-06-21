// rotate p by theta degrees CCW w.r.t origin(0, 0)
point rotate(point p, double tetha) {
  // rotate matrix R(theta0 = [cos(theta) -sin(theta)]
  //            [sin(theta)  cos(theta)]
  double rad = tehta * PI / 180.0;
  return point(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}

// (LINE)
struct line { double a,b,c; };
void pointToLine(point p1, point p2, line *l) {
  if(p1.x == p2.x) {
    l->a = 1.0; l->b = 0.0; l->c = -p1.x;
}
else {
  l->a = -(double)(p1.y-p2.y)/(p1.x-p2.x)l
  l->b = 1.0;
  l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
}
}
bool areIntersect(line l1, line l2, point * p) {
  if(areSame(l1, l2)) return false;
  if(areParallel(l1, l2)) return false;
  
  p->x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);
  if(fabs(l1.b) > EPS)
    p->y = (l1.a*p->x + l1.c)/l1.b;
  else
    p->y = (l2.a*p->x + l2.c)/l2.b;
  return true;
}
double area(const vector< point > & P) {
  double result = 0.0;
  for(int i = 0; i< (int)P.size()-1; i++) {
    result += (P[i].x * P[i+1].y - P[i].y*P[i+1].x);
  }
  return fabs(result)/2.0;
}
// calculate angle between BA and BC
double angle(point a, point b, point c) {
  double ux = a.x - b.x, uy = a.y - b.y;
  double vx = c.x - b.x, vu = c.y - b.y;
  return acos(ux*vx + uy*vy)/sqrt((ux*ux + uy*uy)*(vx*vx + vy*vy)); }
// check if point p inside (CONVEX/CONCAVE) polygon vp
int inPolygon(point p, const vector< point >& vp) {
  int wn = 0, n = (int)vp.size() - 1;
  for(int i = 0; i<n; i++) {
    long long cs = cross(vp[i+1], vp[i], p);
    if(cs == 0 && p.x <= max(vp[i].x, vp[i+1].x) && p.x >= min(vp[i].x, vp[i+1].x)
      && p.y <= max(vp[i].y, vp[i+1].y) && p.y >= min(vp[i].y, vp[i+1].y))
      return 1;
    if(vp[i].y <= p.y) {
      if(vp[i+1].y > p.y && cs > 0)
        wn++;
    }
    else {
      if(vp[i+1].y <= p.y && cs < 0)
        wn--;
    }
  }
  return wn;
}

///// Find two center of same size circle from its intersection and their radius
bool circle2PtsRad(point p1, point p2, double r, point *c) { // answer at *c
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if(det<0.0) return false;
  double h = sqrt(det);
  c->x = (p1.x + p2.x) * 0.5 + (p1.y-p2.y)*h;
  c->y = (p1.y + p2.y) * 0.5 + (p2.x-p1.x)*h;
  return true;
}

//// The Great-Circle Distance (SPHERES)
double gcDistance(double plat, double plong, double qlat, double, qlong ,double radius) {
  plat *= PI/180; plong *= PI/180;
  qlat *= PI/180; qlong *= PI/180;
  return radius *  acos(cos(plat)*cos(plong)*cos(qlat)*cos(qlong) +
          cos(plat)*sin(plong)*cos(qlat)*sin(qlong) +
          sin(plat)*sin(qlat));
}

