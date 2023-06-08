#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_queue_i **) object)

#pragma mark stream_i -

int butterflyfish_queue_i_first(
        const struct butterflyfish_queue_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_i
            .collection_i
            .stream_i
            .first(object, out);
}

int butterflyfish_queue_i_next(
        const struct butterflyfish_queue_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_i
            .collection_i
            .stream_i
            .next(object, item, out);
}

#pragma mark collection_i -

int butterflyfish_queue_i_count(
        const struct butterflyfish_queue_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_i
            .collection_i
            .count(object, out);
}

int butterflyfish_queue_i_last(
        const struct butterflyfish_queue_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_i
            .collection_i
            .last(object, out);
}

int butterflyfish_queue_i_prev(
        const struct butterflyfish_queue_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_i
            .collection_i
            .prev(object, item, out);
}

#pragma mark reducible_queue_i -

int butterflyfish_queue_i_remove(
        struct butterflyfish_queue_i *const object,
        struct sea_turtle_integer *const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_i
            .remove(object, out);
}

#pragma mark queue_i -

int butterflyfish_queue_i_add(
        struct butterflyfish_queue_i *const object,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->add(object, value);
}

int butterflyfish_queue_i_add_all(
        struct butterflyfish_queue_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}
