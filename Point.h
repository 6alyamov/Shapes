#ifndef POINT_H
#define	POINT_H

#include "IGameItem.h"
#include "IObject.h"
#include "IObject.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        INTERFACE_DECLARE(IObject)
        INTERFACE_DECLARE(IGameItem)

        double x;
        double y;
    } Point;

    void Point_Init(Point * const);


#ifdef	__cplusplus
}
#endif

#endif	/* POINT_H */

