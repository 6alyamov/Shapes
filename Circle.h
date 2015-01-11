#ifndef CIRCLE_H
#define	CIRCLE_H

#include "Point.h"
#include "IResizable.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        INTERFACE_DECLARE(IResizable)
        INTERFACE_DECLARE(IObject)
        INTERFACE_DECLARE(IGameItem)

        Point center;
        double r;
    } Circle;

    void Circle_Init(Circle * const);

#ifdef	__cplusplus
}
#endif

#endif	/* CIRCLE_H */

