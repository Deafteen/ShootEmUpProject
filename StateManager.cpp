#include "StateManager.h"
#include "GeneralMenu.h"

StateManager::StateManager(void)
{
}

StateManager::StateManager(ShootEmUp* shootEmUpP){
	shootEmUp = shootEmUpP;
	currentType = StateType::NONE;
	nextType = StateType::GENERAL_MENU;
	states.insert(std::pair<StateType, State*>(GENERAL_MENU, new GeneralMenu(shootEmUp)));
}

StateManager::~StateManager(void)
{
}

void StateManager::start() {
    if(nextType != currentType) {
        std::map<StateType, State*>::iterator it = states.find(currentType);
        if (it != states.end()) { // si on a pas trouver currentType
            State* state = it->second;
            state->stop();
        } 
        currentType = nextType;
        std::map<StateType, State*>::iterator it2 = states.find(currentType);
        if (it2 != states.end()) { 
            State* state = it2->second;
            state->start();
        }        
    }
}

ShootEmUp* StateManager::getShootEmUp() {
    return shootEmUp;
}

void StateManager::setNxtMenu(StateType menu){
	nextType = menu;
}