#include "GAME/WORLD/World.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	Game* project = new Game;

	project->GameStart();

	delete project;
	return 0;
}