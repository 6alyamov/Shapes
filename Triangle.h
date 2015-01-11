#ifndef TRIANGLE_H
#define	TRIANGLE_H

#include "Point.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        INTERFACE_DECLARE(IGameItem)
        INTERFACE_DECLARE(IObject)

        Point p1;
        Point p2;
        Point p3;
    } Triangle;

    void Triangle_Init(Triangle * const);

#ifdef	__cplusplus
}
#endif

#endif	/* TRIANGLE_H */

