#include <stdlib.h>
#include <sea-turtle.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x)   (*(struct butterflyfish_stream_ni **) x)

#pragma mark stream_i -

int butterflyfish_stream_ni_first(
        const struct butterflyfish_stream_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->first(object, out);
}

int butterflyfish_stream_ni_next(
        const struct butterflyfish_stream_ni *const object,
        const uintmax_t *const item,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STREAM_NI_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->next(object, item, out);
}
