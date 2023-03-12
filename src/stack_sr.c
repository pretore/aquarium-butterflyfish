#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stack_sr **) object)

#pragma mark stream_sr -

int butterflyfish_stack_sr_first(
        const struct butterflyfish_stack_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .stream_sr
            .first(object, out);
}

int butterflyfish_stack_sr_next(
        const struct butterflyfish_stack_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STACK_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .stream_sr
            .next(object, item, out);
}

#pragma mark collection_sr -

int butterflyfish_stack_sr_count(
        const struct butterflyfish_stack_sr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .count(object, out);
}

int butterflyfish_stack_sr_last(
        const struct butterflyfish_stack_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .last(object, out);
}

int butterflyfish_stack_sr_prev(
        const struct butterflyfish_stack_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STACK_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .prev(object, item, out);
}

#pragma mark stack_sr -

int butterflyfish_stack_sr_push(
        struct butterflyfish_stack_sr *const object,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_STACK_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->push(object, value);
}

int butterflyfish_stack_sr_pop(
        struct butterflyfish_stack_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->pop(object, out);
}

