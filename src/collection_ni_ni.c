#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_collection_ni_ni **) object)

#pragma mark stream_ni_ni -

int butterflyfish_collection_ni_ni_first(
        const struct butterflyfish_collection_ni_ni *const object,
        struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_ni_ni
            .first(object, out);
}

int butterflyfish_collection_ni_ni_next(
        const struct butterflyfish_collection_ni_ni *const object,
        const struct butterflyfish_map_entry_ni_ni *const entry,
        struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_ni_ni
            .next(object, entry, out);
}

#pragma mark collection_ni_ni -

int butterflyfish_collection_ni_ni_count(
        const struct butterflyfish_collection_ni_ni *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->count(object, out);
}

int butterflyfish_collection_ni_ni_last(
        const struct butterflyfish_collection_ni_ni *const object,
        struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->last(object, out);
}

int butterflyfish_collection_ni_ni_prev(
        const struct butterflyfish_collection_ni_ni *const object,
        const struct butterflyfish_map_entry_ni_ni *const entry,
        struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->prev(object, entry, out);
}

