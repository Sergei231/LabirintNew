#include <cmath>

#include <numbers>

#include "Player.h"

static double pi = std::numbers::pi;

void Player::set_walk_check_function(WalkCheckFunction wcf) {
  if (wcf == nullptr) {
    _wcf = [](double, double) -> bool {
      return false;
    };
  } else {
    _wcf = wcf;
  }
}

void Player::spawn(const Point3D_Cart & pos,
  const Point3D_Sph & dir) {
  _pos = pos;
  _dir = dir;
}

void Player::walk_forward(double d) {
  double nx = _pos.x + d * sin(_dir.phi);
  double ny = _pos.y + d * cos(_dir.phi);

  if (_wcf(nx, ny) == true) {
    _pos.x = nx;
    _pos.y = ny;
  }
}

void Player::walk_backward(double d) {
  walk_forward(-d);
}

void Player::strafe_right(double d) {
  double nx = _pos.x + d * sin(_dir.phi + pi / 2.0);
  double ny = _pos.y + d * cos(_dir.phi + pi / 2.0);

  if (_wcf(nx, ny) == true) {
    _pos.x = nx;
    _pos.y = ny;
  }
}

void Player::strafe_left(double d) {
  strafe_right(-d);
}

void Player::turn_right(double dphi) {
  _dir.phi += dphi;
  if (_dir.phi >= 2. * pi)
    _dir.phi -= 2. * pi;
}

void Player::turn_left(double dphi) {
  _dir.phi -= dphi;
  if (_dir.phi < 0.)
    _dir.phi += 2. * pi;
}

void Player::turn_up(double dtheta) {
  _dir.theta -= dtheta;
  if (_dir.theta < VERTICAL_LIMIT)
    _dir.theta = VERTICAL_LIMIT;
}

void Player::turn_down(double dtheta) {
  _dir.theta += dtheta;
  if (_dir.theta > (pi - VERTICAL_LIMIT))
    _dir.theta = (pi - VERTICAL_LIMIT);
}