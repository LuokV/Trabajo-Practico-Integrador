#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace sf;

class Enemigo {

	Texture enemy_texture;
	Sprite pistolero;
	Texture bang_texture;
	Sprite bang;

	bool vivo;
	bool visible;



public:

	Enemigo();

	bool EnPantalla();

	void PosicionAzar();

	void Dibujar(RenderWindow* App);

	bool Encima(float x, float y);

	void Derrotar();

	void Invisible();

	void Visible();

	void Revivir();

	void Disparo_Bang(RenderWindow* App);

};

