#include <chrono>
#include <Windows.h>
#include "gun.h"
#include "ShootingState.h"
#include "ReloadingState.h"
#include "EmptyState.h"
#include "IdleState.h"

Gun::Gun(int capacity, float reloadTime, float shootTime)
	: mCapacity(capacity), mReloadTime(reloadTime), mShootTime(shootTime) {
	mAmmo = mCapacity;
	mShootProgress = 0;
	mReloadProgress = 0;

	// Initialisation des objets d’état dans le tableau
	mStates[(int)StateLabel::Shooting] = new ShootingState(this);
	mStates[(int)StateLabel::Reloading] = new ReloadingState(this);
	mStates[(int)StateLabel::Empty] = new EmptyState(this);
	mStates[(int)StateLabel::Idle] = new IdleState(this);

	// Initialisation de l’état actuel
	mStateLabel = StateLabel::Idle;
	mCurrentState = mStates[(int)StateLabel::Idle];
	mCurrentState->Start();
	std::cout << "Gun Create" << std::endl;
}

Gun::~Gun() {
	// Libération des objets d'état
	for (int i = 0; i < STATE_COUNT; ++i) {
		delete mStates[i];
	}
}

bool Gun::SetState(StateLabel to) {
	if (mTransition[(int)mStateLabel][(int)to] == 0) {
		return false;
	}
	mStateLabel = to;
	mCurrentState = mStates[(int)mStateLabel];
	mCurrentState->Start();
	return true;
}

void Gun::Shoot() {
	if (SetState(StateLabel::Shooting)) {
		mShootProgress = mShootTime;
		std::cout << "Bam" << std::endl;
		mAmmo -= 1;
	}
}

void Gun::Reload() {
	if (SetState(StateLabel::Reloading)) {
		std::cout << "Reloading..." << std::endl;
		mAmmo = mCapacity;
		mReloadProgress = mReloadTime;
		std::cout << "Ammo left : " << mAmmo << std::endl;
	}
}

void Gun::Update(float deltaTime) {
	if (mCurrentState) {
		mCurrentState->Update(deltaTime);
	}
}

Gun::StateLabel Gun::GetCurrentState() {
	return mStateLabel;
}

void Gun::TransitionTo(StateLabel newstate) {
	if (SetState(newstate)) {
		switch (newstate) {
		case StateLabel::Idle:
			std::cout << "Transitioned to Idle state." << std::endl;
			break;
		case StateLabel::Shooting:
			std::cout << "Transitioned to Shooting state." << std::endl;
			break;
		case StateLabel::Reloading:
			std::cout << "Transitioned to Reloading state." << std::endl;
			break;
		case StateLabel::Empty:
			std::cout << "Transitioned to Empty state." << std::endl;
			break;
		}
	}
}
