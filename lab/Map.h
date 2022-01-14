#ifndef MAP_H_

#define MAP_H_

#include <vector>

enum class MapCell
{
  VOIDD,
  SPACE,
  WALL
};

class Map final
{
protected:
	int _width { 0 }, _height { 0 };
	double _start_x { 0. }, _start_y { 0. }, _start_dir { 0. };
	std::vector<std::vector<MapCell>> _cells;
public:
	Map(const char * filename);

	int height() const { return _height; }
	int width() const  { return _width;  }

	double start_dir() const { return _start_dir; }
	double start_x() const   { return _start_x; }
	double start_y() const   { return _start_y; }

	MapCell cell(int x, int y) const;

};

#endif /* MAP_H_ */
