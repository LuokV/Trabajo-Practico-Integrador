#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Vaquero.h";


Enemigo::Enemigo() {


	enemy_texture.loadFromFile("Pistolero.png");
	pistolero.setTexture(enemy_texture);
	pistolero.setScale(1.2f, 1.2f);
	
	bang_texture.loadFromFile("BANG.png");
	bang.setTexture(bang_texture);
	bang.setScale(0.15f,0.15f);

	vivo = true;
	visible = false;

}



bool Enemigo::EnPantalla() {

	return vivo && visible;

}


void Enemigo::PosicionAzar() {

	srand(time(NULL));
	int azar = rand() % 5;

	switch (azar)
	{
	case 0:

		pistolero.setPosition(75, 260);
		bang.setPosition(55, 290);

		break;

	case 1:

		pistolero.setPosition(585, 260);
		bang.setPosition(565, 290);

		break;


	case 2:

		pistolero.setPosition(335, 285);
		bang.setPosition(305, 315);

		break;

	case 3:

		pistolero.setPosition(110,65);
		bang.setPosition(90, 95);

		break;

	case 4:

		pistolero.setPosition(565, 65);
		bang.setPosition(545, 95);

		break;

	}

}


void Enemigo::Dibujar(RenderWindow* App) {

	App->draw(pistolero);

}


bool Enemigo::Encima(float x, float y) {

	FloatRect area = pistolero.getGlobalBounds();

	return area.contains(x, y);

}


void Enemigo::Derrotar() {

	vivo = false;
	visible = false;
}

void Enemigo::Invisible() {

	visible=false;

}

void Enemigo::Visible() {

	visible= true;

}

void Enemigo::Revivir() {

	vivo = true;

}


void Enemigo::Disparo_Bang(RenderWindow* App) {
		
			App->draw(bang);				
	
}
