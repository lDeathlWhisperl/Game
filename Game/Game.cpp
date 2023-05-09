#include <iostream>
#include <Windows.h>

#include "Base.h"
#include "Field.h"

#define UPDATE_FRAME gotoPoint()
#define GAMELOOP while(true)

// \033[#A передвинуть курсор вверх на # строк
// \033[#B передвинуть курсор вниз на # строк
// \033[#С передвинуть курсор вправо на # столбцов
// \033[#D передвинуть курсор влево на # столбцов
// \033[#E передвинуть курсор вниз на # строк и поставить в начало строки
// \033[#F передвинуть курсор вверх на # строк и поставить в начало строки
// \033[#G переместить курсор в указанный столбец текущей строки
// \033[#;#H задает абсолютные координаты курсора (строка, столбец)
// \033]2;BLA_BLA\007 Заголовок окна xterm...
// \x1b[34m

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

    Field field(length, width);
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