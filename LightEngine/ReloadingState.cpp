#include "ReloadingState.h"


void ReloadingState::Update(float deltaTime) {
    mGun->mReloadProgress -= deltaTime;
    if (mGun->mReloadProgress <= 0.0f) {
        mGun->SetState(Gun::StateLabel::Idle);
        mGun->mAmmo = mGun->mCapacity;
        std::cout << "Ammo : " << mGun->mAmmo << std::endl;
    }
}

void ReloadingState::Start() {
    std::cout << "Gun is in Reloading state" << std::endl;
}