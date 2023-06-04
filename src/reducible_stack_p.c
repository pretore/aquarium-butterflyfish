#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_reducible_stack_p **) object)

#pragma mark stream_p -

int butterflyfish_reducible_stack_p_first(
        const struct butterflyfish_reducible_stack_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .stream_p
            .first(object, out);
}

int butterflyfish_reducible_stack_p_next(
        const struct butterflyfish_reducible_stack_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .stream_p
            .next(object, item, out);
}

#pragma mark collection_p -

int butterflyfish_reducible_stack_p_count(
        const struct butterflyfish_reducible_stack_p *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .count(object, out);
}

int butterflyfish_reducible_stack_p_last(
        const struct butterflyfish_reducible_stack_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .last(object, out);
}

int butterflyfish_reducible_stack_p_prev(
        const struct butterflyfish_reducible_stack_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .prev(object, item, out);
}

#pragma mark reducible_stack_p -

int butterflyfish_reducible_stack_p_pop(
        struct butterflyfish_reducible_stack_p *const object,
        void **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_STACK_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->pop(object, out);
}

