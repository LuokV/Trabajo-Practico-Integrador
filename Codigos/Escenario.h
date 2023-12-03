#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Background {

	Texture backtexture;
	Sprite Fondo;

	float escalaX, escalaY;
	float anchofondo, altofondo;

public:

	Background() {

		backtexture.loadFromFile("Fondo.png");
		Fondo.setTexture(backtexture);

		anchofondo = (float)backtexture.getSize().x;
		altofondo = (float)backtexture.getSize().y;

		escalaX = 800 / anchofondo;
		escalaY = 600 / altofondo;

		Fondo.setScale(escalaX, escalaY);


	}

	void DibujoFondo(RenderWindow* App) {

		App->draw(Fondo);
	
	}

};
