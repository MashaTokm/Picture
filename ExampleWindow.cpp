#include "ExampleWindow.h"
#include <stdexcept>
#include <iostream>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

ExampleWindow::ExampleWindow(int width, int height)
:Window(width, height) {
	x_car = 1300;
	boolFly = true;
	x_fly = 600, y_fly = 200;

	_tree = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "tree.png"),
			SDL_DestroyTexture
	);

	_car2 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "car2.png"),
			SDL_DestroyTexture
	);

	_car1 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "car.png"),
			SDL_DestroyTexture
	);

	_flyLeft = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "flyLeft.png"),
			SDL_DestroyTexture
	);

	_flyRight = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "flyRight.png"),
			SDL_DestroyTexture
	);
}

void ExampleWindow::render() {
	//Земля
	SDL_SetRenderDrawColor(_renderer.get(), 0, 128, 0, 255);
	SDL_Rect ground {0, 420, 1280, 300};
	SDL_RenderFillRect(_renderer.get(), &ground);

	SDL_SetRenderDrawColor(_renderer.get(), 100, 100, 100, 255);
	SDL_Rect road1 {0, 550, 1280, 150};
	SDL_RenderFillRect(_renderer.get(), &road1);

	for(double x1 = 640, x2 = 640, y = 300; y <= 550; x1 -= 0.4, x2 += 0.4, y++){
		SDL_RenderDrawLine(_renderer.get(), x1, y, x2, y);
	}

	//Небо
	SDL_SetRenderDrawColor(_renderer.get(), 175, 238, 238, 255);
	SDL_Rect nebo {0, 0, 1280, 420};
	SDL_RenderFillRect(_renderer.get(), &nebo);

	if (boolFly){
		SDL_Rect fly1 {x_fly, y_fly, 129, 100};
		SDL_RenderCopy(_renderer.get(), _flyLeft.get(), nullptr, &fly1);
	} else {
		SDL_Rect fly2 {x_fly, y_fly, 129, 100};
		SDL_RenderCopy(_renderer.get(), _flyRight.get(), nullptr, &fly2);
	}


	SDL_Rect tree1 {-100, 130, 300, 319};
	SDL_RenderCopy(_renderer.get(), _tree.get(), nullptr, &tree1);

	SDL_Rect tree2 {1080, 130, 300, 319};
	SDL_RenderCopy(_renderer.get(), _tree.get(), nullptr, &tree2);

	SDL_Rect car2 {565, 370, 150, 110};
	SDL_RenderCopy(_renderer.get(), _car2.get(), nullptr, &car2);

	//Забор (Крепежи)
	for(int y = 340; y < 460; y += 110){
		SDL_SetRenderDrawColor(_renderer.get(), 104, 62, 0, 255);
		SDL_Rect fenceTwo {0, y+1, 200, 8};
		SDL_RenderFillRect(_renderer.get(), &fenceTwo);
	}

	for(int y = 340; y < 460; y += 110){
		SDL_SetRenderDrawColor(_renderer.get(), 104, 62, 0, 255);
		SDL_Rect fenceTwo {850, y+1, 1300, 8};
		SDL_RenderFillRect(_renderer.get(), &fenceTwo);
	}

	//Забор (Столбы)
	for (int x = 5; x <= 200; x += 40){
		SDL_SetRenderDrawColor(_renderer.get(), 151, 80, 0, 255);
		SDL_Rect fenceTwo {x+1, 301, 28, 198};
		SDL_RenderFillRect(_renderer.get(), &fenceTwo);
	}

	for (int x = 840; x <= 1280; x += 40){
		SDL_SetRenderDrawColor(_renderer.get(), 151, 80, 0, 255);
		SDL_Rect fenceTwo {x+1, 301, 28, 198};
		SDL_RenderFillRect(_renderer.get(), &fenceTwo);
	}

	//Дом Первый
	SDL_SetRenderDrawColor(_renderer.get(), 240, 240, 100, 255);
	SDL_Rect home1 {150, 270, 300, 250};
	SDL_RenderFillRect(_renderer.get(), &home1);

	//Дом Второй
	SDL_SetRenderDrawColor(_renderer.get(), 240, 240, 100, 255);
	SDL_Rect home2 {830, 270, 300, 250};
	SDL_RenderFillRect(_renderer.get(), &home2);

	//Крыша
	SDL_SetRenderDrawColor(_renderer.get(), 247, 111, 77, 255);
	for(double x1 = 980, x2 = 980, y = 70; y <= 270; x1 -= 0.9, x2 += 0.9, y++){
		SDL_RenderDrawLine(_renderer.get(), x1, y, x2, y);
	}

	SDL_SetRenderDrawColor(_renderer.get(), 247, 111, 77, 255);
	for(double x1 = 300, x2 = 300, y = 70; y <= 270; x1 -= 0.9, x2 += 0.9, y++){
		SDL_RenderDrawLine(_renderer.get(), x1, y, x2, y);
	}

	//Двери
	SDL_SetRenderDrawColor(_renderer.get(), 77, 113, 101, 255);
	SDL_Rect door1 {200, 350, 80, 170};
	SDL_RenderFillRect(_renderer.get(), &door1);

	SDL_SetRenderDrawColor(_renderer.get(), 77, 113, 101, 255);
	SDL_Rect door2 {1000, 350, 80, 170};
	SDL_RenderFillRect(_renderer.get(), &door2);

	//Окна
	SDL_SetRenderDrawColor(_renderer.get(), 6, 192, 117, 255);
	SDL_Rect window {315, 350, 100, 100};
	SDL_RenderFillRect(_renderer.get(), &window);

	SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);
	SDL_RenderDrawLine(_renderer.get(), 365, 350, 365, 449);
	SDL_RenderDrawLine(_renderer.get(), 315, 400, 414, 400);

	SDL_SetRenderDrawColor(_renderer.get(), 6, 192, 117, 255);
	SDL_Rect window2 {865, 350, 100, 100};
	SDL_RenderFillRect(_renderer.get(), &window2);

	SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);
	SDL_RenderDrawLine(_renderer.get(), 915, 350, 915, 449);
	SDL_RenderDrawLine(_renderer.get(), 865, 400, 964, 400);

	SDL_Rect car1 {x_car, 470, 411, 200};
	SDL_RenderCopy(_renderer.get(), _car1.get(), nullptr, &car1);
}

void ExampleWindow::do_logic() {
	x_car -= 5;
	if (x_car <= -800) x_car = 1400;
}

void ExampleWindow::handle_keys(const Uint8 *keys) {
	if (keys[SDL_SCANCODE_LEFT] && x_fly >= 0){
		boolFly = true;
		x_fly -= 3;
	}

	if (keys[SDL_SCANCODE_RIGHT] && x_fly <= 1124){
		boolFly = false;
		x_fly += 3;
	}

	if (keys[SDL_SCANCODE_DOWN] && y_fly <= 250){
		y_fly += 2;
	}

	if (keys[SDL_SCANCODE_UP] && y_fly >= 0){
		y_fly -= 2;
	}
}

void ExampleWindow::handle_event(const SDL_Event &event) {

}
