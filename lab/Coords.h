#ifndef COORDS_H_
#define COORDS_H_

struct Point3D_Cart;

struct Point3D_Sph;

struct Point3D_Sph
{
	double r, phi, theta;
	Point3D_Sph() { r = phi = theta = 0.0; }
	Point3D_Sph(double pr, double pphi, double ptheta) { r = pr; phi = pphi; theta = ptheta; }
	Point3D_Sph(const Point3D_Sph& ps) { r = ps.r; phi = ps.phi; theta = ps.theta; }
	Point3D_Sph(const Point3D_Cart& p);
};

struct Point3D_Cart
{
	double x, y, z;
	Point3D_Cart() { x = y = z = 0.0; }
	Point3D_Cart(double px, double py, double pz) { x = px; y = py; z = pz; }
	Point3D_Cart(const Point3D_Cart& p) { x = p.x; y = p.y; z = p.z; }
	Point3D_Cart(const Point3D_Sph& ps);
};


#endif /* COORDS_H_ */
