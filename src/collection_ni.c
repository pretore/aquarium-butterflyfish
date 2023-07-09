#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_collection_ni **) object)

#pragma mark stream_ni -

int butterflyfish_collection_ni_first(
        const struct butterflyfish_collection_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_ni
            .first(object, out);
}

int butterflyfish_collection_ni_next(
        const struct butterflyfish_collection_ni *const object,
        const uintmax_t *const item,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_ni
            .next(object, item, out);
}

#pragma mark collection_ni -

int butterflyfish_collection_ni_as_stream(
        const struct butterflyfish_collection_ni *const object,
        const struct butterflyfish_stream_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_ni *) &object->stream_ni;
    return 0;
}

int butterflyfish_collection_ni_count(
        const struct butterflyfish_collection_ni *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->count(object, out);
}

int butterflyfish_collection_ni_last(
        const struct butterflyfish_collection_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->last(object, out);
}

int butterflyfish_collection_ni_prev(
        const struct butterflyfish_collection_ni *const object,
        const uintmax_t *const item,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->prev(object, item, out);
}

