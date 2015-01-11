#include <stdio.h>
#include "Triangle.h"
#include "Point.h"

static void _draw(IDrawable const * const self) {
    PREPARE_THIS(Triangle, IDrawable, self)

    printf("Draw triangle {%g, %g}, {%g, %g}, {%g, %g}\n",
            this->p1.x, this->p1.y,
            this->p2.x, this->p2.y,
            this->p3.x, this->p3.y);
}

static void _move(IMovable const * const self, double dx, double dy) {
    PREPARE_THIS(Triangle, IMovable, self)

    printf("Move triangle {%g, %g}, {%g, %g}, {%g, %g} to {%g, %g}\n",
            this->p1.x, this->p1.y,
            this->p2.x, this->p2.y,
            this->p3.x, this->p3.y,
            dx, dy);

    this->p1.Move(&this->p1.IMovable, dx, dy);
    this->p2.Move(&this->p2.IMovable, dx, dy);
    this->p3.Move(&this->p3.IMovable, dx, dy);

    printf("End move triangle\n");
}

static void const * _getInterface(IObject const * const self, char const * const name) {
    PREPARE_THIS(Triangle, IObject, self)
            
    INTERFACE_PREPARE(Triangle, IGameItem, this, name)
    INTERFACE_PREPARE(Triangle, IMovable, this, name)
    INTERFACE_PREPARE(Triangle, IDrawable, this, name)

    return NULL;
}

void Triangle_Init(Triangle * const self) {
    memset(self, 0, sizeof (Triangle));
    Point_Init(&self->p1);
    Point_Init(&self->p2);
    Point_Init(&self->p3);

    self->GetInterface = _getInterface;
    self->Draw = _draw;
    self->Move = _move;
}
