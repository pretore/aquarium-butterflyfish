#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stack_wr **) object)

#pragma mark stream_wr -

int butterflyfish_stack_wr_first(
        const struct butterflyfish_stack_wr *const object,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_wr
            .collection_wr
            .stream_wr
            .first(object, out);
}

int butterflyfish_stack_wr_next(
        const struct butterflyfish_stack_wr *const object,
        const struct triggerfish_weak *const item,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STACK_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_wr
            .collection_wr
            .stream_wr
            .next(object, item, out);
}

#pragma mark collection_wr -

int butterflyfish_stack_wr_count(
        const struct butterflyfish_stack_wr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_wr
            .collection_wr
            .count(object, out);
}

int butterflyfish_stack_wr_last(
        const struct butterflyfish_stack_wr *const object,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_wr
            .collection_wr
            .last(object, out);
}

int butterflyfish_stack_wr_prev(
        const struct butterflyfish_stack_wr *const object,
        const struct triggerfish_weak *const item,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STACK_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_wr
            .collection_wr
            .prev(object, item, out);
}

#pragma mark reducible_stack_wr -

int butterflyfish_stack_wr_pop(
        struct butterflyfish_stack_wr *const object,
        struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_wr
            .pop(object, out);
}

#pragma mark stack_wr -

int butterflyfish_stack_wr_push(
        struct butterflyfish_stack_wr *const object,
        const struct triggerfish_weak *const value) {
    if (!object) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_STACK_WR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->push(object, value);
}

int butterflyfish_stack_wr_push_all(
        struct butterflyfish_stack_wr *const object,
        const struct butterflyfish_stream_wr *const other) {
    if (!object) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_STACK_WR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->push_all(object, other);
}

