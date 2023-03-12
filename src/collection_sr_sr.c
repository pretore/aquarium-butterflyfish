#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_collection_sr_sr **) object)

#pragma mark stream_sr_sr -

int butterflyfish_collection_sr_sr_first(
        const struct butterflyfish_collection_sr_sr *const object,
        struct butterflyfish_map_entry_sr_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_sr_sr
            .first(object, out);
}

int butterflyfish_collection_sr_sr_next(
        const struct butterflyfish_collection_sr_sr *const object,
        const struct butterflyfish_map_entry_sr_sr *const entry,
        struct butterflyfish_map_entry_sr_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_sr_sr
            .next(object, entry, out);
}

#pragma mark collection_sr_sr -

int butterflyfish_collection_sr_sr_count(
        const struct butterflyfish_collection_sr_sr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->count(object, out);
}

int butterflyfish_collection_sr_sr_last(
        const struct butterflyfish_collection_sr_sr *const object,
        struct butterflyfish_map_entry_sr_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->last(object, out);
}

int butterflyfish_collection_sr_sr_prev(
        const struct butterflyfish_collection_sr_sr *const object,
        const struct butterflyfish_map_entry_sr_sr *const entry,
        struct butterflyfish_map_entry_sr_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->prev(object, entry, out);
}

