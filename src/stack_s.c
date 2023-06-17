#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stack_s **) object)

#pragma mark stream_s -

int butterflyfish_stack_s_first(
        const struct butterflyfish_stack_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_s
            .collection_s
            .stream_s
            .first(object, out);
}

int butterflyfish_stack_s_next(
        const struct butterflyfish_stack_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STACK_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_s
            .collection_s
            .stream_s
            .next(object, item, out);
}

#pragma mark collection_s -

int butterflyfish_stack_s_count(
        const struct butterflyfish_stack_s *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_s
            .collection_s
            .count(object, out);
}

int butterflyfish_stack_s_last(
        const struct butterflyfish_stack_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_s
            .collection_s
            .last(object, out);
}

int butterflyfish_stack_s_prev(
        const struct butterflyfish_stack_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STACK_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_s
            .collection_s
            .prev(object, item, out);
}

#pragma mark reducible_stack_s -

int butterflyfish_stack_s_pop(
        struct butterflyfish_stack_s *const object,
        struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_s
            .pop(object, out);
}

#pragma mark stack_s -

int butterflyfish_stack_s_push(
        struct butterflyfish_stack_s *const object,
        const struct sea_turtle_string *const value) {
    if (!object) {
        return BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_STACK_S_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->push(object, value);
}

int butterflyfish_stack_s_push_all(
        struct butterflyfish_stack_s *const object,
        const struct butterflyfish_stream_s *const other) {
    if (!object) {
        return BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_STACK_S_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->push_all(object, other);
}
