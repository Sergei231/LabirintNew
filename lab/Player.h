#ifndef PLAYER_H_

#define PLAYER_H_

#include <functional>

#include "Coords.h"

class Player final
{
public:
	static constexpr double DEFAULT_WALK_DISTANCE = 0.01;
	static constexpr double DEFAULT_TURN_ANGLE = 0.02;
	static constexpr double VERTICAL_LIMIT = 0.05;

	using WalkCheckFunction = std::function<bool(double, double)>;
protected:
	Point3D_Cart _pos;
	Point3D_Sph  _dir;

	WalkCheckFunction _wcf { [](double, double)->bool { return false; } }; // @suppress("Invalid arguments")
public:
	Player() = default;

	void set_walk_check_function(WalkCheckFunction wcf);

	void spawn(const Point3D_Cart& pos, const Point3D_Sph& dir);

	void walk_forward(double d = DEFAULT_WALK_DISTANCE);
	void walk_backward(double d = DEFAULT_WALK_DISTANCE);
	void strafe_left(double d = DEFAULT_WALK_DISTANCE);
	void strafe_right(double d = DEFAULT_WALK_DISTANCE);
	void turn_right(double dphi = DEFAULT_TURN_ANGLE);
	void turn_left (double dphi = DEFAULT_TURN_ANGLE);
	void turn_up(double dtheta = DEFAULT_TURN_ANGLE);
	void turn_down(double dtheta = DEFAULT_TURN_ANGLE);

	const Point3D_Sph& dir() const { return _dir; }
	const Point3D_Cart& pos() const { return _pos; }
};

#endif /* PLAYER_H_ */
