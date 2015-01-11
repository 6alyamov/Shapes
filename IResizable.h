#ifndef IRESIZABLE_H
#define	IRESIZABLE_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct IResizable {
        void (*Scale)(struct IResizable const * const, double);
    } IResizable;

#ifdef	__cplusplus
}
#endif

#endif	/* IRESIZABLE_H */

