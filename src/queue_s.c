#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_queue_s **) object)

#pragma mark stream_s -

int butterflyfish_queue_s_first(
        const struct butterflyfish_queue_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_s
            .collection_s
            .stream_s
            .first(object, out);
}

int butterflyfish_queue_s_next(
        const struct butterflyfish_queue_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_s
            .collection_s
            .stream_s
            .next(object, item, out);
}

#pragma mark collection_s -

int butterflyfish_queue_s_count(
        const struct butterflyfish_queue_s *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_s
            .collection_s
            .count(object, out);
}

int butterflyfish_queue_s_last(
        const struct butterflyfish_queue_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_s
            .collection_s
            .last(object, out);
}

int butterflyfish_queue_s_prev(
        const struct butterflyfish_queue_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_s
            .collection_s
            .prev(object, item, out);
}

#pragma mark reducible_queue_s -

int butterflyfish_queue_s_remove(
        struct butterflyfish_queue_s *const object,
        struct sea_turtle_string *const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_s
            .remove(object, out);
}

#pragma mark queue_s -

int butterflyfish_queue_s_as_stream(
        const struct butterflyfish_queue_s *const object,
        const struct butterflyfish_stream_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_s *)
            &object->reducible_queue_s.collection_s.stream_s;
    return 0;
}

int butterflyfish_queue_s_as_collection(
        const struct butterflyfish_queue_s *const object,
        const struct butterflyfish_collection_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_s *)
            &object->reducible_queue_s.collection_s;
    return 0;
}

int butterflyfish_queue_s_as_reducible_queue(
        struct butterflyfish_queue_s *const object,
        struct butterflyfish_reducible_queue_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL;
    }
    *out = (struct butterflyfish_reducible_queue_s *)
            &object->reducible_queue_s;
    return 0;
}

int butterflyfish_queue_s_add(
        struct butterflyfish_queue_s *const object,
        const struct sea_turtle_string *const value) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->add(object, value);
}

int butterflyfish_queue_s_add_all(
        struct butterflyfish_queue_s *const object,
        const struct butterflyfish_stream_s *const other) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_QUEUE_S_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}
