#include "EmptyState.h"


void EmptyState::Update(float deltaTime) {
    mGun->Reload();
}

void EmptyState::Start() {
    //rien
}