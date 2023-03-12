#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stream_sr_sr **) object)

#pragma mark stream_sr_sr -

int butterflyfish_stream_sr_sr_first(
        const struct butterflyfish_stream_sr_sr *const object,
        struct butterflyfish_map_entry_sr_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->first(object, out);
}

int butterflyfish_stream_sr_sr_next(
        const struct butterflyfish_stream_sr_sr *const object,
        const struct butterflyfish_map_entry_sr_sr *const entry,
        struct butterflyfish_map_entry_sr_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_STREAM_SR_SR_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->next(object, entry, out);
}
