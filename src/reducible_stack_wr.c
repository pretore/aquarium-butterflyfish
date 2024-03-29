#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_reducible_stack_wr **) object)

#pragma mark stream_wr -

int butterflyfish_reducible_stack_wr_first(
        const struct butterflyfish_reducible_stack_wr *const object,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .stream_wr
            .first(object, out);
}

int butterflyfish_reducible_stack_wr_next(
        const struct butterflyfish_reducible_stack_wr *const object,
        const struct triggerfish_weak *const item,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .stream_wr
            .next(object, item, out);
}

#pragma mark collection_wr -

int butterflyfish_reducible_stack_wr_as_stream(
        const struct butterflyfish_reducible_stack_wr *const object,
        const struct butterflyfish_stream_wr **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_wr *)
            &object->collection_wr.stream_wr;
    return 0;
}

int butterflyfish_reducible_stack_wr_as_collection(
        const struct butterflyfish_reducible_stack_wr *const object,
        const struct butterflyfish_collection_wr **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_wr *) &object->collection_wr;
    return 0;
}

int butterflyfish_reducible_stack_wr_count(
        const struct butterflyfish_reducible_stack_wr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .count(object, out);
}

int butterflyfish_reducible_stack_wr_last(
        const struct butterflyfish_reducible_stack_wr *const object,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .last(object, out);
}

int butterflyfish_reducible_stack_wr_prev(
        const struct butterflyfish_reducible_stack_wr *const object,
        const struct triggerfish_weak *const item,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .prev(object, item, out);
}

#pragma mark reducible_stack_wr -

int butterflyfish_reducible_stack_wr_pop(
        struct butterflyfish_reducible_stack_wr *const object,
        struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->pop(object, out);
}

