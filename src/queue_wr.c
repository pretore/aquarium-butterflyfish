#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_queue_wr **) object)

#pragma mark stream_wr -

int butterflyfish_queue_wr_first(
        const struct butterflyfish_queue_wr *const object,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .stream_wr
            .first(object, out);
}

int butterflyfish_queue_wr_next(
        const struct butterflyfish_queue_wr *const object,
        const struct triggerfish_weak *const item,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .stream_wr
            .next(object, item, out);
}

#pragma mark collection_wr -

int butterflyfish_queue_wr_count(
        const struct butterflyfish_queue_wr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .count(object, out);
}

int butterflyfish_queue_wr_last(
        const struct butterflyfish_queue_wr *const object,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .last(object, out);
}

int butterflyfish_queue_wr_prev(
        const struct butterflyfish_queue_wr *const object,
        const struct triggerfish_weak *const item,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .prev(object, item, out);
}

#pragma mark queue_wr -

int butterflyfish_queue_wr_add(
        struct butterflyfish_queue_wr *const object,
        const struct triggerfish_weak *const value) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->add(object, value);
}

int butterflyfish_queue_wr_remove(
        struct butterflyfish_queue_wr *const object,
        struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->remove(object, out);
}
