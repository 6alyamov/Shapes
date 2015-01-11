#ifndef IGAMEITEM_H
#define	IGAMEITEM_H

#include "IObject.h"
#include "IDrawable.h"
#include "IMovable.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        INTERFACE_DECLARE(IMovable)
        INTERFACE_DECLARE(IDrawable)
    } IGameItem;

#ifdef	__cplusplus
}
#endif

#endif	/* IGAMEITEM_H */
