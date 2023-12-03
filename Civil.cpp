#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Civil.h";


Inocente::Inocente() {

	inocente_texture.loadFromFile("Civil.png");
	inocente.setTexture(inocente_texture);
	inocente.setScale(1.2f, 1.2f);
	vivo = true;
	visible = false;

}


bool Inocente::EnPantalla() {

	return vivo && visible;

}


void Inocente::PosicionAzar() {

	srand(time(NULL));
	int azar = rand() % 5;

	switch (azar)
	{
	case 0:

		inocente.setPosition(90, 280);

		break;

	case 1:

		inocente.setPosition(600, 280);

		break;


	case 2:

		inocente.setPosition(350, 295);

		break;

	case 3:

		inocente.setPosition(125, 80);

		break;

	case 4:

		inocente.setPosition(580, 80);

		break;

	}

}


void Inocente::Dibujar(RenderWindow* App) {

	App->draw(inocente);

}


bool Inocente::Encima(float x, float y) {

	FloatRect area = inocente.getGlobalBounds();

	return area.contains(x, y);

}


void Inocente::Derribado() {

	vivo = false;
	visible = false;
}


void Inocente::Invisible() {

	visible = false;

}


void Inocente::Visible() {

	visible = true;

}


void Inocente::Revivir() {

	vivo = true;

}

