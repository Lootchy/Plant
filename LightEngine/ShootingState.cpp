#include "ShootingState.h"


void ShootingState::Update(float deltaTime) {
    mGun->mShootProgress -= deltaTime;
    if (mGun->mShootProgress <= 0.0f) {
        mGun->SetState(Gun::StateLabel::Idle);
    }
}

void ShootingState::Start() {
    std::cout << "Gun is in shooting state" << std::endl;
}