#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stream_p_p **) object)

#pragma mark stream_p_p -

int butterflyfish_stream_p_p_first(
        const struct butterflyfish_stream_p_p *const object,
        const struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->first(object, out);
}

int butterflyfish_stream_p_p_next(
        const struct butterflyfish_stream_p_p *const object,
        const struct butterflyfish_map_entry_p_p *const entry,
        const struct butterflyfish_map_entry_p_p **const out) {
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
