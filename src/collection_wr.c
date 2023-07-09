#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_collection_wr **) object)

#pragma mark stream_wr -

int butterflyfish_collection_wr_first(
        const struct butterflyfish_collection_wr *const object,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_wr
            .first(object, out);
}

int butterflyfish_collection_wr_next(
        const struct butterflyfish_collection_wr *const object,
        const struct triggerfish_weak *const item,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_wr
            .next(object, item, out);
}

#pragma mark collection_wr -

int butterflyfish_collection_wr_as_stream(
        const struct butterflyfish_collection_wr *const object,
        const struct butterflyfish_stream_wr **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_wr *) &object->stream_wr;
    return 0;
}

int butterflyfish_collection_wr_count(
        const struct butterflyfish_collection_wr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->count(object, out);
}

int butterflyfish_collection_wr_last(
        const struct butterflyfish_collection_wr *const object,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->last(object, out);
}

int butterflyfish_collection_wr_prev(
        const struct butterflyfish_collection_wr *const object,
        const struct triggerfish_weak *const item,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->prev(object, item, out);
}

