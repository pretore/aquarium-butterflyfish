#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stream_i_i **) object)

#pragma mark stream_i_i -

int butterflyfish_stream_i_i_first(
        const struct butterflyfish_stream_i_i *const object,
        struct butterflyfish_map_entry_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->first(object, out);
}

int butterflyfish_stream_i_i_next(
        const struct butterflyfish_stream_i_i *const object,
        const struct butterflyfish_map_entry_i_i *const entry,
        struct butterflyfish_map_entry_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->next(object, entry, out);
}
