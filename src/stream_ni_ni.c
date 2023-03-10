#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stream_ni_ni **) object)

#pragma mark stream_ni_ni -

int butterflyfish_stream_ni_ni_first(
        const struct butterflyfish_stream_ni_ni *const object,
        struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->first(object, out);
}

int butterflyfish_stream_ni_ni_next(
        const struct butterflyfish_stream_ni_ni *const object,
        const struct butterflyfish_map_entry_ni_ni *const entry,
        struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_STREAM_NI_NI_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->next(object, entry, out);
}
