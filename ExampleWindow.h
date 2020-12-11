#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"

class ExampleWindow: public Window{
protected:
	std::shared_ptr<SDL_Texture> _tree;
	std::shared_ptr<SDL_Texture> _car2;
	std::shared_ptr<SDL_Texture> _car1;
	std::shared_ptr<SDL_Texture> _flyLeft;
	std::shared_ptr<SDL_Texture> _flyRight;

	int x_car;
	bool boolFly;
	int x_fly, y_fly;

public:
	ExampleWindow(
		int width = DEFAULT_WIDTH,
		int height = DEFAULT_HEIGHT);
	virtual ~ExampleWindow() = default;

	virtual void render() override;
	virtual void do_logic() override;
	virtual void handle_keys(const Uint8 *keys) override;
	virtual void handle_event(const SDL_Event &event) override;
};

#endif /* EXAMPLEWINDOW_H_ */
