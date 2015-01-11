#ifndef IObject_H
#define	IObject_H

#include <string.h>
#include <stddef.h>

#ifdef	__cplusplus
extern "C" {
#endif

    /**
     * Базовый класс всех объектов
     */
    typedef struct IObject {
        // Позволяет получить ссылку на реализацию интерфеса по его имени.
        // Возвращает NULL, если интерфейс не поддерживается.
        void const * (*GetInterface)(struct IObject const * const, char const * const);
    } IObject;

#define INTERFACE_VAR(InterfaceType, ptInterface, variable) \
    InterfaceType const * const variable = (ptInterface)->GetInterface((ptInterface), #InterfaceType);

#define INTERFACE_PREPARE(Type, InterfaceType, ptObject, name) \
    if (strcmp((name), #InterfaceType) == 0) { \
        return (void const *)((size_t)(ptObject) + offsetof(Type, InterfaceType)); \
    }

#define INTERFACE_DECLARE(InterfaceType) \
    union { \
        InterfaceType; \
        InterfaceType const InterfaceType; \
    };

#define PREPARE_THIS(Type, InterfaceType, ptInterface) \
    Type * const this = (Type *)((size_t)(ptInterface) - offsetof(Type, InterfaceType));

#ifdef	__cplusplus
}
#endif

#endif	/* IObject_H */

