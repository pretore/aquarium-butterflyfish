#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_collection_i_i **) object)

#pragma mark stream_i_i -

int butterflyfish_collection_i_i_first(
        const struct butterflyfish_collection_i_i *const object,
        const struct butterflyfish_map_entry_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_i_i
            .first(object, out);
}

int butterflyfish_collection_i_i_next(
        const struct butterflyfish_collection_i_i *const object,
        const struct butterflyfish_map_entry_i_i *const entry,
        const struct butterflyfish_map_entry_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_i_i
            .next(object, entry, out);
}

#pragma mark collection_i_i -

int butterflyfish_collection_i_i_count(
        const struct butterflyfish_collection_i_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->count(object, out);
}

int butterflyfish_collection_i_i_last(
        const struct butterflyfish_collection_i_i *const object,
        const struct butterflyfish_map_entry_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->last(object, out);
}

int butterflyfish_collection_i_i_prev(
        const struct butterflyfish_collection_i_i *const object,
        const struct butterflyfish_map_entry_i_i *const entry,
        const struct butterflyfish_map_entry_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->prev(object, entry, out);
}

