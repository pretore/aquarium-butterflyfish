#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_collection_s_s **) object)

#pragma mark stream_s_s -

int butterflyfish_collection_s_s_first(
        const struct butterflyfish_collection_s_s *const object,
        const struct butterflyfish_map_entry_s_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_s_s
            .first(object, out);
}

int butterflyfish_collection_s_s_next(
        const struct butterflyfish_collection_s_s *const object,
        const struct butterflyfish_map_entry_s_s *const entry,
        const struct butterflyfish_map_entry_s_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->stream_s_s
            .next(object, entry, out);
}

#pragma mark collection_s_s -

int butterflyfish_collection_s_s_as_stream(
        const struct butterflyfish_collection_s_s *const object,
        const struct butterflyfish_stream_s_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_s_s *) &object->stream_s_s;
    return 0;
}

int butterflyfish_collection_s_s_count(
        const struct butterflyfish_collection_s_s *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->count(object, out);
}

int butterflyfish_collection_s_s_last(
        const struct butterflyfish_collection_s_s *const object,
        const struct butterflyfish_map_entry_s_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->last(object, out);
}

int butterflyfish_collection_s_s_prev(
        const struct butterflyfish_collection_s_s *const object,
        const struct butterflyfish_map_entry_s_s *const entry,
        const struct butterflyfish_map_entry_s_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->prev(object, entry, out);
}

