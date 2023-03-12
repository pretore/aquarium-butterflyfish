#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_collection_sr **) object)

#pragma mark stream_sr -

int butterflyfish_collection_sr_first(
        const struct butterflyfish_collection_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_sr
            .first(object, out);
}

int butterflyfish_collection_sr_next(
        const struct butterflyfish_collection_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_sr
            .next(object, item, out);
}

#pragma mark collection_sr -

int butterflyfish_collection_sr_count(
        const struct butterflyfish_collection_sr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->count(object, out);
}

int butterflyfish_collection_sr_last(
        const struct butterflyfish_collection_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->last(object, out);
}

int butterflyfish_collection_sr_prev(
        const struct butterflyfish_collection_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->prev(object, item, out);
}

