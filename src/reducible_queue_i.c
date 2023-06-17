#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_reducible_queue_i **) object)

#pragma mark stream_i -

int butterflyfish_reducible_queue_i_first(
        const struct butterflyfish_reducible_queue_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_i
            .stream_i
            .first(object, out);
}

int butterflyfish_reducible_queue_i_next(
        const struct butterflyfish_reducible_queue_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_i
            .stream_i
            .next(object, item, out);
}

#pragma mark collection_i -

int butterflyfish_reducible_queue_i_count(
        const struct butterflyfish_reducible_queue_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_i
            .count(object, out);
}

int butterflyfish_reducible_queue_i_last(
        const struct butterflyfish_reducible_queue_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_i
            .last(object, out);
}

int butterflyfish_reducible_queue_i_prev(
        const struct butterflyfish_reducible_queue_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_i
            .prev(object, item, out);
}

#pragma mark reducible_queue_i -

int butterflyfish_reducible_queue_i_remove(
        struct butterflyfish_reducible_queue_i *const object,
        struct sea_turtle_integer *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->remove(object, out);
}
