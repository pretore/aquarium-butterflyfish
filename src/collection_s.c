#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_collection_s **) object)

#pragma mark stream_s -

int butterflyfish_collection_s_first(
        const struct butterflyfish_collection_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_s
            .first(object, out);
}

int butterflyfish_collection_s_next(
        const struct butterflyfish_collection_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_s
            .next(object, item, out);
}

#pragma mark collection_s -

int butterflyfish_collection_s_as_stream(
        const struct butterflyfish_collection_s *const object,
        const struct butterflyfish_stream_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_s *) &object->stream_s;
    return 0;
}

int butterflyfish_collection_s_count(
        const struct butterflyfish_collection_s *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->count(object, out);
}

int butterflyfish_collection_s_last(
        const struct butterflyfish_collection_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->last(object, out);
}

int butterflyfish_collection_s_prev(
        const struct butterflyfish_collection_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->prev(object, item, out);
}

