#ifndef WINDOW_H_

#define WINDOW_H_

#include <memory>

#include <SDL2/SDL.h>

#include <GL/gl.h>

#include <GL/glu.h>

class Window
{
public:
	static constexpr int DEFAULT_WIDTH = 800;
	static constexpr int DEFAULT_HEIGHT = 600;
	static constexpr int DEFAULT_X = SDL_WINDOWPOS_CENTERED_DISPLAY(1);
	static constexpr int DEFAULT_Y = SDL_WINDOWPOS_CENTERED_DISPLAY(1);

private:
	std::shared_ptr<SDL_Window> _window; // okno
	std::shared_ptr<void> _gl_context; // KOntekst OpenGL
	int _width, _height; // Shirina i Visota

public:
	Window(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~Window() = default;

	void set_title(const char * title) { SDL_SetWindowTitle(_window.get(), title); }

	int height() const { return _height; }
	int width() const  { return _width;  }

	void main_loop();

	virtual void setup() {}
	virtual void setup_gl() {}
	virtual void update() {}
	virtual void render() {}
	virtual void handle_event(const SDL_Event& event) {}
	virtual void handle_keys(const Uint8 * keys) {}
};

#endif /* WINDOW_H_ */
