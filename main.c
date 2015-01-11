#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "IGameItem.h"
#include "Circle.h"
#include "Triangle.h"

/** 
 * 1. конструкторы. 
 * Конструктор и деструктор можно попробовать сделать через синглтонный глобальный объект, описывающий класс.
 * Можно будет сделать макрос new с указанием типа создаваемого объекта: new(String, ...).
 * 2. костантые методы в интерфейсах
 * 3. макрос объявления метода в интерфейсе
 * 4. макрос для метода _getInterface
 * 5. Сигнатуру функции в реализации можно объявлять специальным макросом FCIMPL, чтобы встроить счетчик ссылок и проще было бы возвращать результат с несколькими значениями и статусом выполнения функции.
 * 6. Таблицу функций использовать для быстрого конструирования объекта
 * 7. попробовать макрос вызова методов интерфейса, чтобы не нужно было явно передавать ссылку на себя
 * 8. попробовать fplan6, чтоб укоротить вызов this->center.Move(&this->center.IMovable, dx, dy);
 * 9. исследовать насколько безопасно использовать offsetof. нужно ли использовать упаковку структур?
 * 10. посмотреть как работает container_of, может он облегчит макрос PREPARE_THIS
 */

void game_run(size_t len, IGameItem const * const items[], IObject const * const obj) {
    printf("game start\n");

    INTERFACE_VAR(IResizable, obj, res)
    res->Scale(res, 12);

    for (size_t i = 0; i < len; i++) {
        IGameItem const * const item = items[i];

        item->Move(&item->IMovable, i + 10, 10 - i);

        item->Draw(&item->IDrawable);
    }

    printf("game end\n");
}

int main(int argc, char* argv[]) {
    argc--;
    argv++;

    Point p1;
    Point_Init(&p1);

    Circle c1;
    Circle_Init(&c1);
    c1.r = 12;

    Triangle t1;
    Triangle_Init(&t1);

    IGameItem const * const items [] = {
        &c1.IGameItem,
        &p1.IGameItem,
        &t1.IGameItem
    };

    game_run(3, items, &c1.IObject);

    return (EXIT_SUCCESS);
}


