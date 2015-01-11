#include <stdio.h>
#include <string.h>
#include "Point.h"

static void _draw(IDrawable const * const self) {
    PREPARE_THIS(Point, IDrawable, self)

    printf("Draw point {%g, %g}\n", this->x, this->y);
}

static void _move(IMovable const * const self, double dx, double dy) {
    PREPARE_THIS(Point, IMovable, self)

    printf("Move point {%g, %g} for {%g, %g}\n", this->x, this->y, dx, dy);

    this->x += dx;
    this->y += dy;
}

static void const * _getInterface(IObject const * const self, char const * const name) {
    PREPARE_THIS(Point, IObject, self)
            
    INTERFACE_PREPARE(Point, IGameItem, this, name)
    INTERFACE_PREPARE(Point, IMovable, this, name)
    INTERFACE_PREPARE(Point, IDrawable, this, name)

    return NULL;
}

void Point_Init(Point * const self) {
    memset(self, 0, sizeof(Point));
 
    self->GetInterface = _getInterface;
    self->Draw = _draw;
    self->Move = _move;
}
