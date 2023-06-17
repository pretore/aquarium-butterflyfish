#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_reducible_queue_s **) object)

#pragma mark stream_s -

int butterflyfish_reducible_queue_s_first(
        const struct butterflyfish_reducible_queue_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .stream_s
            .first(object, out);
}

int butterflyfish_reducible_queue_s_next(
        const struct butterflyfish_reducible_queue_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .stream_s
            .next(object, item, out);
}

#pragma mark collection_s -

int butterflyfish_reducible_queue_s_count(
        const struct butterflyfish_reducible_queue_s *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .count(object, out);
}

int butterflyfish_reducible_queue_s_last(
        const struct butterflyfish_reducible_queue_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .last(object, out);
}

int butterflyfish_reducible_queue_s_prev(
        const struct butterflyfish_reducible_queue_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .prev(object, item, out);
}

#pragma mark reducible_queue_s -

int butterflyfish_reducible_queue_s_remove(
        struct butterflyfish_reducible_queue_s *const object,
        struct sea_turtle_string *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->remove(object, out);
}
