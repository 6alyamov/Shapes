#include <stdio.h>
#include <string.h>
#include "Circle.h"

static void _draw(IDrawable const * const self) {
    PREPARE_THIS(Circle, IDrawable, self)

    printf("Draw circle {%g, %g, %g}\n", this->center.x, this->center.y, this->r);
}

static void _move(IMovable const * const self, double dx, double dy) {
    PREPARE_THIS(Circle, IMovable, self)

    printf("Move circle {%g, %g, %g} for {%g, %g}\n", this->center.x, this->center.y, this->r, dx, dy);

    this->center.Move(&this->center.IMovable, dx, dy);

    printf("End move circle\n");
}

static void _scale(IResizable const * const self, double scale) {
    PREPARE_THIS(Circle, IResizable, self)

    printf("Scale circle {%g, %g, %g} on %g\n", this->center.x, this->center.y, this->r, scale);

    this->r *= scale;
}

static void const * _getInterface(IObject const * const self, char const * const name) {
    PREPARE_THIS(Circle, IObject, self)
            
    INTERFACE_PREPARE(Circle, IGameItem, this, name)
    INTERFACE_PREPARE(Circle, IMovable, this, name)
    INTERFACE_PREPARE(Circle, IDrawable, this, name)
    INTERFACE_PREPARE(Circle, IResizable, this, name)

    return NULL;
}

void Circle_Init(Circle * const self) {
    memset(self, 0, sizeof (Circle));
    Point_Init(&self->center); // todo: можно забыть инициализировать поля классы

    self->GetInterface = _getInterface;
    self->Draw = _draw;
    self->Move = _move;
    self->Scale = _scale;
}