struct circle {
	ll x, y, r;
	circle() {};
	circle(ll _x, ll _y, ll _r) {
		x = _x;
		y = _y;
		r = _r;
}};

double dist(circle p1, circle p2) {
	ll x = p1.x-p2.x;
	ll y = p1.y-p2.y;
	return sqrt(x*x + y*y);
}

// What if the circles intersect ??
pdd DistRange(circle a, circle b) {
	pdd ret;
	if(a.r < b.r) swap(a, b);
	double d = dist(a, b);
	// a.r > b.r
	// a & b doesn't coincide (touches or not touches)
	if(d >= a.r+b.r)
		ret.first = max(d-a.r-b.r, 0.0), ret.second = d+a.r+b.r;
	else {		// a & b coincides (touches or not touches)
		if(d == a.r-b.r)			// a & b touches
			ret.first = 0;
		else						// a & b not touches
			ret.first = a.r-d-b.r;
		ret.second = a.r+d+b.r;		// a & b touch or not touch max is same?
	}
	return ret;
}
