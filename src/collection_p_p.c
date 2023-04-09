#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_collection_p_p **) object)

#pragma mark stream_p_p -

int butterflyfish_collection_p_p_first(
        const struct butterflyfish_collection_p_p *const object,
        const struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_p_p
            .first(object, out);
}

int butterflyfish_collection_p_p_next(
        const struct butterflyfish_collection_p_p *const object,
        const struct butterflyfish_map_entry_p_p *const entry,
        const struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_COLLECTION_P_P_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_p_p
            .next(object, entry, out);
}

#pragma mark collection_p_p -

int butterflyfish_collection_p_p_count(
        const struct butterflyfish_collection_p_p *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->count(object, out);
}

int butterflyfish_collection_p_p_last(
        const struct butterflyfish_collection_p_p *const object,
        const struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->last(object, out);
}

int butterflyfish_collection_p_p_prev(
        const struct butterflyfish_collection_p_p *const object,
        const struct butterflyfish_map_entry_p_p *const entry,
        const struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_COLLECTION_P_P_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->prev(object, entry, out);
}

