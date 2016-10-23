##
#  IEEExtreme Programming Contest 10
#  Problem : Food Truck
#  Solver  : M Visat Sutarno
#  Status  : Accepted
#

from sys import stdin, stdout
from datetime import datetime
from decimal import Decimal
from math import asin, sin, cos, sqrt, radians

lat1, long1 = map(float, stdin.readline().rstrip().split(","))
lat1, long1 = radians(lat1), radians(long1)
r = float(stdin.readline().rstrip())
stdin.readline()

numbers = {}
for line in stdin:
    dt, lat2, long2, pn = line.rstrip().split(",")
    dt = datetime.strptime(dt, '%m/%d/%Y %H:%M')
    lat2 = radians(float(lat2))
    long2 = radians(float(long2))

    dlat = lat1-lat2
    dlong = long1-long2
    a = sqrt(sin(dlat/2)**2 + cos(lat1) * cos(lat2) * sin(dlong/2)**2)
    if a > 1.0:
        a = 1.0
    elif a < -1.0:
        a = -1.0
    d = (2.0) * (asin(a)) * (6378.137)
    if pn in numbers:
        (dt2, d2) = numbers[pn]
        if dt < dt2:
            continue
    numbers[pn] = (dt, d)

pns = [pn for pn, (dt, d) in numbers.items() if d <= r]
pns.sort()
stdout.write(",".join(pns))
stdout.write("\n")
