#include "ShootEmUp.h"
#include "GeneralMenu.h"

GeneralMenu::GeneralMenu(ShootEmUp* shootEmUpP) : Menu(shootEmUpP){
    //img = SDL_LoadBMP("Images/Menu_puissance4.bmp");
	img = IMG_Load("Images/mainMenu_960x720.jpg");
}
GeneralMenu::~GeneralMenu(){

}

void GeneralMenu::start() {
    image = new Image(shootEmUp->getEngineManager(), img);
    curseur_GM = new CurseurGeneralMenu(shootEmUp->getEngineManager());
}

void GeneralMenu::stop() {
    delete curseur_GM;
    delete image;
} 
