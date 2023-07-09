#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_queue_sr **) object)

#pragma mark stream_sr -

int butterflyfish_queue_sr_first(
        const struct butterflyfish_queue_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_sr
            .collection_sr
            .stream_sr
            .first(object, out);
}

int butterflyfish_queue_sr_next(
        const struct butterflyfish_queue_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_sr
            .collection_sr
            .stream_sr
            .next(object, item, out);
}

#pragma mark collection_sr -

int butterflyfish_queue_sr_count(
        const struct butterflyfish_queue_sr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_sr
            .collection_sr
            .count(object, out);
}

int butterflyfish_queue_sr_last(
        const struct butterflyfish_queue_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_sr
            .collection_sr
            .last(object, out);
}

int butterflyfish_queue_sr_prev(
        const struct butterflyfish_queue_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_sr
            .collection_sr
            .prev(object, item, out);
}

#pragma mark reducible_queue_sr -

int butterflyfish_queue_sr_remove(
        struct butterflyfish_queue_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_sr
            .remove(object, out);
}

#pragma mark queue_sr -

int butterflyfish_queue_sr_as_stream(
        const struct butterflyfish_queue_sr *const object,
        const struct butterflyfish_stream_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_sr *)
            &object->reducible_queue_sr.collection_sr.stream_sr;
    return 0;
}

int butterflyfish_queue_sr_as_collection(
        const struct butterflyfish_queue_sr *const object,
        const struct butterflyfish_collection_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_sr *)
            &object->reducible_queue_sr.collection_sr;
    return 0;
}

int butterflyfish_queue_sr_as_reducible_queue(
        struct butterflyfish_queue_sr *const object,
        struct butterflyfish_reducible_queue_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    *out = (struct butterflyfish_reducible_queue_sr *)
            &object->reducible_queue_sr;
    return 0;
}

int butterflyfish_queue_sr_add(
        struct butterflyfish_queue_sr *const object,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->add(object, value);
}

int butterflyfish_queue_sr_add_all(
        struct butterflyfish_queue_sr *object,
        const struct butterflyfish_stream_sr *other) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_QUEUE_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}
