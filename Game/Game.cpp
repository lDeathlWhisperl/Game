#include <iostream>
#include <Windows.h>

#include "Base.h"
#include "Field.h"

#define UPDATE_FRAME gotoPoint()
#define GAMELOOP while(true)

void fullscreen()
{
    ShowWindow(GetForegroundWindow(), SW_SHOWMAXIMIZED);
}

void Blinking()
{
    void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);
}

int main()
{
    std::cout << "\033]2;Game\007"; // заголовок окна
    //fullscreen(); // тут по желанию
    Blinking(); // здесь каретка становится невидимой, можешь закомментировать и увидеть, на что это влияет

    int length = 25, 
        width = 25;

    /*
        Здесь в качестве третьего параметра установи символ 't' или 'f' или 'd', чтобы выбрать ландшафт
        t - tundra (по-моему получилась лучше всего)
        f - forest
        d - desert
        если без третьего параметра, то будет просто пустая карта (Field field(length, width))
    */
    
    Field field(length, width, 'T');
    Base base(length, width);
    Player player;

    GAMELOOP 
    {   
        field.draw();

        player.draw();
        base.draw();
        base.shop(player);

        player.controller();
        UPDATE_FRAME;
    }
    return 0;
}