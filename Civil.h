#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace sf;

class Inocente {

	Texture inocente_texture;
	Sprite inocente;

	bool vivo;
	bool visible;
	

public:

	Inocente();

	bool EnPantalla();

	void PosicionAzar();

	void Dibujar(RenderWindow* App);

	bool Encima(float x, float y);

	void Derribado();

	void Invisible();

	void Visible();

	void Revivir();

};
