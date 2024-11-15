#include "EmptyState.h"


void EmptyState::Update(float deltaTime) {
    mGun->Reload();
}

void EmptyState::Start() {
    std::cout << "Gun is in Empty state" << std::endl;
}