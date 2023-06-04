#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stack_ni **) object)

#pragma mark stream_ni -

int butterflyfish_stack_ni_first(
        const struct butterflyfish_stack_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_ni
            .collection_ni
            .stream_ni
            .first(object, out);
}

int butterflyfish_stack_ni_next(
        const struct butterflyfish_stack_ni *const object,
        const uintmax_t *const item,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STACK_NI_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_ni
            .collection_ni
            .stream_ni
            .next(object, item, out);
}

#pragma mark collection_ni -

int butterflyfish_stack_ni_count(
        const struct butterflyfish_stack_ni *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_ni
            .collection_ni
            .count(object, out);
}

int butterflyfish_stack_ni_last(
        const struct butterflyfish_stack_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_ni
            .collection_ni
            .last(object, out);
}

int butterflyfish_stack_ni_prev(
        const struct butterflyfish_stack_ni *const object,
        const uintmax_t *const item,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STACK_NI_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_ni
            .collection_ni
            .prev(object, item, out);
}

#pragma mark reducible_stack_ni -

int butterflyfish_stack_ni_pop(
        struct butterflyfish_stack_ni *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_ni
            .pop(object, out);
}

#pragma mark stack_ni -

int butterflyfish_stack_ni_push(
        struct butterflyfish_stack_ni *const object,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->push(object, value);
}

int butterflyfish_stack_ni_push_all(
        struct butterflyfish_stack_ni *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_STACK_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->push_all(object, other);
}

