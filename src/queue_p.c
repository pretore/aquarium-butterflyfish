#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_queue_p **) object)

#pragma mark stream_p -

int butterflyfish_queue_p_first(
        const struct butterflyfish_queue_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_p
            .collection_p
            .stream_p
            .first(object, out);
}

int butterflyfish_queue_p_next(
        const struct butterflyfish_queue_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_p
            .collection_p
            .stream_p
            .next(object, item, out);
}

#pragma mark collection_p -

int butterflyfish_queue_p_count(
        const struct butterflyfish_queue_p *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_p
            .collection_p
            .count(object, out);
}

int butterflyfish_queue_p_last(
        const struct butterflyfish_queue_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_p
            .collection_p
            .last(object, out);
}

int butterflyfish_queue_p_prev(
        const struct butterflyfish_queue_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_p
            .collection_p
            .prev(object, item, out);
}

#pragma mark reducible_queue_p -

int butterflyfish_queue_p_remove(
        struct butterflyfish_queue_p *const object,
        void **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_p
            .remove(object, out);
}

#pragma mark queue_p -

int butterflyfish_queue_p_add(
        struct butterflyfish_queue_p *const object,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->add(object, value);
}

int butterflyfish_queue_p_add_all(
        struct butterflyfish_queue_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_QUEUE_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}
