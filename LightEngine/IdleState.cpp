#include "IdleState.h"


void IdleState::Update(float deltaTime) {
    if (mGun->GetCurrentState() == Gun::StateLabel::Idle) {
        std::cout << "Idle State..." << std::endl;
    }
}

void IdleState::Start() {
    std::cout << "Gun is in Idle state now" << std::endl;
}