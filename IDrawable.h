#ifndef IDRAWABLE_H
#define	IDRAWABLE_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct IDrawable {
        void (*Draw)(struct IDrawable const * const);
    } IDrawable;

#ifdef	__cplusplus
}
#endif

#endif	/* IDRAWABLE_H */

