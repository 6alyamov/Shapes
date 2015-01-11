#ifndef IMOVABLE_H
#define	IMOVABLE_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct IMovable{
        void (*Move)(struct IMovable const * const, double, double);
    } IMovable;

#ifdef	__cplusplus
}
#endif

#endif	/* IMOVABLE_H */