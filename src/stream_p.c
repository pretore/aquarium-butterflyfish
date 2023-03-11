#include <stdlib.h>
#include <sea-turtle.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stream_p **) object)

#pragma mark stream_p -

int butterflyfish_stream_p_first(
        const struct butterflyfish_stream_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->first(object, out);
}

int butterflyfish_stream_p_next(
        const struct butterflyfish_stream_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STREAM_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->next(object, item, out);
}
