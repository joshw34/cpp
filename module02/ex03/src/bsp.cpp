#include "../inc/Point.hpp"

static bool check_value(const Fixed& abc, const Fixed& total) {
	int diff = abc.getRawBits() - total.getRawBits();

	return diff >= -1 && diff <= 1; 
}

static Fixed getArea(const Point a, const Point b, const Point c) {
	//Area = |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)| / 2
	Fixed va(a.getX() * (b.getY() - c.getY()));
	Fixed vb(b.getX() * (c.getY() - a.getY()));
	Fixed vc(c.getX() * (a.getY() - b.getY()));

	Fixed result((va + vb + vc) / 2);
	
	if (result < 0)
		result =  result * -1;
	
	return result;
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	Fixed abc = getArea(a, b, c);
	if (abc == 0)
		return  false;

	Fixed pab = getArea(point, a, b);
	if (pab == 0)
		return false;

	Fixed pbc = getArea(point, b, c);
	if (pbc == 0)
		return false;

	Fixed pca = getArea(point, c, a);
	if (pca == 0)
		return false;

	Fixed total = pab + pbc + pca;
	
	return check_value(abc, total);
}
