#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_reducible_stack_s **) object)

#pragma mark stream_s -

int butterflyfish_reducible_stack_s_first(
        const struct butterflyfish_reducible_stack_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .stream_s
            .first(object, out);
}

int butterflyfish_reducible_stack_s_next(
        const struct butterflyfish_reducible_stack_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .stream_s
            .next(object, item, out);
}

#pragma mark collection_s -

int butterflyfish_reducible_stack_s_count(
        const struct butterflyfish_reducible_stack_s *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .count(object, out);
}

int butterflyfish_reducible_stack_s_last(
        const struct butterflyfish_reducible_stack_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .last(object, out);
}

int butterflyfish_reducible_stack_s_prev(
        const struct butterflyfish_reducible_stack_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .prev(object, item, out);
}

#pragma mark reducible_stack_s -

int butterflyfish_reducible_stack_s_as_stream(
        const struct butterflyfish_reducible_stack_s *const object,
        const struct butterflyfish_stream_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_s *)
            &object->collection_s.stream_s;
    return 0;
}

int butterflyfish_reducible_stack_s_as_collection(
        const struct butterflyfish_reducible_stack_s *const object,
        const struct butterflyfish_collection_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_s *) &object->collection_s;
    return 0;
}

int butterflyfish_reducible_stack_s_pop(
        struct butterflyfish_reducible_stack_s *const object,
        struct sea_turtle_string *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->pop(object, out);
}

