#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_reducible_queue_sr **) object)

#pragma mark stream_sr -

int butterflyfish_reducible_queue_sr_first(
        const struct butterflyfish_reducible_queue_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .stream_sr
            .first(object, out);
}

int butterflyfish_reducible_queue_sr_next(
        const struct butterflyfish_reducible_queue_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .stream_sr
            .next(object, item, out);
}

#pragma mark collection_sr -

int butterflyfish_reducible_queue_sr_count(
        const struct butterflyfish_reducible_queue_sr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .count(object, out);
}

int butterflyfish_reducible_queue_sr_last(
        const struct butterflyfish_reducible_queue_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .last(object, out);
}

int butterflyfish_reducible_queue_sr_prev(
        const struct butterflyfish_reducible_queue_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .prev(object, item, out);
}

#pragma mark reducible_queue_sr -

int butterflyfish_reducible_queue_sr_as_stream(
        const struct butterflyfish_reducible_queue_sr *const object,
        const struct butterflyfish_stream_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_sr *)
            &object->collection_sr.stream_sr;
    return 0;
}

int butterflyfish_reducible_queue_sr_as_collection(
        const struct butterflyfish_reducible_queue_sr *const object,
        const struct butterflyfish_collection_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_sr *) &object->collection_sr;
    return 0;
}

int butterflyfish_reducible_queue_sr_remove(
        struct butterflyfish_reducible_queue_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->remove(object, out);
}
