#include <stdlib.h>
#include <sea-turtle.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x)   (*(struct butterflyfish_stream_i_i **) x)

#pragma mark stream_i_i -

int butterflyfish_stream_i_i_first(
        const struct butterflyfish_stream_i_i *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->first(object, out);
}

int butterflyfish_stream_i_i_next(
        const struct butterflyfish_stream_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->next(object, item, out);
}

