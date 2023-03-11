#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_collection_p **) object)

#pragma mark stream_p -

int butterflyfish_collection_p_first(
        const struct butterflyfish_collection_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_p
            .first(object, out);
}

int butterflyfish_collection_p_next(
        const struct butterflyfish_collection_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_p
            .next(object, item, out);
}

#pragma mark collection_p -

int butterflyfish_collection_p_count(
        const struct butterflyfish_collection_p *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->count(object, out);
}

int butterflyfish_collection_p_last(
        const struct butterflyfish_collection_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->last(object, out);
}

int butterflyfish_collection_p_prev(
        const struct butterflyfish_collection_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->prev(object, item, out);
}

