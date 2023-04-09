#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stream_s_s **) object)

#pragma mark stream_s_s -

int butterflyfish_stream_s_s_first(
        const struct butterflyfish_stream_s_s *const object,
        const struct butterflyfish_map_entry_s_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->first(object, out);
}

int butterflyfish_stream_s_s_next(
        const struct butterflyfish_stream_s_s *const object,
        const struct butterflyfish_map_entry_s_s *const entry,
        const struct butterflyfish_map_entry_s_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_STREAM_S_S_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->next(object, entry, out);
}
