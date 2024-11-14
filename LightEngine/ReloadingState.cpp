#include "ReloadingState.h"


void ReloadingState::Update(float deltaTime) {
    if (mGun->GetCurrentState() == Gun::StateLabel::Reloading) {
        mGun->mReloadProgress -= deltaTime;
        if (mGun->mReloadProgress <= 0.0f) {
            mGun->SetState(Gun::StateLabel::Idle);
        }
    }
}

void ReloadingState::Start() {
    std::cout << "Gun is in Reloading state" << std::endl;
}