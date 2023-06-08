#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stack_i **) object)

#pragma mark stream_i -

int butterflyfish_stack_i_first(
        const struct butterflyfish_stack_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_i
            .collection_i
            .stream_i
            .first(object, out);
}

int butterflyfish_stack_i_next(
        const struct butterflyfish_stack_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STACK_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_i
            .collection_i
            .stream_i
            .next(object, item, out);
}

#pragma mark collection_i -

int butterflyfish_stack_i_count(
        const struct butterflyfish_stack_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_i
            .collection_i
            .count(object, out);
}

int butterflyfish_stack_i_last(
        const struct butterflyfish_stack_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_i
            .collection_i
            .last(object, out);
}

int butterflyfish_stack_i_prev(
        const struct butterflyfish_stack_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STACK_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_i
            .collection_i
            .prev(object, item, out);
}

#pragma mark reducible_stack_i -

int butterflyfish_stack_i_pop(
        struct butterflyfish_stack_i *const object,
        struct sea_turtle_integer *const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_i
            .pop(object, out);
}

#pragma mark stack_i -

int butterflyfish_stack_i_push(
        struct butterflyfish_stack_i *const object,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_STACK_I_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->push(object, value);
}

int butterflyfish_stack_i_push_all(
        struct butterflyfish_stack_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_STACK_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->push_all(object, other);
}

