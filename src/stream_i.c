#include <stdlib.h>
#include <sea-turtle.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stream_i **) object)

#pragma mark stream_i -

int butterflyfish_stream_i_first(
        const struct butterflyfish_stream_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->first(object, out);
}

int butterflyfish_stream_i_next(
        const struct butterflyfish_stream_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STREAM_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->next(object, item, out);
}
