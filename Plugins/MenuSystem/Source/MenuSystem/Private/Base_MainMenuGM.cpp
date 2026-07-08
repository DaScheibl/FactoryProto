#include "MainMenuGameModeBase.h"
#include "MainMenuHUDBase.h"

AMainMenuGameModeBase::AMainMenuGameModeBase()
{
	HUDClass = AMainMenuHUDBase::StaticClass();
}