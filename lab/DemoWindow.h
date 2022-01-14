#ifndef DEMOWINDOW_H_

#define DEMOWINDOW_H_

#include <memory>

#include "Window.h"

#include "Map.h"

#include "Player.h"


class DemoWindow final : public Window
{
protected:
	double _cube_angle { 0. };
	std::shared_ptr<Map> _map;
	Player _player;

	GLuint _wall_list { 0 }, _space_list { 0 };

	void draw_cube();
	void draw_wall();
	void draw_space();

public:
	DemoWindow(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~DemoWindow() = default;

	virtual void setup_gl() override;
	virtual void render() override;
	virtual void update() override;
	virtual void handle_keys(const Uint8 *keys) override;
	virtual void handle_event(const SDL_Event &event) override;
};

#endif /* DEMOWINDOW_H_ */
