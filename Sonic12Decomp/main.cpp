#include "RetroEngine.hpp"

int alreadyset = 0;

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; ++i) {
        if (StrComp(argv[i], "UsingCWD"))
            usingCWD = true;
    }
#if RETRO_USING_SDL2
    SDL_SetHint(SDL_HINT_WINRT_HANDLE_BACK_BUTTON, "1");
#endif
    if (argc > 1)
    {
		sprintf(Engine.dataFile, "%s", argv[1]);
		alreadyset = 1;
	}
    Engine.Init();
#if RETRO_USING_SDL2
    controllerInit(0);
#endif
    Engine.Run();

    return 0;
}

#if RETRO_PLATFORM == RETRO_UWP
int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int) { return SDL_WinRTRunApp(main, NULL); }
#endif
