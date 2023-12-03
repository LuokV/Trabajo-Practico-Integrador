#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Crosshair {

	Texture cross_texture;
	Sprite cross;

public:

	Crosshair();

	void Dibujar(RenderWindow* App);

	void Posicion(float x, float y);
	
	Vector2f PosicionActual();

};

