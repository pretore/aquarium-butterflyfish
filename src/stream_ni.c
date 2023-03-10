#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stream_ni **) object)

#pragma mark stream_ni -

int butterflyfish_stream_ni_first(
        const struct butterflyfish_stream_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->first(object, out);
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
    return INVOKABLE->next(object, item, out);
}
